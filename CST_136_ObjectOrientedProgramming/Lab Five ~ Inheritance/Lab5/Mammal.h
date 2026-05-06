// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _MAMMAL_H
#define _MAMMAL_H

#include "Animal.h"
#include <string>

using std::string;

class Mammal : public Animal
{
public:
	 explicit Mammal(const std::string& species);
	 virtual ~Mammal();

	 Mammal();                                     // default ctor
	 Mammal(const Mammal& other);                  // copy ctor
	 Mammal(Mammal&& other) noexcept;              // move ctor
	 Mammal & operator = (const Mammal & rhs);     // copy assignment
	 Mammal& operator = (Mammal&& rhs) noexcept;   // move assignment

	 void WhatAmI() const override;
};
#endif
