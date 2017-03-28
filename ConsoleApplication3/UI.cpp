#include "UI.h"


void UI::setUI(moviesCtrl c)
{
	this->ctrl = c;
}

moviesCtrl UI::getCtrl()
{
	return this->ctrl;
}

void UI::appStart()
{
	std::cout << "Welcome to your favourite IMDB app!\n";
	bool alive = true;
	std::string cmd;
	while (alive)
	{
		cmd = this->getCommand();
		if (cmd == "exit")
			alive = false;
		if (cmd == "add")
		{
			this->addUi();
		}
		if (cmd == "list")
		{
			this->listUi();
		}
	}
}

void UI::addUi()
{
	std::string genre, title, trailer;
	int year, likes;
	std::cout << "Movie title: ";
	std::cin >> title;
	std::cout << "Movie Genre: ";
	std::cin >> genre;
	std::cout << "Year of Release: ";
	std::cin >> year;
	std::cout << "No. of likes:";
	std::cin >> likes;
	std::cout << "Movie Trailer: ";
	std::cin >> trailer;
	this->getCtrl().addMovieCtrl(Movie{ title, genre, year, likes, trailer });
}

void UI::listUi()
{
	for (auto s : this->getCtrl().getMovies())
		s.printMovie();
}

std::string UI::getCommand()
{
	std::cout << "Your wish is my command: ";
	std::string cmd;
	std::cin >> cmd;
	return cmd;
}
