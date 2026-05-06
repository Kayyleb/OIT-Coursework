#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	char fileWord[35];
	char words[10000][35];
	int count[10000];
	int wordsperFile = 0;
	float totalWords = 0;
	float hapaxWord = 0;
	float totalChar = 0;
	ifstream fin("C:\\Users\\kayleb.cook\\Downloads\\mystery1.txt");

	if (fin.is_open()) {
		while (!fin.eof()) {
			fin >> fileWord;
			//cout << fileWord << "\n";

			bool found = false;
			for (int i = 0; i < wordsperFile; i++) {
				if (_stricmp(words[i], fileWord) == 0) {
					count[i]++;
					found = true;
					totalWords++;

				}
			}
			if (!found) {
				strcpy(words[wordsperFile], fileWord);
				count[wordsperFile] = 1;
				wordsperFile++;
				totalWords++;
			}
		}
	}

	fin.close();

	for (int j = 0; j < wordsperFile; j++) {
		//cout << words[j] << " " << count[j] << "\n";
		if (count[j] == 1) {
			hapaxWord++;
		}
		int value = strlen(words[j]) * count[j];
		totalChar = value + totalChar;
			
	}

	float averageLength = (totalChar / totalWords);
	cout << "The Average Word Length is: " << averageLength << endl;

	float token = (wordsperFile / totalWords);
	cout << "The Type-Token Ratio is: " << token << endl;

	float hapax = ((hapaxWord) / totalWords);
	cout << "The Hapax Legomana Ratio is: " << hapax << endl;

}