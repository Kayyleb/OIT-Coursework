// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _ELK_H
#define _ELK_H

#include "Mammal.h"

class Elk : public Mammal
{
public:
	explicit Elk(const std::string& species);
	
	 Elk();
	 Elk(int points);
	 ~Elk();
	 Elk & operator = (const Elk & rhs);
	 Elk(const Elk & copy);
	 Elk& operator = (Elk&& rhs) noexcept;
	 Elk(Elk&& copy) noexcept;
	 void WhatAmI() const override;
protected:
	int m_points;
};
#endif
