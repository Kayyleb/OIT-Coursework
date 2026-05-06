// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Platypus.h"

Platypus::Platypus(const std::string& species) : Otter(species)
{
}

Platypus::Platypus() : Otter("Platypus")
{
}

Platypus::~Platypus()
{
}

Platypus& Platypus::operator=(const Platypus& other)
{
	if (this != &other)
	{
		Otter::operator = (other);
	}
	return *this;
}

Platypus::Platypus(const Platypus& copy) : Otter(copy)
{
}

Platypus& Platypus::operator=(Platypus&& other) noexcept
{
	if (this != &other)
	{
		Otter::operator = (static_cast<Platypus&&>(other));
	}
	return *this;
}

Platypus::Platypus(Platypus&& copy) noexcept : Otter(std::move(copy))
{
}

void Platypus::WhatAmI() const
{
	std::cout << "I am an " << GetSpecies() << std::endl;
}
