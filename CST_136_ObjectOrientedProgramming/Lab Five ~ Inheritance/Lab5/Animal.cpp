// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include "Animal.h"

Animal::Animal(const std::string& species) : m_species(species)
{
}

Animal::Animal(const Animal& other) : m_species(other.m_species)
{
}

Animal::Animal(Animal&& other) noexcept : m_species(std::move(other.m_species))
{
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other) 
	{
		m_species = other.m_species;
	}
	return *this;
}

Animal& Animal::operator=(Animal&& other) noexcept
{
	if (this != &other) {
		m_species = std::move(other.m_species);
	}
	return *this;
}

Animal::~Animal()
{
}

const std::string Animal::GetSpecies() const
{
	return m_species;
}


void Animal::WhatAmI() const
{
	std::cout << "I am an Animal, Species: " << m_species << std::endl;
}