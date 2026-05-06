// Name: Kayleb Cook
// Programming Assignment: Lab 5 ~ Inheritance

#include <iostream>
#include "Mammal.h"
#include "Elk.h"
#include "Otter.h"
#include "Bird.h"
#include "Duck.h"
#include "Platypus.h"


int main()
{
	// Question 1
	Mammal m;
	Elk cow;
	Elk bull(3);
	Otter river(false);

	// Question 2
	m.WhatAmI();
	cow.WhatAmI();
	bull.WhatAmI();
	river.WhatAmI();
	std::cout << "\n" << std::endl; // for readability for me

	// Question 3
	m = bull;

	// Question 4
	m.WhatAmI();
	std::cout << "\n" << std::endl; // for readability for me

	//Question 5
	//Elk elkBull(bull);

	// Question 6
	Mammal mamBull(bull);

	//Question 7
	Mammal* mamArr[3];
	mamArr[0] = new Mammal;
	mamArr[1] = new Elk;
	mamArr[2] = new Otter;
	for (int e = 0; e < 3; e++)
	{
		mamArr[e]->WhatAmI();
	}
	std::cout << "\n" << std::endl; // for readability for me

	// Question 8
	for (int e = 0; e < 3; e++)
	{
		delete mamArr[e];
	}

	// Question 9
	std::cout << "Mammal Size: " << sizeof(Mammal) << std::endl;

	// Question 10
	std::cout << "Elk Size: " << sizeof(Elk) << std::endl;

	// Question 16
	std::cout << "Animal Size: " << sizeof(Animal) << std::endl;
	std::cout << "\n" << std::endl; // for readability for me

	// Question 20
	Animal* Arr[4];
	Arr[0] = new Mammal;
	Arr[1] = new Mammal;
	Arr[2] = new Elk;
	Arr[3] = new Otter;
	for (int e = 0; e < 4; e++)
	{
		Arr[e]->WhatAmI();
	}
	std::cout << "\n" << std::endl; // for readability for me
	// Deleting Pointers: 
	for (int e = 0; e < 4; e++)
	{
		delete Arr[e];
	}

	// Question 25
	Animal* Arr2[6];
	Arr2[0] = new Mammal;
	Arr2[1] = new Mammal;
	Arr2[2] = new Elk;
	Arr2[3] = new Otter;
	Arr2[4] = new Bird;
	Arr2[5] = new Duck;
	for (int e = 0; e < 6; e++)
	{
		Arr2[e]->WhatAmI();
	}
	std::cout << "\n" << std::endl; // for readability for me
	// Deleting Pointers: 
	for (int e = 0; e < 6; e++)
	{
		delete Arr2[e];
	}

	Animal* Arr3[7];
	Arr3[0] = new Mammal;
	Arr3[1] = new Mammal;
	Arr3[2] = new Elk;
	Arr3[3] = new Otter;
	Arr3[4] = new Bird;
	Arr3[5] = new Duck;
	Arr3[5] = new Platypus;
	for (int e = 0; e < 7; e++)
	{
		Arr3[e]->WhatAmI();
	}
	std::cout << "\n" << std::endl; // for readability for me
	// Deleting Pointers: 
	for (int e = 0; e < 7; e++)
	{
		delete Arr3[e];
	}

	return 0;
}