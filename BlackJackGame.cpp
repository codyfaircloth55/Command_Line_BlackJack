/* BlackJackGame.cpp : This file contains the 'main' function.Program execution begins and ends there. 
   Author: Cody Faircloth 
   Date: 03/13/2024
*/

#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include "card.h"
#include <math.h>

using namespace std;

/*Global Card Objects:
Each card contains the following:
-int Value
-string Name
-string Suit
-bool Active (set to true by constructor)
--See card.cpp and card.h for more information*/
Card aceS = Card(11, "Ace", "Spades");
Card aceC = Card(11, "Ace", "Clubs");
Card aceH = Card(11, "Ace", "Hearts");
Card aceD = Card(11, "Ace", "Diamonds");
Card kingS = Card(10, "King", "Spades");
Card kingC = Card(10, "King", "Clubs");
Card kingH = Card(10, "King", "Hearts");
Card kingD = Card(10, "King", "Diamonds");
Card queenS = Card(10, "Queen", "Spades");
Card queenC = Card(10, "Queen", "Clubs");
Card queenH = Card(10, "Queen", "Hearts");
Card queenD = Card(10, "Queen", "Diamonds");
Card jackS = Card(10, "Jack", "Spades");
Card jackC = Card(10, "Jack", "Clubs");
Card jackH = Card(10, "Jack", "Hearts");
Card jackD = Card(10, "Jack", "Diamonds");
Card tenS = Card(10, "Ten", "Spades");
Card tenC = Card(10, "Ten", "Clubs");
Card tenH = Card(10, "Ten", "Hearts");
Card tenD = Card(10, "Ten", "Diamonds");
Card nineS = Card(9, "Nine", "Spades");
Card nineC = Card(9, "Nine", "Clubs");
Card nineH = Card(9, "Nine", "Hearts");
Card nineD = Card(9, "Nine", "Diamonds");
Card eightS = Card(8, "Eight", "Spades");
Card eightC = Card(8, "Eight", "Clubs");
Card eightH = Card(8, "Eight", "Hearts");
Card eightD = Card(8, "Eight", "Diamonds");
Card sevenS = Card(7, "Seven", "Spades");
Card sevenC = Card(7, "Seven", "Clubs");
Card sevenH = Card(7, "Seven", "Hearts");
Card sevenD = Card(7, "Seven", "Diamonds");
Card sixS = Card(6, "Six", "Spades");
Card sixC = Card(6, "Six", "Clubs");
Card sixH = Card(6, "Six", "Hearts");
Card sixD = Card(6, "Six", "Diamonds");
Card fiveS = Card(5, "Five", "Spades");
Card fiveC = Card(5, "Five", "Clubs");
Card fiveH = Card(5, "Five", "Hearts");
Card fiveD = Card(5, "Five", "Diamonds");
Card fourS = Card(4, "Four", "Spades");
Card fourC = Card(4, "Four", "Clubs");
Card fourH = Card(4, "Four", "Hearts");
Card fourD = Card(4, "Four", "Diamonds");
Card threeS = Card(3, "Three", "Spades");
Card threeC = Card(3, "Three", "Clubs");
Card threeH = Card(3, "Three", "Hearts");
Card threeD = Card(3, "Three", "Diamonds");
Card twoS = Card(2, "Two", "Spades");
Card twoC = Card(2, "Two", "Clubs");
Card twoH = Card(2, "Two", "Hearts");
Card twoD = Card(2, "Two", "Diamonds");

/*Global vector to hold each created Card object creating a deck
-Modifications to individual cards and whole deck is performed by game functions
--See game functions section for more information*/
vector<Card> deck = { aceS, aceC, aceH, aceD, kingS, kingC, kingH, kingD, queenS, queenC, queenH, queenD, jackS, jackC, jackH, jackD,
                tenS, tenC, tenH, tenD, nineS, nineC, nineH, nineD, eightS, eightC, eightH, eightD, sevenS, sevenC, sevenH, sevenD,
                sixS, sixC, sixH, sixD, fiveS, fiveC, fiveH, fiveD, fourS, fourC, fourH, fourD, threeS, threeC, threeH, threeD,
                twoS, twoC, twoH, twoD };

