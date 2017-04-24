#include "ListCtrl.h"

void listCtrl::add(const Movie & m)
{
	watchRepo.addMovieList(m);
}

void listCtrl::del(const std::string title)
{
	this->watchRepo.deleteMovieList(title);
}

DynamicVector<Movie> listCtrl::getList()
{
	return this->watchRepo.getList();
}
