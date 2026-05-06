#include "header1.h"

int main()
{
	int numAuthors = 0;
	AuthorStats** authorInfo = new AuthorStats * [5];
	loadAuthorStats(authorInfo, numAuthors);

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

	averageLength = (totalChar / totalWords);
	cout << "The Average Word Length is: " << averageLength << endl;

	token = (wordsperFile / totalWords);
	cout << "The Type-Token Ratio is: " << token << endl;

	hapax = ((hapaxWord) / totalWords);
	cout << "The Hapax Legomana Ratio is: " << hapax << endl;

		bool found = false;
		float similarityScore = 0;
		float bestSimilarity = 100;
		int keepTrack = 0;
		for (int j = 0; j < numAuthors; j++) {
				float avgWL = (abs(authorInfo[j]->avgerageWL - averageLength) * 11);
				float tok = (abs(authorInfo[j]->typeTokenR - token) * 33);
				float hap = (abs(authorInfo[j]->hapaxRatio - hapax) * 50);
				similarityScore = (avgWL + tok + hap);
				if (similarityScore < bestSimilarity) {
					bestSimilarity = similarityScore;
					keepTrack = j;
			}
		}
		cout << " This is most likely written by: " << authorInfo[keepTrack]->firstName << " " << authorInfo[keepTrack]->lastName << endl;

		return 0;
}

int loadAuthorStats(AuthorStats** authorInfo, int& numAuthors) {
	ifstream fin("C:\\Users\\kayleb.cook\\Downloads\\authorStats.txt");
	char buffer[10000];
	if (fin.is_open()) {
		while (!fin.eof()) {
			authorInfo[numAuthors] = new AuthorStats;
			fin >> authorInfo[numAuthors]->firstName;
			fin >> authorInfo[numAuthors]->lastName;
			fin >> authorInfo[numAuthors]->avgerageWL;
			fin >> authorInfo[numAuthors]->typeTokenR;
			fin >> authorInfo[numAuthors]->hapaxRatio;
			numAuthors++;
		}
	}
	fin.close();

	return 0;
}

