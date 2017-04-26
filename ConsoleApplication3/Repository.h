#pragma once
#include <vector>
#include "Domain.h"
#include "Vector.h"

class moviesRepo
{
private:
	std::vector<Movie> moviesList;
	DynamicVector<Movie> moviesL;
public:
		
	std::vector<Movie> getList() { return this->moviesList; }
	/*
	Takes as param a movie and adds it to the vector of Movies.
	m - has to be of valid Movie type.
	*/
	void addMovie(const Movie& m);
	/*
	Initialises Repo vector with entries of movies for testing!
	*/
	void initRepo();
	/*
	Takes as parameters a string. Finds the movie in the vector with the specific
	title and then, deletes it by overwriting the over entries in the vector with the ones
	on the next posiitons.
	*/
	bool deleteMovie(const std::string title);

	void increaseLike(const std::string tit);

	/*
	Takes as parameter a title of a movie in the VectorList, finds that movie and then
	updates the movie with the string given by the user.
	The update of the movie is made by calling te updateMovie method of the Movie class.
	*/
	void updateMovieRepo(const std::string title, const std::string newTitle, const std::string newGenre, const std::string newYear, const std::string newLikes, const std::string newTrailer);
};

//void testRepo();