/*Global string vectors to hold variations of phrases
-Used to validate input for various game functions
--See game functions section for implementation information*/
vector<string> yesVariations = { "YES", "Yes", "yes", "Y", "y" };
vector<string> noVariations = { "NO", "No", "no", "N", "n" };
vector<string> hitVariations = { "HIT", "Hit", "hit", "H", "h" };
vector<string> standVariations = { "STAND", "Stand", "stand", "S", "s"};
vector<string> doubleDVariations = { "DOUBLE DOWN", "Double Down", "Double down", "double Down", "double down", "DOUBLE", "Double", "double", "D", "d" };

/*Global integer variables for commonly modified variables
-Used in functions to modify respective variable while returning a different type
--See game functions section for implementation information*/
int userBalance = 200;
int wager1 = 0;
int wager2 = 0;
int cardsDealt = 0;

/*=====================================
=== Test Functions: ===================
=====================================*/

/*Function to test the size of the deck
-Used to find discrepencies when Card objects were created*/
void testDeckSize() {
    cout << "Deck Size Test:" << endl;
    cout << deck.size() << " Cards" << endl;
    if (deck.size() == 52) {
        cout << "Test Passed." << endl;
    }
    else {
        cout << "Test Failed." << endl;
    }
    cout << endl;
}

/*Function to test the name of each card in deck
-Used to find discrepencies when Card objects were created*/
void testCardName() {
    int numCorrect = 0;

    cout << "Card Name Test:" << endl;
    for (int i = 0; i < deck.size(); i++) {
        if (i <= 3 && deck[i].getName() == "Ace") {
            numCorrect++;
        }
        else if (i <= 7 && deck[i].getName() == "King") {
            numCorrect++;
        }
        else if (i <= 11 && deck[i].getName() == "Queen") {
            numCorrect++;
        }
        else if (i <= 15 && deck[i].getName() == "Jack") {
            numCorrect++;
        }
        else if (i <= 19 && deck[i].getName() == "Ten") {
            numCorrect++;
        }
        else if (i <= 23 && deck[i].getName() == "Nine") {
            numCorrect++;
        }
        else if (i <= 27 && deck[i].getName() == "Eight") {
            numCorrect++;
        }
        else if (i <= 31 && deck[i].getName() == "Seven") {
            numCorrect++;
        }
        else if (i <= 35 && deck[i].getName() == "Six") {
            numCorrect++;
        }
        else if (i <= 39 && deck[i].getName() == "Five") {
            numCorrect++;
        }
        else if (i <= 43 && deck[i].getName() == "Four") {
            numCorrect++;
        }
        else if (i <= 47 && deck[i].getName() == "Three") {
            numCorrect++;
        }
        else if (i <= 51 && deck[i].getName() == "Two") {
            numCorrect++;
        }
        else {
            cout << deck[i].getName() << " of " << deck[i].getSuit() << " has a value of " << deck[i].getValue() << endl;
        }

    }
    cout << numCorrect << "/" << deck.size() << " Card Names are Correct." << endl;
    cout << endl;
}

/*Function to test the boolean active of each card in deck
-Used to find discrepencies when Card objects were created
-Used to test dealCard() and resetDeck() game functions*/
void testCardActive() {
    int numActive = 0;

    for (int i = 0; i < deck.size(); i++) {
        if (deck[i].isActive()) {
            numActive++;
        }
        else {
            cout << deck[i].getName() << " of " << deck[i].getSuit() << " is inactive." << endl;
        }
    }
    cout << numActive << "/" << deck.size() << " cards are active." << endl;
    cout << endl;

}

