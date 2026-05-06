// Name: Kayleb Cook
// Programming Assignment: Lab 2: Transport More Manager Functions
#pragma once
#include <iostream>
#include "String.h" 

class Passenger {
private:
	unsigned int seatNumber;
	String firstName;
	String lastName;

public:
	//Constructors
	Passenger();
	Passenger(unsigned int seat, const String first, const String last);
	Passenger(const Passenger& other);
	Passenger& operator=(const Passenger& other);

	//Not used: 
	Passenger(Passenger&& other) noexcept;
	Passenger& operator=(Passenger&& other) noexcept;


	~Passenger();
};