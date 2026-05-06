// Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <time.h> 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int tries = 7;
	char guess;
	int finalWord = 1;
	char mysteryWord[35];
	char mysteryDashes[35];

	ifstream fin("C:\\Users\\kayleb.cook\\Downloads\\hangmanWords.txt");
	char words[1000][35];
	int randomPosititon;
	if (fin.is_open()) {
		for (int i = 0; i < 999; i++) {
			fin >> words[i];
		}

		fin.close();
	}
	srand(time(NULL));
	randomPosititon = rand() % 1000;
	strcpy(mysteryWord, words[randomPosititon]);
	strcpy(mysteryDashes, mysteryWord);
	for (int i = 0; i < strlen(mysteryWord); i++) {
		mysteryDashes[i] = '_';
	}

	while ((tries != 0) && (finalWord != 0)) {
		cout << "Your word is " << mysteryDashes << ". " << endl;
		cout << endl;

		cout << "You have " << tries << " guesses left. " << endl;
		cout << endl;

		cout << "Guess a letter: " << endl;
		cin >> guess;
		cout << endl; 


		bool found = false;
		for (int i = 0; i < strlen(mysteryWord); i++) {
			if (guess == mysteryWord[i]) {
				mysteryDashes[i] = guess;
				found = true;
			}

		}
		if (!found) {
			tries = (tries - 1);
			cout << guess << " is NOT in the word!" << endl;
		}

		finalWord = strcmp(mysteryWord, mysteryDashes);
		if (finalWord == 0) {
			cout << "Your word is: " << mysteryWord << "! YOU WIN!!!" << endl;
		}

		else {
			switch (tries) {
			case 7: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |             " << endl;
				cout << "      |             " << endl;
				cout << "      |             " << endl;
				cout << "      |             " << endl;
				break;
			}

			case 6: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          O  " << endl;
				cout << "      |             " << endl;
				cout << "      |             " << endl;
				cout << "      |             " << endl;
				break;
			}
			case 5: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          O  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |             " << endl;
				cout << "      |             " << endl;
				break;
			}
			case 4: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          O  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |             " << endl;
				break;
			}
			case 3: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          O  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |         /   " << endl;
				break;
			}
			case 2: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          O  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |         / \\" << endl;
				break;
			}
			case 1: {
				cout << "       _________ " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |          O  " << endl;
				cout << "      |        / |  " << endl;
				cout << "      |          |  " << endl;
				cout << "      |         / \\" << endl;
				break;
			}
			case 0: {
				cout << "       _________ " << endl;
				cout << "      |          |   " << endl;
				cout << "      |          |   " << endl;
				cout << "      |          O   " << endl;
				cout << "      |        / | \\" << endl;
				cout << "      |          |   " << endl;
				cout << "      |         / \\ " << endl;
				cout << " GAME OVER!! YOU LOOSE!!" << endl;
				cout << " Your word was: " << mysteryWord << endl;
				break;
			}
			}
		}
	}
}