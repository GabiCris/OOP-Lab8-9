#include "ListRepo.h"

void listRepo::addMovieList(const Movie & m)
{
	watchList.add(m);
}

DynamicVector<Movie> listRepo::getList()
{
	return this->watchList;
}

void listRepo::deleteMovieList(const std::string title)
{
	int i, j;
	for (i = 0; i < this->watchList.getSize(); i++)
		if (title == watchList[i].getTitle())
			break;
	for (j = i; j < this->watchList.getSize() - 1; j++)
	{
		watchList[j] = watchList[j + 1];
	}
	watchList.deleteLast();
}
