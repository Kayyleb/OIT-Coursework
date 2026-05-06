// Name: Kayleb Cook
// Programming Assignment: Lab 2: Transport More Manager Functions
#include "Passenger.h"
#include <iostream>

Passenger::Passenger() : seatNumber(0), firstName("Kayleb"), lastName("Cook")
{
    std::cout << "Passenger Default Constructor" << std::endl;

}
Passenger::Passenger(unsigned int seat, const String first, const String last) : seatNumber(seat), firstName(first), lastName(last)
{
    std::cout << "Passenger 3 Argument  Constructor" << std::endl;

}

Passenger::Passenger(const Passenger& other) : seatNumber(other.seatNumber) , firstName(other.firstName) , lastName(other.lastName)
{
    std::cout << "Passenger Copy Constructor" << std::endl;

}

Passenger& Passenger::operator=(const Passenger& other)
{
    if (this != &other)
        return *this;

    seatNumber = other.seatNumber;
    firstName = other.firstName;
    lastName = other.lastName;

    std::cout << "Passenger Copy Assignment" << std::endl;
    return *this;
}

Passenger::Passenger(Passenger&& other) noexcept
{
    std::cout << "Passenger Move Constructuor" << std::endl;
}

Passenger& Passenger::operator=(Passenger&& other) noexcept
{
    if (this != &other)
        return *this;

    seatNumber = other.seatNumber;
    firstName = other.firstName;
    lastName = other.lastName;

    std::cout << "Passenger Move Assignment" << std::endl;
    return *this;
}

Passenger::~Passenger()
{
    std::cout << "Passenger Destructor" << std::endl;
}