/*Function to test the suit of each card in deck
-Used to find discrepencies when Card objects were created*/
void testCardSuit() {
    int numCorrect = 0;

    for (int i = 0; i < deck.size(); i++) {
        if (i % 4 == 0 && deck[i].getSuit() == "Spades") {
            numCorrect++;
        }
        else if (i % 4 == 1 && deck[i].getSuit() == "Clubs") {
            numCorrect++;
        }
        else if (i % 4 == 2 && deck[i].getSuit() == "Hearts") {
            numCorrect++;
        }
        else if (i % 4 == 3 && deck[i].getSuit() == "Diamonds") {
            numCorrect++;
        }
        else {
            cout << deck[i].getName() << " of " << deck[i].getSuit() << " at index " << i << " has the wrong suit." << endl;
            cout << "Suit should be ";
            if (i % 4 == 0) {
                cout << "Spades." << endl;
            }
            else if (i % 4 == 1) {
                cout << "Clubs." << endl;
            }
            else if (i % 4 == 2) {
                cout << "Hearts." << endl;
            }
            else {
                cout << "Diamonds." << endl;
            }
        }
    }
    cout << numCorrect << "/" << deck.size() << " cards have the correct suit." << endl;
    cout << endl;
}

/*=====================================
=== Game Functions: ===================
=====================================*/

/*Resets active status of all Cards in deck
-If Card is an Ace, checks cards value
--If value has been changed to 1, sets it back at 11*/
void resetDeck() {
    for (int i = 0; i < deck.size(); i++) {
        if (deck[i].isActive() == false) {
            if (deck[i].getName() == "Ace" && deck[i].getValue() == 1) {
                deck[i].setValue(11);
            }
            deck[i].setActive();
        }
    }
}

/*Deals a randomm Card
-checks if card is active
-if card is active, returns card
-utilizes random library
--for more information on random seed, see main function*/
Card dealCard() {
    while (1) {
        if (cardsDealt < deck.size()) {
            while (1) {
                int randNum = rand() % 52;
                if (deck[randNum].isActive()) {
                    deck[randNum].setActive();
                    cardsDealt++;
                    return deck[randNum];
                }
            }
        }
        resetDeck();
        cardsDealt = 0;
    }
}

/*Sums the provided hand based on each Cards Value
-Input: vector of cards
-Returns: int value of sum
--if the sum is greater than 21, sumHand() will change Aces to ones until none are left or sum is less than or equal to 21*/
int sumHand(vector<Card> hand) {
    int sum = 0;
    for (int i = 0; i < hand.size(); i++) {
        sum += hand[i].getValue();
    }
    if (sum > 21) {
        for (int i = 0; i < hand.size(); i++) {
            if (hand[i].getValue() == 11) {
                sum -= 10;
                hand[i].setValue(1);
                if (sum <= 21) {
                    break;
                }
            }
        }
    }
    return sum;
}

/*Creates wager for the current game
-Displays wager prompts then takes user input for wager amount
--Wager must be numeric and must be greater than 0 but less than or equal to the usersBalance
---All non-numeric values are handled by the catch block*/
int createWager() {
    int wager;
    string userChoice;
    while (1) {
        cout << "Your Balance: $" << userBalance << endl;
        cout << "Ante Up! Whats your wager? $";
        cin >> userChoice;
        try {
            wager = stoi(userChoice);
            if (wager > 0 && wager <= userBalance) {
                userBalance -= wager;
                cout << endl;
                return wager;
            }
            else {
                cout << "Invalid input. Your wager must be a positive number less than or equal to your balance." << endl;
            }
        }
        catch (...) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Your wager must be a numeric value." << endl;
        }
    }
}

