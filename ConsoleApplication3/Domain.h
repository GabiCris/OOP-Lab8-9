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
	Movie();
	Movie(const std::string& title, const std::string& genre, int year, int likes, const std::string& trailer);
	void printMovie();

	const std::string getTitle();

	bool operator < (Movie m);

	std::string getGenre();

	std::string getTrailer();

	void updateMovie(const std::string& newTitle, const std::string& newGenre, const std::string& newYear, const std::string& newLikes, const std::string& newTrailer);

	int getYear();

	int getLikes();

	void incLikes() { this->likes++; }

};
