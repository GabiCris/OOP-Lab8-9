#include "Controller.h"



std::vector<Movie> moviesCtrl::getMovies()
{
	return this->repo.getList();
}

void moviesCtrl::addMovieCtrl(const Movie& m)
{
	//std::cout << getRepo().getList().getSize();
	repo.addMovie(m);
	//std::cout << getRepo().getList().getSize();
}

bool moviesCtrl::deleteMovieCtrl(const std::string& title)
{
	return this->repo.deleteMovie(title);
}

void moviesCtrl::updateMovieCtrl(const std::string title, const std::string newTitle, const std::string newGenre, const std::string newYear, const std::string newLikes, const std::string newTrailer)
{
	repo.updateMovieRepo(title, newTitle, newGenre, newYear, newLikes, newTrailer);
}
