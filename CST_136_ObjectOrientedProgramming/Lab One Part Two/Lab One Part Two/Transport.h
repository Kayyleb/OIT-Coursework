// Name: Kayleb Cook
// Programming Assignment: Lab 2: Transport More Manager Functions
#pragma once
#include "Passenger.h"


class Transport {
private:
	Passenger passengers[49];
	int current;
public:
    Transport();
    Transport(const Transport& other);
    Transport& operator=(const Transport& other);
    Transport(Transport&& other) noexcept = default;
    Transport& operator=(Transport&& other) noexcept = default;
    ~Transport();

    void getNextpassenger();
    void passengerArrival();
    void musicalChairs();
};
