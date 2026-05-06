//Name: Kayleb Cook
//Programming Assignment: Lab Eight: STL
#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


class Movies
{
public: 
	std::string title;
	float rating;
	int year;
	std::string certifications;
	std::string genre;
	std::string director;	
	std::string cast;
	float metascore;
	float length;  //length in minutes 

	Movies(const std::string& T , float R , int Y , const std::string& Ce , const std::string& G , const std::string& D , const std::string& Ca , float M , float L);
	
	Movies();                                    //default ctor
	Movies(const Movies& other);                 //copy ctor
	Movies(Movies&& other) noexcept;             //move ctor
	Movies& operator=(const Movies& other);      //copy assignment
	Movies& operator=(Movies&& other) noexcept;  //move assignment
	~Movies();                                   //dtor
};

std::vector<Movies> readMovies(const std::string& file);
void displayMovies(const std::vector<Movies>& movies);

#endif
