// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Bird.h"

Bird::Bird(const std::string& species) : Animal(species)
{
}

Bird::Bird() : Animal("Bird")
{
}

Bird::~Bird()
{
}

Bird& Bird::operator=(const Bird& other)
{
	if (this != &other)
	{
		Animal::operator = (other);
	}
	return *this;
}

Bird::Bird(const Bird& copy) : Animal(copy)
{
}

Bird& Bird::operator=(Bird&& other) noexcept
{
	if (this != &other)
	{
		Animal::operator = (static_cast<Bird&&>(other));
	}
	return *this;
}

Bird::Bird(Bird&& copy) noexcept : Animal(std::move(copy))
{
}

void Bird::WhatAmI() const
{
	std::cout << "I am an " << GetSpecies() << std::endl;
}
