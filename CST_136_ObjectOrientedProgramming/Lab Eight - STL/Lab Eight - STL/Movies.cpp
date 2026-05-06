//Name: Kayleb Cook
//Programming Assignment: Lab Eight: STL
#include "Movies.h"

Movies::Movies() : title(""), rating(0), year(0), certifications(""), genre(""), director(""), cast(""), metascore(0), length(0)
{
}

Movies::Movies(const Movies& other)
	: title(other.title), rating(other.rating), year(other.year), certifications(other.certifications), genre(other.genre), director(other.director), cast(other.cast), metascore(other.metascore), length(other.length)
{
}

Movies::Movies(Movies&& other) noexcept : title(other.title), rating(other.rating), year(other.year), certifications(other.certifications), genre(other.genre), director(other.director), cast(other.cast), metascore(other.metascore), length(other.length)
{
	title = other.title;
	rating = other.rating;
	year = other.year;
	certifications = other.certifications;
	genre = other.genre;
	director = other.director;
	cast = other.cast;
	metascore = other.metascore;
	length = other.length;

	other.title.clear();
	other.rating = 0;
	other.year = 0;
	other.certifications.clear();
	other.genre.clear();
	other.director.clear();
	other.cast.clear();
	other.metascore = 0;
	other.length = 0;

	//this and my move operator dont actually move just copy, so see how to fix if we have time 
	//for strings we should do xxx = std::move(other.xxx)
}

Movies& Movies::operator=(const Movies& other)
{
	if (this != &other)
	{
		title = other.title;
		rating = other.rating;
		year = other.year;
		certifications = other.certifications;
		genre = other.genre;
		director = other.director;
		cast = other.cast;
		metascore = other.metascore;
		length = other.length;
	} return *this;
}

Movies& Movies::operator=(Movies&& other) noexcept
{
	if (this != &other)
	{
		//moving into destiniation
		title = other.title;
		rating = other.rating;
		year = other.year;
		certifications = other.certifications;
		genre = other.genre;
		director = other.director;
		cast = other.cast;
		metascore = other.metascore;
		length = other.length;

		//resetting where we moved from
		other.title.clear();
		other.rating = 0;
		other.year = 0;
		other.certifications.clear();
		other.genre.clear();
		other.director.clear();
		other.cast.clear();
		other.metascore = 0;
		other.length = 0;
	} return *this;
}

Movies::Movies(const std::string& T, float R, int Y, const std::string& Ce, const std::string& G, const std::string& D, const std::string& Ca, float M, float L)
	: title(T) , rating(R) , year(Y) , certifications(Ce) , genre(G) , director(D) , cast(Ca) , metascore(M) , length(L)
{
}



Movies::~Movies()
{
}

std::vector<Movies> readMovies(const std::string& FILE)
{
	std::vector<Movies> movies; 
	std::ifstream file(FILE);
	std::string line;

	//vector: manages its own size automatically, when something is added, it'll grow and when something is removed it'll shrink, 
	// also will only dynamically allocate memory as needed. Random Acess, so easier to access items by position

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << FILE << std::endl;
		return movies;
	}

	std::getline(file, line); // putting this outside the loop will 'getline' the header name, and not include it in the reading
	while (std::getline(file, line))
	{
		std::stringstream SS(line);
		//stringstream: does the same thing as cin and cout, but allows you to do inputs and outputs on strings as well
	
		// Data we're reading in: 
		std::string title;
		float rating;
		int year;
		std::string certifications;
		std::string genre;
		std::string director;
		std::string cast;
		float metascore;
		float length;

		std::getline(SS, title, ','); // this will input the title, then stop reading when it encounters the comma
		SS >> rating; // reads in the number
		SS.ignore();  // ignores the comma
		SS >> year;   // reads the next thing, in this case a number
		SS.ignore();  // then ignores the comma, and so on downwards
		std::getline(SS, certifications, ',');
		std::getline(SS, genre, ',');
		std::getline(SS, director, ',');
		std::getline(SS, cast, ',');
		SS >> metascore;
		SS.ignore();
		SS >> length;
		SS.ignore();
		
		// My comments: we use getline for strings for when we encounter titles with multiple words so that it can read in everything until it hits a comma so it knows when to move on
		// For more simple data, such as floats and ints we use SS >> as imput to take in whats next to be read, then we use SS.ignore to ignore the comma. 
		// We do this because ratings, year, etc. wont have multiple numbers and can just be read in as is. 

		movies.emplace_back(title, rating, year, certifications, genre, director, cast, metascore, length);
	}
	return movies;
}

void displayMovies(const std::vector<Movies>& movies)
{
	// Display headers
	std::cout << "Title , Rating , Year , Certifications , Genre , Director , Cast , Metascore , Length" << std::endl;
	// Display data
	for (const auto& movie : movies)
	{
		std::cout 
			<< movie.title << " | "
			<< movie.rating << " | "
			<< movie.year << " | "
			<< movie.certifications << " | "
			<< movie.genre << " | "
			<< movie.director << " | "
			<< movie.cast << " | "
			<< movie.metascore << " | "
			<< movie.length << "\n" 
			<< std::endl;
			
	}
}
