#include "Repository.h"
#include <assert.h>
#include <algorithm>


void moviesRepo::addMovie(const Movie& m)
{
	this->moviesList.push_back(m);
}

void moviesRepo::initRepo()
{
	this->addMovie(Movie{ "HP1","Fantasy",2003, 53000, "https://www.youtube.com/watch?v=rKjqZH4XQiY" });
	this->addMovie(Movie{ "HP2","Fantasy",2004, 80000, "https://www.youtube.com/watch?v=bq7OxqAiieA" });
	this->addMovie(Movie{ "HP3","Fantasy",2006, 91000, "https://www.youtube.com/watch?v=3IRpfht3X50" });
	this->addMovie(Movie{ "IndianaJones","Adventure",2002, 43251, "https://www.youtube.com/watch?v=PoscTUBavms" });
	this->addMovie(Movie{ "Pan'sLabyrinth","Fantasy",2006, 21987, "https://www.youtube.com/watch?v=h2VbU22H1g8" });
	this->addMovie(Movie{ "LaLaLand","Drama",2017, 200000, "https://www.youtube.com/watch?v=_gx-GwyQVMs" });
}

bool moviesRepo::deleteMovie(const std::string title)
{
	bool exist = false;
	Movie m;
	for (auto s: this->moviesList)
		if (s.getTitle() == title)
		{
			moviesList.erase(std::remove(moviesList.begin(), moviesList.end(), s), moviesList.end());
			return true;
		}
	if (!exist)
		return false;
			
}

void moviesRepo::increaseLike(const std::string tit)
{

	for (auto s : moviesList)
		if (s.getTitle() == tit)
			s.incLikes();
}

void moviesRepo::updateMovieRepo(const std::string title, const std::string newTitle, const std::string newGenre, const std::string newYear, const std::string newLikes, const std::string newTrailer)
{
	for (auto s: moviesList)
		if (s.getTitle() == title)
			s.updateMovie(newTitle, newGenre, newYear, newLikes, newTrailer);
}
/*
void testRepo()
{
	moviesRepo repo{};
	repo.initRepo();
	assert(repo.getList().getSize() == 6);
	repo.deleteMovie("HP3");
	assert(repo.getList().getSize() == 5);
	repo.deleteMovie("HP2");
	assert(repo.getList().getSize() == 5);

	//repo.updateMovieRepo("HP1", "t", "t", "1", "1", "t");
	//assert(repo.moviesL[0].getTitle == "t");
}
*/