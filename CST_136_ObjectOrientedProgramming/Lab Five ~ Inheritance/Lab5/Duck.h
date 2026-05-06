// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#ifndef _DUCK_H
#define _DUCK_H

#include "Bird.h"
#include <iostream>

class Duck : public Bird
{
public:
	explicit Duck(const std::string& species);

	Duck();
	~Duck();
	Duck& operator = (const Duck& rhs);
	Duck(const Duck& copy);
	Duck& operator = (Duck&& rhs) noexcept;
	Duck(Duck&& copy) noexcept;
	void WhatAmI() const override;

};
#endif
