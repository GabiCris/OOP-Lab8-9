#include "UI.h"
#include <algorithm>

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
		if (cmd == "delete")
		{
			this->deleteUi();
		}
		if (cmd == "update")
		{
			this->updateUi();
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
	this->ctrl.addMovieCtrl(Movie{ title, genre, year, likes, trailer });
}

void UI::listUi()
{	//TODO SORT
	//std::sort(this->ctrl.getRepo().getList().begin(), this->ctrl.getRepo().getList().end());
	for (auto s : ctrl.getMovies())
		s.printMovie();
}

void UI::deleteUi()
{
	std::string title;
	std::cout << "Title of Movie: ";
	std::cin >> title;
	ctrl.deleteMovieCtrl(title);


}

void UI::updateUi()
{
	std::string title, newT, newG, yr, lik, tr;
	std::cout << "Movie title to be updated: ";
	std::cin >> title;
	std::cout << "New Movie title: ";
	std::cin >> newT;
	std::cout << "New Movie Genre: ";
	std::cin >> newG;
	std::cout << "New Year of Release: ";
	std::cin >> yr;
	std::cout << "New No. of likes:";
	std::cin >> lik;
	std::cout << "New Movie Trailer: ";
	std::cin >> tr;
	ctrl.updateMovieCtrl(title, newT, newG, yr, lik, tr);

}

std::string UI::getCommand()
{
	std::cout << "Your wish is my command: ";
	std::string cmd;
	std::cin >> cmd;
	return cmd;
}
