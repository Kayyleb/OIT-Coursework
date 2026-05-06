// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Otter.h"

Otter::Otter(const std::string& species) : Mammal(species) , m_sea(0)
{
}

Otter::Otter() : Mammal("Otter") , m_sea(0)
{
}

Otter::Otter(int sea) : Mammal("Otter"), m_sea(sea)
{
}

Otter::~Otter()
{
}

Otter& Otter::operator=(const Otter& other)
{
	if (this != &other) 
	{
		Mammal::operator = (other);
		m_sea = other.m_sea;
	}
	return *this;
}

Otter::Otter(const Otter& copy) : Mammal(copy), m_sea(copy.m_sea)
{
}

Otter& Otter::operator=(Otter&& other) noexcept
{
	if (this != &other)
	{
		Mammal::operator = (static_cast<Otter&&>(other));
		m_sea = other.m_sea;
	}
	return *this;
}

Otter::Otter(Otter&& copy) noexcept
{
	copy.m_sea = false;
}

void Otter::WhatAmI() const
{
	std::cout << "I am an " << GetSpecies() << std::endl;
}
