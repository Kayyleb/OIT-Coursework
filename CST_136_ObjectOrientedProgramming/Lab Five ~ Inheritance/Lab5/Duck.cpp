// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Duck.h"

Duck::Duck(const std::string& species) : Bird(species)
{
}

Duck::Duck() : Bird("Duck")
{
}

Duck::~Duck()
{
}

Duck& Duck::operator=(const Duck& other)
{
	if (this != &other)
	{
		Bird::operator = (other);
	}
	return *this;
}

Duck::Duck(const Duck& copy) : Bird(copy)
{
}

Duck& Duck::operator=(Duck&& other) noexcept
{
	if (this != &other)
	{
		Bird::operator = (static_cast<Duck&&>(other));
	}
	return *this;
}

Duck::Duck(Duck&& copy) noexcept : Bird(std::move(copy))
{
}

void Duck::WhatAmI() const
{
	std::cout << "I am an " << GetSpecies() << std::endl;
}
