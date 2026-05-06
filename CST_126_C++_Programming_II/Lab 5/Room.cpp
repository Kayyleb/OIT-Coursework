#include "Room.h"

Room::Room() :m_description("description"), m_north(0), m_south(0), m_east(0), m_west(0), m_gameOver(0)
{
}

Room::Room(string description, int north, int south, int east, int west, int gameOver) : m_description(description), m_north(north), m_south(south), m_east(east), m_west(west), m_gameOver(gameOver)
{
}

Room::Room(char*line)
{
	char* token = nullptr;
	token = strtok(line, ",");
	m_description = token;
	token = strtok(NULL, ",");
	m_north = atoi(token);
	token = strtok(NULL, ",");
	m_south = atoi(token);
	token = strtok(NULL, ",");
	m_east = atoi(token);
	token = strtok(NULL, ",");
	m_west = atoi(token);
	token = strtok(NULL, ",");
	m_gameOver = atoi(token);
}

void Room::setDescription(string description)
{
	m_description = description;
}

void Room::setNorth(int north)
{
	m_north = north;
}

void Room::setSouth(int south)
{
	m_south = south;
}

void Room::setEast(int east)
{
	m_east = east;
}

void Room::setWest(int west)
{
	m_west = west;
}

void Room::setgameOver(int gameOver)
{
	m_gameOver = gameOver;
}

string Room::getDescription()
{
	return m_description;
}

int Room::getNorth()
{
	return m_north;
}

int Room::getSouth()
{
	return m_south;
}

int Room::getEast()
{
	return m_east;
}

int Room::getWest()
{
	return m_west;
}

int Room::getgameOver()
{
	return m_gameOver;
}

Room::~Room()
{
}
