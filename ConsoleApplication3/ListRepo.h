#pragma once
#include "Repository.h"

class listRepo {
private:
	//moviesRepo repo;
	DynamicVector<Movie> watchList;
public:
	void addMovieList(const Movie& m);

	DynamicVector<Movie> getList();

	void deleteMovieList(const std::string title);

};