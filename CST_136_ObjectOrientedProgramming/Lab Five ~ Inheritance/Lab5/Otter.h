// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _OTTER_H
#define _OTTER_H

#include "Mammal.h"
#include <iostream>

class Otter : public Mammal
{
public:
	explicit Otter(const std::string& species);
	Otter();
	Otter(int sea);
	~Otter();
	Otter& operator = (const Otter& other);
	Otter(const Otter& copy);
	Otter& operator = (Otter&& other) noexcept;
	Otter(Otter&& copy) noexcept;
	void WhatAmI() const override;

protected:
	bool m_sea;;
};
#endif