/*Processes user input for Yes/No prompts
-Input: string user input
-Returns: normalized string for corresponding choice
--Checks yes and no variation vectors for a match
---If match is found, returns normalized string for corresponding respond
---If no match is found, prompts new input and continues loop*/
string processYNInput(string choice) {
    string userChoice = choice;
    while (1) {
        for (int i = 0; i < yesVariations.size(); i++) {
            if (yesVariations[i] == userChoice) {
                return "y";
            }
        }
        for (int i = 0; i < noVariations.size(); i++) {
            if (noVariations[i] == userChoice) {
                return "n";
            }
        }
        cout << "Invalid input. Try Yes or No." << endl;
        cin >> userChoice;
    }
}

/*Processes user input for Hit/Stand/Double Down prompts
-Input: string user input
-Returns: normalized string for corresponding choice
--Checks yes and no variation vectors for a match
---If match is found, returns normalized string for corresponding respond
---If no match is found, prompts new input and continues loop*/
string processHSDInput(string choice) {
    string userChoice = choice;
    while (1) {
        for (int i = 0; i < hitVariations.size(); i++) {
            if (hitVariations[i] == userChoice) {
                return "h";
            }
        }
        for (int i = 0; i < standVariations.size(); i++) {
            if (standVariations[i] == userChoice) {
                return "s";
            }
        }
        for (int i = 0; i < doubleDVariations.size(); i++) {
            if (doubleDVariations[i] == userChoice) {
                return "d";
            }
        }
        cout << "Invalid input. Try Hit, Stand, or Double Down." << endl;
        cin >> userChoice;
    }
}

/*Processes user input for Hit/Stand prompts
-Input: string user input
-Returns: normalized string for corresponding choice
--Checks yes and no variation vectors for a match
---If match is found, returns normalized string for corresponding respond
---If no match is found, prompts new input and continues loop*/
string processHSInput(string choice) {
    string userChoice = choice;
    while (1) {
        for (int i = 0; i < hitVariations.size(); i++) {
            if (hitVariations[i] == userChoice) {
                return "h";
            }
        }
        for (int i = 0; i < standVariations.size(); i++) {
            if (standVariations[i] == userChoice) {
                return "s";
            }
        }
        cout << "Invalid input. Try Hit or Stand." << endl;
        cin >> userChoice;
    }
}

/*Displays welcome screen prompt
-prompts user to play game
-if yes returns true
-if no returns false
--for more information on implementation see main function*/
bool displayWelcome() {
    string userChoice;
    cout << "Welcome to Cody's Casino Blackjack!" << endl;
    cout << "Would you like to play? (Yes/No)" << endl;
    cin >> userChoice;
    userChoice = processYNInput(userChoice);
    if (userChoice == "y") {
        cout << endl;
        return true;
    }
    else if (userChoice == "n") {
        cout << endl;
        return false;
    }
}

/*Displays split prompt
-prompts user to split their hand
-if yes returns true
-if no returns false
--for more information on implementation see main function*/
bool decideSplit() {
    string userChoice;
    cout << "Would you like to split? (Yes/No)" << endl;
    cin >> userChoice;
    userChoice = processYNInput(userChoice);
    if (userChoice == "y") {
        cout << endl;
        return true;
    }
    else if (userChoice == "n") {
        cout << endl;
        return false;
    }
}

/*Determines in a hand busts
-Input: vector of Cards
-Returns: boolean value
--If sumHand is greater than 21 returns true
--If sumHand is less than or equal to 21 returns false
---For more information on implementation see main function*/
bool determineBust(vector<Card> hand) {

    if (sumHand(hand) > 21) {
        return true;
    }
    else {
        return false;
    }
}

