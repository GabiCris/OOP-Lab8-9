#include "Controller.h"


void moviesCtrl::setRepo(moviesRepo r)
{
	this->repo = r;
}

moviesRepo moviesCtrl::getRepo()
{
	return this->repo;
}

std::vector<Movie> moviesCtrl::getMovies()
{
	return this->repo.getList();
}

void moviesCtrl::addMovieCtrl(Movie m)
{
	std::cout << getRepo().moviesList.size();
	this->getRepo().addMovie(m);
	std::cout << getRepo().moviesList.size();
}

void moviesCtrl::deleteMovieCtrl(Movie m)
{
	this->getRepo().deleteMovie(m);
}
