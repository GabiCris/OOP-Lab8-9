#pragma once
#include "Repository.h"

class moviesCtrl
{
private:
	moviesRepo repo;
public:
	moviesCtrl(const moviesRepo& r) : repo(r) {}

	moviesRepo getRepo() const { return repo; }

	std::vector<Movie> getMovies();

	void incLikes(const std::string title) { this->repo.increaseLike(title); }

	void addMovieCtrl(const Movie& m);

	void deleteMovieCtrl(const std::string& title);

	void updateMovieCtrl(const std::string title, const std::string newTitle, const std::string newGenre, const std::string newYear, const std::string newLikes, const std::string newTrailer);
	
};