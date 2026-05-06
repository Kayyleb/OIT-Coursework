#define _CRT_SECURE_NO_WARNINGS
#define _CRT_DBG_MAP_ALLOC
#include<crtdbg.h>
#include <iostream>
#include <fstream>

using namespace std;

//Part One 
int loadFromFile(char** pantry, int& numIngredients, char* fileName);
int displayIngredients(char** pantry, int& numIngredients);

//Part Two
int addIngredient(char** pantry, int& numIngredients, char* addedIngredient);
int searchIngredients(char** pantry, int& numIngredients, char* checkIngredient);
int saveToFile(char** pantry, int& numIngredients, char* fileName);

//Part Three
int changeIngredient(char** pantry, int& numIngredients, char* oldIngredient, char* newIngredient);
int removeIngredients(char** pantry, int& numIngredients, char* removeIngredient);

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Part One
	char** pantry = new char* [360];
	int numIngredients = 0;
	char fileName[] = "C:\\Users\\kayleb.cook\\Downloads\\food.txt";
	loadFromFile(pantry, numIngredients, fileName);

	//Part Two
	char addedIngredient[] = "pepper";
	char checkIngredient[] = "fruit";
	addIngredient(pantry, numIngredients, addedIngredient);
	displayIngredients(pantry, numIngredients);
	searchIngredients(pantry, numIngredients, checkIngredient);
	saveToFile(pantry, numIngredients, fileName);

	//Part Three
	char oldIngredient[] = "tomatoes";
	char newIngredient[] = "milk";
	char removeIngredient[] = "flour";
	changeIngredient(pantry, numIngredients, oldIngredient, newIngredient);
	displayIngredients(pantry, numIngredients);
	removeIngredients(pantry, numIngredients, removeIngredient);
}

int loadFromFile(char** pantry, int& numIngredients, char* fileName) {
	char buffer[35];
	ifstream  fin(fileName);
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> buffer;

			pantry[numIngredients] = new char[strlen(buffer) + 1];
			strcpy(pantry[numIngredients], buffer);
			numIngredients++;
		}
	}
	fin.close();
	return 0;
}

int displayIngredients(char** pantry, int& numIngredients) {
	for (int i = 0; i < numIngredients; i++) {
		cout << pantry[i] << endl;
	}
	return 0;
}

int addIngredient(char** pantry, int& numIngredients, char* addedIngredient) {
	pantry[numIngredients] = new char[strlen(addedIngredient) + 1];
	strcpy(pantry[numIngredients], addedIngredient);
	numIngredients++;
	return 0;
}

int searchIngredients(char** pantry, int& numIngredients, char* checkIngredient) {
	bool found = false;
	for (int i = 0; i < numIngredients; i++) {
		if (_stricmp(pantry[i], checkIngredient) == 0) {
			found = true;
			cout << "\n" << checkIngredient << " was found" << "\n" << endl;

		}
	}
	if (!found) {
		cout << "\n" << checkIngredient << " was NOT found!" << "\n" << endl;
	}
	return 0;
}

int saveToFile(char** pantry, int& numIngredients, char* fileName)
{
	ifstream fin("C:\\Users\\kayleb.cook\\Downloads\\NewPantry.txt");
	if (fin.is_open()) {

		ofstream fout("C:\\Users\\kayleb.cook\\Downloads\\NewPantry.txt");
		for (int i = 0; i < numIngredients; i++) {
			fout << pantry[i] << "\n";
		}
		return 0;
	}
	fin.close();
}

int changeIngredient(char** pantry, int& numIngredients, char* oldIngredient, char* newIngredient)
{
	bool found = false;
	for (int i = 0; i < numIngredients; i++) {
		if (_stricmp(pantry[i], oldIngredient) == 0) {
			found = true;
			delete[] pantry[i];
			pantry[i] = new char[strlen(newIngredient) + 1];
			strcpy(pantry[i], newIngredient);
		}
	}
	return 0;
}

int removeIngredients(char** pantry, int& numIngredients, char* removeIngredient)
{
	bool found = false;
	for (int i = 0; i < numIngredients; i++) {
		if (_stricmp(pantry[i], removeIngredient) == 0) {
			found = true;
			numIngredients--;
			delete[] pantry[i];
			(pantry[i] = pantry[numIngredients]);

		}
	}
	return 0;
}