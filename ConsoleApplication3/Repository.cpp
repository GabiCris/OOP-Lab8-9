#include "Repository.h"
#include <assert.h>
#include <algorithm>

DynamicVector<Movie> moviesRepo::getList()
{
	return this->moviesL;
}

void moviesRepo::addMovie(const Movie& m)
{
	this->moviesL.add(m);
	//std::sort(this->repo.MoviesL.begin(), this->ctrl.getRepo().getList().end());
}

void moviesRepo::initRepo()
{
	this->addMovie(Movie{ "HP1","Fantasy",2003, 53000, "www.yt.com/hp1" });
	this->addMovie(Movie{ "HP2","Fantasy",2004, 80000, "www.yt.com/hp2" });
	this->addMovie(Movie{ "HP3","Fantasy",2006, 91000, "www.yt.com/hp3" });
	this->addMovie(Movie{ "IndianaJones","Adventure",2002, 43251, "www.yt.com/IndiJ" });
	this->addMovie(Movie{ "Pan'sLabyrinth","Fantasy",2006, 21987, "www.yt.com/pan" });
	this->addMovie(Movie{ "LaLaLand","Drama",2017, 200000, "www.yt.com/lala23" });
}

void moviesRepo::deleteMovie(const std::string title)
{
	int i, j;
	for ( i=0; i < moviesL.getSize(); i++)
		if (title == moviesL[i].getTitle())
			break;
	for (j = i; j < moviesL.getSize()-1; j++)
	{
		moviesL[j] = moviesL[j + 1];
	}
	moviesL.deleteLast();
			
}

void moviesRepo::updateMovieRepo(const std::string title, const std::string newTitle, const std::string newGenre, const std::string newYear, const std::string newLikes, const std::string newTrailer)
{
	int i;
	for (i=0; i<moviesL.getSize(); i++)
		if (moviesL[i].getTitle() == title)
		{
			break;
		}
	moviesL[i].updateMovie(newTitle, newGenre, newYear, newLikes, newTrailer);
}

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