/*Displays continue game prompt
-If userBalance is 0 game ends automatically
-If yes returns true and the game continues
-If no displays the amount of money won or lost throughout, returns false, and the game and game ends
--For more information on implementation see main funciton*/
bool continueGame() {
    string userChoice;
    int difference;
    if (userBalance == 0) {
        cout << "You're bankrupt!" << endl;
        return false;
    }
    cout << "Would you like to play again? (Yes/No)" << endl;
    cin >> userChoice;
    userChoice = processYNInput(userChoice);
    if (userChoice == "y") {
        cout << endl;
        return true;
    }
    else if (userChoice == "n") {
        difference = userBalance - 200;
        if (difference > 0) {
            cout << "You won $" << difference << ". Great job!" << endl;
            return false;
        }
        else if (difference < 0) {
            cout << "You lost $" << abs(difference) << ". Better luck next time." << endl;
            return false;  
        }
        else {
            cout << "You broke even. Congratulations I guess." << endl;
            return false;
        }
    }
}

/*Displays Header showing the user balance and the current wager
-Used for single hands*/
void displayHeader(int wager) {
    cout << "Your Balance: $" << userBalance << " | Wager: $" << wager << endl;
    cout << endl;
}

/*Displays Header showing the user balance and bother wagers
-Used for split hands*/
void displaySplitHeader(int wager1, int wager2) {
    cout << "Your Balance: $" << userBalance << " | Hand 1 Wager: $" << wager1 << " | Hand 2 Wager: $" << wager2 << endl;
    cout << endl;

}

/*Displays the entire user hand and the total of that hand
-Used for single hands*/
void displayUserHand(vector<Card> hand) {
    cout << "Your Hand:" << endl;
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i].getName() << " of " << hand[i].getSuit() << endl;
    }
    cout << "Total: " << sumHand(hand) << endl;
    cout << endl;
}

/*Displays the entirety of both user hands and the total of each hand
-Used for split hands*/
void displaySplitHand(vector<Card> hand1, vector<Card> hand2) {
    cout << "Hand 1:" << endl;
    for (int i = 0; i < hand1.size(); i++) {
        cout << hand1[i].getName() << " of " << hand1[i].getSuit() << endl;
    }
    cout << "Total: " << sumHand(hand1) << endl;
    cout << endl;
    cout << "Hand 2:" << endl;
    for (int i = 0; i < hand2.size(); i++) {
        cout << hand2[i].getName() << " of " << hand2[i].getSuit() << endl;
    }
    cout << "Total: " << sumHand(hand2) << endl;
    cout << endl;

}

/*Displays first card and dealers hand, unknown card and a possible total (example: if card is an Ace total : >11
-Used during user's turn*/
void displayUnknownHand(vector<Card> hand) {
    cout << "Dealer's Hand:" << endl;
    cout << hand[0].getName() << " of " << hand[0].getSuit() << endl;
    cout << "Unknown Card" << endl;
    cout << "Total: >" << hand[0].getValue() << endl;
    cout << endl;

}

/*Displays the entire dealer hand and the total of the dealer's hand
-Used when determinging the coutcome of the game*/
void displayDealerHand(vector<Card> hand) {
    cout << "Dealer's Hand:" << endl;
    for (int i = 0; i < hand.size(); i++) {
        cout << hand[i].getName() << " of " << hand[i].getSuit() << endl;
    }
    cout << "Total: " << sumHand(hand) << endl;
    cout << endl;
}

/*Determines the outcome of a single hand game
-Displays all information of the game
-Determines the outcome
-Adjusts user balance and outputs the outcome*/
void determineOutcome(vector<Card>uHand, vector<Card> dHand, bool uBust, bool dBust) {
    displayHeader(wager1);
    displayDealerHand(dHand);
    displayUserHand(uHand);
    if (uBust) {
        cout << "You busted." << endl;
        cout << "Your balance: $" << userBalance << endl;
        cout << endl;
    }
    if (dBust) {
        userBalance += (wager1 * 2);
        cout << "The dealer busted!" << endl;
        cout << "Your balance: $" << userBalance << endl;
        cout << endl;
    }
    if (sumHand(uHand) > sumHand(dHand) && !uBust) {
        userBalance += (wager1 * 2);
        cout << "You won!" << endl;
        cout << "Your balance: $" << userBalance << endl;
        cout << endl;
    }
    else if (sumHand(uHand) < sumHand(dHand) && !dBust) {
        cout << "You lose." << endl;
        cout << "Your balance: $" << userBalance << endl;
        cout << endl;
    }
    else if (sumHand(uHand) == sumHand(dHand)) {
        userBalance += wager1;
        cout << "It's a draw." << endl;
        cout << "Your balance: $" << userBalance << endl;
        cout << endl;
    }
}

