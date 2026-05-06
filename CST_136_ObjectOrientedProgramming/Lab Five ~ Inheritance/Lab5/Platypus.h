// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _PLATYPUS_H
#define _PLATYPUS_H

#include "Otter.h"
#include <iostream>

class Platypus : public Otter
{
public:
	explicit Platypus(const std::string& species);

	Platypus();

	~Platypus();
	Platypus& operator = (const Platypus& rhs);
	Platypus(const Platypus& copy);
	Platypus& operator = (Platypus&& rhs) noexcept;
	Platypus(Platypus&& copy) noexcept;
	void WhatAmI() const override;

};
#endif
#pragma once
