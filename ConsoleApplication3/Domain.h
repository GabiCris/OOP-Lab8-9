#pragma once
#include <string>
#include <iostream>

class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;

public:
	Movie(std::string title, std::string genre, int year, int likes, std::string trailer);
	void printMovie();

	std::string getTitle();

	std::string getGenre();

	std::string getTrailer();

	int getYear();

	int getLikes();

};
