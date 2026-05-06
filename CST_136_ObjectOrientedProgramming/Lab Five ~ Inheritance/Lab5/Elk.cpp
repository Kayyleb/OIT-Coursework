// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Elk.h"

Elk::Elk(const std::string& species) : Mammal(species)
{
}

Elk::Elk() :  Mammal("Elk"), m_points(0)
{
}

Elk::Elk(int points) :  Mammal("Elk"), m_points(points)
{
}

Elk::~Elk()
{
}

Elk & Elk::operator = (const Elk & rhs)
{
	if(this != &rhs)
	{
		Mammal::operator = (rhs);
		m_points = rhs.m_points;
	}
	return *this;
}

Elk::Elk(const Elk & other) : Mammal(other), m_points(other.m_points)
{
}

Elk& Elk::operator = (Elk&& rhs) noexcept
{
	if (this != &rhs)
	{
		Mammal::operator = (static_cast<Elk&&>(rhs));
		m_points = rhs.m_points;
	}
	return *this;
}

Elk::Elk(Elk&& other) noexcept : Mammal(static_cast<Elk&&>(other)), m_points(other.m_points)
{
	other.m_points = 0;
}

void Elk::WhatAmI() const

{
	std::cout << "I am an " << GetSpecies() << std::endl;
}
