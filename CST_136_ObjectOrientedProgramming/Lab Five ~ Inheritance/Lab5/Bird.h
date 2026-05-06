// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _BIRD_H
#define _BIRD_H

#include "Animal.h"
#include <iostream>

class Bird : public Animal
{
public:
	explicit Bird(const std::string& species);

	Bird();
	~Bird();
	Bird& operator = (const Bird& other);
	Bird(const Bird& copy);
	Bird& operator = (Bird&& other) noexcept;
	Bird(Bird&& copy) noexcept;
	void WhatAmI() const override;

};
#endif
