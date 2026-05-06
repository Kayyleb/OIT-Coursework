#include "GamePlayer.h"

//Contructors: 
GamePlayer::GamePlayer(): m_name("Jackie"), m_lives(5), m_score(0)
{
}

GamePlayer::GamePlayer(string name, int lives, double score): m_name(name), m_lives(lives) , m_score(score)
{
}

//Setters: 
void GamePlayer::setName(string name)
{
	m_name = name;

}

void GamePlayer::setLives(int lives)
{
	m_lives = lives;
}

void GamePlayer::setScore(double score)
{
	m_score = score;
}

//Getters
string GamePlayer::getName()
{
	return m_name;
}

int GamePlayer::getLives()
{
	return m_lives;
}

double GamePlayer::getScore()
{
	return m_score;
}

//Deconstructor
GamePlayer::~GamePlayer()
{
}

//We do not use "new" at all