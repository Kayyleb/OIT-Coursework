// Day 24 Games.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */ 
using namespace std;

void rockPaperScissors();
int guessingGame();
void twentyOnePickup();

int main() {
    int choice = 4;
    do {
        cout << "Choose any game to play" << endl;
        cout << "1 for Rock Paper Scissors" << endl;
        cout << "2 for The Guessing Game" << endl;
        cout << "3 for 21 Pickup" << endl;
        cout << "4 to Quit" << endl;
        cin >> choice;

        switch (choice) {
        case 1: rockPaperScissors();
            break;
        case 2: guessingGame();
            break;
        case 3: twentyOnePickup();
            break;
        }
    }
            while (choice != 4);
}

void rockPaperScissors() 
{
    int rpsRandom = 0;
    int rps;
    srand(time(NULL));
    rpsRandom = rand() % 3 + 1;
        cout << "Player 1, Choose 1 for Rock, 2 for  Paper, or 3 for Scissors" << endl;
        cin >> rps;

        if (rps == rpsRandom)
            cout << "Tie Game" << endl;

        else if ((rps == 1 && rpsRandom == 3) || (rps == 3 && rpsRandom == 2) || (rps == 2 && rpsRandom == 1))
            cout << "Player Wins" << endl;

        if ((rps == 1 && rpsRandom == 2) || (rps == 3 && rpsRandom == 1) || (rps == 2 && rpsRandom == 3))
            cout << "Computer Wins" << endl;
}

int guessingGame() 
{
    int randomNumber = 0;
    int guess = 0;
    srand(time(NULL));
    randomNumber = rand() % 10 + 1;
    do {
        cout << "Guess a number between 1 and 10: " << endl;
        cin >> guess;
        if (randomNumber > guess) puts("Guess Higher!");
        else if (randomNumber < guess) puts("Guess Lower!");
       } 
    while (randomNumber != guess);
    cout << "You Guessed Coreectly" << endl;
    return 0;
}

void twentyOnePickup()
{
    int twentyOne = 21;
    int take = 0;
    for (int i = 0; i < 5; i++) {
    cout << "Choose a value between 1 and 3 to take away: " << endl;
    cin >> take;
    int computerValue = (4 - take);
    twentyOne = twentyOne - take;
    twentyOne = twentyOne - computerValue; 
    cout << "Computer has taken " << (computerValue) << endl;
    if (twentyOne == 1)
        cout << "Computer Wins" << endl;
    }

}