/*Determines the outcome of a split game
-Displays all information of the game
-Determines the outcome of hand1, adjusts userBalance */
void determineHand1Outcome(vector<Card> hand1, vector<Card> hand2, vector<Card> dHand, bool uBust, bool dBust) {
    displaySplitHeader(wager1, wager2);
    displayDealerHand(dHand);
    displaySplitHand(hand1, hand2);
    bool resolved = false;
    if (uBust && dBust) {
        userBalance += wager1;
        cout << "Your first hand is a draw. You and the dealer busted." << endl;
        resolved = true;
    }
    else if (uBust) {
        cout << "Your first hand loses. You busted." << endl;
        resolved = true;
    }
    else if (dBust) {
        userBalance += (wager1 * 2);
        cout << "Your first hand wins! The dealer busted!" << endl;
        resolved = true;
    }
    if (!resolved) {
        if (sumHand(hand1) > sumHand(dHand) && !uBust) {
            userBalance += (wager1 * 2);
            cout << "Your first hand wins!" << endl;
        }
        else if (sumHand(hand1) < sumHand(dHand) && !dBust) {
            cout << "Your first hand loses." << endl;
        }
        else if (sumHand(hand1) == sumHand(dHand)) {
            userBalance += wager1;
            cout << "Your first hand is a draw." << endl;
        }
    }
}

/*Determines the outcome of a split game
-Determines the outcome of hand2, adjusts userBalance, and outputs userBalance*/
void determineHand2Outcome(vector<Card> hand2, vector<Card> dHand, bool sBust, bool dBust) {
    bool resolved = false;
    if (sBust && dBust) {
        userBalance += wager2;
        cout << "Your second hand is a draw. You and the dealer busted." << endl;
        resolved = true;
    }
    else if (sBust) {
        cout << "Your second hand loses. You busted." << endl;
        resolved = true;
    }
    else if (dBust) {
        userBalance += (wager2 * 2);
        cout << "Your second hand wins! The dealer busted!" << endl;
        resolved = true;
    }
    if (!resolved) {
        if (sumHand(hand2) > sumHand(dHand) && !sBust) {
            userBalance += (wager2 * 2);
            cout << "Your second hand wins!" << endl;
        }
        else if (sumHand(hand2) < sumHand(dHand) && !dBust) {
            cout << "Your second hand loses." << endl;
        }
        else if (sumHand(hand2) == sumHand(dHand)) {
            userBalance += wager2;
            cout << "Your second hand is a draw." << endl;
        }
    }
    cout << "Your Balance: $" << userBalance << endl;
    cout << endl;
}

/*Gameplay loop for the user turn in a single hand game
-Input: userHand vector, dealerHand vector, and the int wager
-Returns: vector of cards
--For more information on implementation see main funciton*/
vector<Card> userPlay(vector<Card> uHand, vector<Card> dHand, int wager) {
    vector<Card> userHand = uHand;
    string userChoice;
    while (1) {
        displayHeader(wager);
        displayUnknownHand(dHand);
        displayUserHand(userHand);
        if (sumHand(userHand) > 21) {
            return userHand;
        }
        if (wager <= userBalance) {
            cout << "What would you like to do? (Hit/Stand/Double Down)" << endl;
            cin >> userChoice;
            userChoice = processHSDInput(userChoice);
            if (userChoice == "h") {
                userHand.insert(userHand.end(), dealCard());
            }
            else if (userChoice == "s") {
                return userHand;
            }
            else if (userChoice == "d") {
                userBalance -= wager1;
                wager1 += wager1;
                userHand.insert(userHand.end(), dealCard());
                return userHand;
            }
        }
        else {
            cout << "What would you like to do? (Hit/Stand)" << endl;
            cin >> userChoice;
            userChoice = processHSInput(userChoice);
            if (userChoice == "h") {
                userHand.insert(userHand.end(), dealCard());
            }
            else if (userChoice == "s") {
                return userHand;
            }
        }
    }
}

