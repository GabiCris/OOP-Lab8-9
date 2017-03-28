#pragma once
#include <vector>
#include "Domain.h"

class moviesRepo
{
private:
	
public:
	std::vector<Movie> moviesList;
	std::vector<Movie> getList();

	void addMovie(Movie m);

	void initRepo();

	void deleteMovie(Movie m);
};
