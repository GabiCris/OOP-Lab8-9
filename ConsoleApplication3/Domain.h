#pragma once
#include <string>
#include <iostream>

class Movie
{
public:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;

	bool operator==(const Movie& m);

//public:
	Movie();
	Movie(const std::string& title, const std::string& genre, int year, int likes, const std::string& trailer);
	void printMovie();

	std::string getTitle() const { return this->title; }
	std::string getGenre() const { return this->genre; }
	std::string getTrailer()const { return this->trailer; }
	int getYear()const { return this->year; }
	int getLikes() const { return this->likes; }

	void updateMovie(const std::string& newTitle, const std::string& newGenre, const std::string& newYear, const std::string& newLikes, const std::string& newTrailer);

	bool operator < (Movie m);

	void incLikes() { this->likes++; }

};
