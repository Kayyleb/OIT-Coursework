#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

float averageLength;
float token = 0;
float hapax = 0;

struct AuthorStats {
	char firstName[25];
	char lastName[25];
	float avgerageWL;
	float typeTokenR;
	float hapaxRatio;
};

int loadAuthorStats(AuthorStats** authorInfo, int& numAuthors);

