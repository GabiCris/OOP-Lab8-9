#include "Domain.h"

Movie::Movie(std::string title, std::string genre, int year, int likes, std::string trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

void Movie::printMovie()
{
	std::cout << "Title: " << this->getTitle() << "; Genre: " << this->getGenre() << "; Year: "
		<< this->getYear() << "; Likes: " << this->getLikes() << "; Trailer: "
		<< this->getTrailer() << ";\n";
}

std::string Movie::getTitle()
{
	return this->title;
}

std::string Movie::getGenre()
{
	return this->genre;
}

std::string Movie::getTrailer()
{
	return this->trailer;
}

int Movie::getYear()
{
	return this->year;
}

int Movie::getLikes()
{
	return this->likes;
}
