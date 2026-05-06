#include "GamePlayer.h"
#include "Room.h"

int main()
{
	char line[50];
	char direction[10];
	const int maximumLength = 35;
	const int maximumRooms = 10;
	int currentRoom = 0;
	Room** mazeRooms = new Room * [10];

	cout << "Welcome to the MAZE GAME" << endl;
	string name = "";
	cout << "What's your name?" << endl;
	cin >> name;
	GamePlayer* gamePlayer = new GamePlayer(name, 3, 0);
	cout << "Welcome " << gamePlayer->getName() << " . You have " << gamePlayer->getLives() << " lives and " << gamePlayer->getScore() << " points." << endl;
	cout << "You will be playing in the " << "The Mansion" << " ." << endl;

	ifstream fin("C:\\Users\\kayleb.cook\\Downloads\\mansion.txt");
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin.getline(line, 50);
			Room* room = new Room(line);
			mazeRooms[currentRoom] = room;
			currentRoom++;
		}
		fin.close();
	}
	currentRoom = 0;
	do {
		cout << "you're currently in " << mazeRooms[currentRoom]->getDescription() << endl;
		cout << "you can travel " << endl;
		if (mazeRooms[currentRoom]->getNorth() != -1) {
			cout << "north, ";
		}
		if (mazeRooms[currentRoom]->getSouth() != -1) {
			cout << "south, ";
		}
		if (mazeRooms[currentRoom]->getEast() != -1) {
			cout << "east, ";
		}
		if (mazeRooms[currentRoom]->getWest() != -1) {
			cout << "west, ";
		}
		cout << "where do you want to go?" << endl;
	
		cin >> direction;
		if (strcmp(direction, "north") == 0) {
			currentRoom = mazeRooms[currentRoom]->getNorth();
		}
		if (strcmp(direction, "south") == 0) {
			currentRoom = mazeRooms[currentRoom]->getSouth();
		}
		if (strcmp(direction, "east") == 0) {
			currentRoom = mazeRooms[currentRoom]->getEast();
		}
		if (strcmp(direction, "west") == 0) {
			currentRoom = mazeRooms[currentRoom]->getWest();
		}
	}
	
	while (mazeRooms[currentRoom]->getgameOver() != 0);
	cout << "You win! :)" << endl;
}
