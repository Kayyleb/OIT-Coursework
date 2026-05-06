#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class GamePlayer {
private: 
	string m_name;
	int m_lives;
	double m_score;
public:
	//Constructors
	GamePlayer();
	GamePlayer(string name, int lives, double score);

	//Setters
	void setName(string name);
	void setLives(int lives);
	void setScore(double score);
	//Getters
	string getName();
	int getLives();
	double getScore();

	//Deconstructor
	~GamePlayer();
};