/*Gameplay loop for the first hand user turn in a split hand game
-Input: userHand1 vector, userHand2 vector, dealerhand vector
-Returns: vector of cards
--For more information on implementation see main funciton*/
vector<Card> splitPlay1(vector<Card> hand1, vector<Card> hand2, vector<Card> dHand) {
    vector<Card> userHand = hand1;
    string userChoice;
    while (1) {
        displaySplitHeader(wager1, wager2);
        displayUnknownHand(dHand);
        displaySplitHand(userHand, hand2);
        if (sumHand(userHand) > 21) {
            return userHand;
        }
        cout << "Working on Hand 1..." << endl;
        if (wager1 <= userBalance) {
            cout << "What would you like to do? (Hit/Stand/Double Down)" << endl;
            cin >> userChoice;
            userChoice = processHSDInput(userChoice);
            if (userChoice == "h") {
                userHand.insert(userHand.end(), dealCard());
            }
            else if (userChoice == "s") {
                return userHand;
            }
            else if (userChoice == "d") {
                userBalance -= wager1;
                wager1 += wager1;
                userHand.insert(userHand.end(), dealCard());
                return userHand;
            }
        }
        else {
            cout << "What would you like to do? (Hit/Stand)" << endl;
            cin >> userChoice;
            userChoice = processHSInput(userChoice);
            if (userChoice == "h") {
                userHand.insert(userHand.end(), dealCard());
            }
            else if (userChoice == "s") {
                return userHand;
            }
        }
    }
}

/*Gameplay loop for the second hand user turn in a split hand game
-Input: userHand1 vector, userHand2 vector, dealerhand vector
-Returns: vector of cards
--For more information on implementation see main funciton*/
vector<Card> splitPlay2(vector<Card> hand1, vector<Card> hand2, vector<Card> dHand) {
    vector<Card> splitHand = hand2;
    string userChoice;
    while (1) {
        displaySplitHeader(wager1, wager2);
        displayUnknownHand(dHand);
        displaySplitHand(hand1, splitHand);
        if (sumHand(splitHand) > 21) {
            return splitHand;
        }
        cout << "Working on Hand 2..." << endl;
        if (wager2 <= userBalance) {
            cout << "What would you like to do? (Hit/Stand/Double Down)" << endl;
            cin >> userChoice;
            userChoice = processHSDInput(userChoice);
            if (userChoice == "h") {
                splitHand.insert(splitHand.end(), dealCard());
            }
            else if (userChoice == "s") {
                return splitHand;
            }
            else if (userChoice == "d") {
                userBalance -= wager2;
                wager2 += wager2;
                splitHand.insert(splitHand.end(), dealCard());
                return splitHand;
            }
        }
        else {
            cout << "What would you like to do? (Hit/Stand)" << endl;
            cin >> userChoice;
            userChoice = processHSInput(userChoice);
            if (userChoice == "h") {
                splitHand.insert(splitHand.end(), dealCard());
            }
            else if (userChoice == "s") {
                return splitHand;
            }
        }
    }
}

/*Initial deal at the start of game
-returns a vector of 2 card objects*/
vector<Card> initialDeal() {
    vector<Card> hand;
    hand.insert(hand.end(), dealCard());
    hand.insert(hand.end(), dealCard());
    return hand;
}

