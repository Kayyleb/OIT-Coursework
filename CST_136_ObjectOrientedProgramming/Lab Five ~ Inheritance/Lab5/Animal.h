// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
private: 
	std::string m_species;

public: 
    explicit Animal(const std::string& species);  // Constructor to initialize m_species

    Animal(const Animal& other);                  // Copy constructor
    Animal(Animal&& other) noexcept;              // Move constructor
    Animal& operator=(const Animal& other);       // Copy assignment operator
    Animal& operator=(Animal&& other) noexcept;   // Move assignment operator

    const std::string GetSpecies() const;
    virtual void WhatAmI() const = 0;

    // Destructor
    virtual ~Animal();
};

#endif