#pragma once
#include "GamePlayer.h"

class Room {
private:
	string m_description;
	int m_north;
	int m_south;
	int m_east;
	int m_west;
	int m_gameOver;
public:
	//Constructors:
	Room();
	Room(string description , int north, int south, int east, int west , int gameOver);
	Room(char*);

	//Setters
	void setDescription(string description);
	void setNorth(int north);
	void setSouth(int south);
	void setEast(int east);
	void setWest(int west);
	void setgameOver(int gameOver);

	//Getters
	string getDescription();
	int getNorth();
	int getSouth();
	int getEast();
	int getWest();
	int getgameOver();

	//Deconstructor
	~Room();
};