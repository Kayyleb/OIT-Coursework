// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Mammal.h"

Mammal::Mammal(const std::string& species) : Animal(species)
{

}

Mammal::~Mammal()
{
}

Mammal & Mammal::operator = (const Mammal & rhs)
{
	if(this != &rhs)
	{
		Animal::operator=(rhs); // calls Animal's Assignment Operator
	}
	return *this;
}

Mammal::Mammal() : Animal("")
{
}

Mammal::Mammal(const Mammal & other) : Animal(other)
{
}

Mammal& Mammal::operator = (Mammal&& rhs) noexcept
{
	if (this != &rhs)
	{
		Animal::operator=(std::move(rhs)); // calls Animal's Move Assignment
	}
	return *this;
}

Mammal::Mammal(Mammal&& other) noexcept : Animal(std::move(other))
{
}


void Mammal::WhatAmI() const
{
	std::cout << "I am a Mammal" << std::endl;
}


