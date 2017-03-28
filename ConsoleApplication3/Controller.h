#pragma once
#include "Repository.h"

class moviesCtrl
{
private:
	moviesRepo repo;
public:
	void setRepo(moviesRepo r);

	moviesRepo getRepo();

	std::vector<Movie> getMovies();

	void addMovieCtrl(Movie m);

	void deleteMovieCtrl(Movie m);
	
};