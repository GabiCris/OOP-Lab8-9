#pragma once
#include "ListRepo.h"

class listCtrl {
private:
	listRepo watchRepo;
public:
	listCtrl(const listRepo& r) : watchRepo(r){}
	
	void add(const Movie& m);

	void del(const std::string title);

	DynamicVector<Movie> getList();
};