/*Logic for dealer play during a single hand game*/
vector<Card> dealerPlay(vector<Card> hand, bool bust) {
    vector<Card> dealerHand = hand;
    if (bust) {
        return dealerHand;
    }
    while (1) {
        if (sumHand(dealerHand) > 21) {
            return dealerHand;
        }
        else if (sumHand(dealerHand) < 17) {
            dealerHand.insert(dealerHand.end(), dealCard());
        }
        else {
            return dealerHand;
        }
    }
}

/*Logic for dealer play during a split hand game*/
vector<Card> dealerSplitPlay(vector<Card> hand, bool bust1, bool bust2) {
    vector<Card> dealerHand = hand;
    if (bust1 && bust2) {
        return dealerHand;
    }
    while (1) {
        if (sumHand(dealerHand) > 21) {
            return dealerHand;
        }
        else if (sumHand(dealerHand) < 17) {
            dealerHand.insert(dealerHand.end(), dealCard());
        }
        else {
            return dealerHand;
        }
    }
}


/*=====================================
=== Main Function: ====================
=====================================*/

int main()
{
    /*Local Boolean Variables*/
    bool activeGame = false;
    bool activeSplit = false;
    bool userBust = false;
    bool splitBust = false;
    bool dealerBust = false;

    /*Uses current time to set random seed
    -This method allows different seed on every play through*/
    time_t currentTime = time(NULL);
    srand(currentTime);

    /*Vectors for each Hand*/
    vector<Card> userHand;
    vector<Card> dealerHand;
    vector<Card> splitHand;

    /*Establish gameplay loop*/
    activeGame = displayWelcome();
    while (activeGame) {
        activeSplit = false;
        /*Establish the wager for the current game*/
        wager1 = createWager();
        /*Deal Cards to the user hand and dealer hand*/
        userHand = initialDeal();
        dealerHand = initialDeal();
        /*Check for split opportunity and determine if the user wants to split*/
        if (userHand[0].getName() == userHand[1].getName() && wager1 <= userBalance) {
            displayHeader(wager1);
            displayUnknownHand(dealerHand);
            displayUserHand(userHand);
            activeSplit = decideSplit();
        }
        if (activeSplit) {
            /*Split Set Up*/
            wager2 = wager1;
            userBalance -= wager2;
            splitHand.insert(splitHand.end(), userHand[1]);
            userHand.pop_back();
            userHand.insert(userHand.end(), dealCard());
            splitHand.insert(splitHand.end(), dealCard());
            /*User plays the first hand and checks for bust*/
            userHand = splitPlay1(userHand, splitHand, dealerHand);
            userBust = determineBust(userHand);
            /*User plays the second hand and checks for bust*/
            splitHand = splitPlay2(userHand, splitHand, dealerHand);
            splitBust = determineBust(splitHand);
            /*Dealer plays their hand*/
            dealerHand = dealerSplitPlay(dealerHand, userBust, splitBust);
            dealerBust = determineBust(dealerHand);
            /*Determines Outcome for both hands*/
            determineSplitOutcome(userHand, splitHand, dealerHand, userBust, splitBust, dealerBust);
            /*Reset everything used in the game*/
            userHand.clear();
            splitHand.clear();
            dealerHand.clear();
            wager1 = 0;
            wager2 = 0;
            userBust = false;
            splitBust = false;
            dealerBust = false;
        }
        else {
            /*User plays their hand and checks for bust*/
            userHand = userPlay(userHand, dealerHand, wager1);
            userBust = determineBust(userHand);
            /*Dealer plays their hand and checks for bust*/
            dealerHand = dealerPlay(dealerHand, userBust);
            dealerBust = determineBust(dealerHand);
            /*Determines outcome*/
            determineOutcome(userHand, dealerHand, userBust, dealerBust);
            /*Reset everything used in the game*/
            userHand.clear();
            dealerHand.clear();
            wager1 = 0;
            userBust = false;
            dealerBust = false;
        }
        /*Check if user wants to play again*/
        activeGame = continueGame();  
    }
    cout << "Thank you for playing!" << endl;
    return 0;
}
