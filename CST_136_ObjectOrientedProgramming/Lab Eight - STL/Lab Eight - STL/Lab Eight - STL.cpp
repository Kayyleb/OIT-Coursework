//Name: Kayleb Cook
//Programming Assignment: Lab Eight: STL
//Source: Kaggle. (n.d.). IMDb movies dataset (2024 updated) https://www.kaggle.com/datasets/parthdande/imdb-dataset-2024-updated

#include "Movies.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);           //checking for memory leaks
	const std::string File = "C://Mac//Home//Downloads//IMDb_Dataset.csv";  //giving our filename a name "File"
	auto movies = readMovies(File);                                         //"auto" sets its own data type that the compiler will find most effective
	                                                                        //then sets "movies" to the data we just read in

	displayMovies(movies);                                                  //call our display function with all the data we just read in as a parameter

	return 0;
}
