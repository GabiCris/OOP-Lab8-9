#include "Repository.h"

std::vector<Movie> moviesRepo::getList()
{
	return moviesList;
}

void moviesRepo::addMovie(Movie m)
{
	moviesList.push_back(m);
}

void moviesRepo::initRepo()
{
	this->addMovie(Movie{ "HP 1","Fantasy",2003, 53000, "www.yt.com/hp1" });
	this->addMovie(Movie{ "HP 2","Fantasy",2004, 80000, "www.yt.com/hp2" });
	this->addMovie(Movie{ "HP 3","Fantasy",2006, 91000, "www.yt.com/hp3" });
	this->addMovie(Movie{ "Indiana Jones","Adventure",2002, 43251, "www.yt.com/IndiJ" });
	this->addMovie(Movie{ "Pan's Labyrinth","Fantasy",2006, 21987, "www.yt.com/pan" });
	this->addMovie(Movie{ "La La Land","Drama",2017, 200000, "www.yt.com/lala23" });
}

void moviesRepo::deleteMovie(Movie m)
{
	return;
	/*auto it = find(this->moviesList.begin(), this->moviesList.end(), m);
	if (it != this->moviesList.end())
		this->moviesList.erase(it);*/
	
}
