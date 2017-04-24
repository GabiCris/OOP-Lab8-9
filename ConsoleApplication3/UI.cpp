#include "UI.h"
#include <algorithm>
#include <windows.h>
#include <ShellApi.h>

void UI::appStart()
{
	std::cout << "Welcome to your favourite IMDB app!\n";
	bool alive = true;
	int choice;
	std::cout << "Enter 1 for Administrator Mode;\nEnter 2 for User Mode;\nMode:";
	std::cin >> choice;
	std::string cmd;

	if (choice == 1)
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
	else if (choice == 2)
		while (alive)
		{
			cmd = this->getCommand();
			if (cmd == "exit")
				alive = false;
			//task a
			if (cmd == "browse")
				taskA();

			if (cmd == "list")
				listWatchList();

			if (cmd == "delete")
				deleteWatchList();

		}
	else
	{
		std::cout << "Invalid option";
		exit(0);
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

void UI::taskA()
{
	int i, n= ctrl.getMovies().getSize();
	std::string genr, answer;
	std::cout << "Enter genre to browse by: ";
	std::getline(std::cin, genr);
	std::getline(std::cin, genr);
	
	if (genr != "")
	{
		for (i = 0; i < n; i++)
		{
			if (ctrl.getMovies()[i].getGenre() == genr)
			{
				ctrl.getMovies()[i].printMovie();
				s2ws(ctrl.getMovies()[i].getTrailer());
				ShellExecute(0, 0, s2ws(ctrl.getMovies()[i].getTrailer()).c_str(), 0, 0, SW_SHOW);
				std::cout << "Add movie to watch List? (y/n or stop): ";
				std::cin >> answer;
				if (answer == "y")
					this->watchCtrl.add(ctrl.getMovies()[i]);
				else if (answer == "stop")
					break;
			}
			else
			{
				i++;
			}
			if (i == n)
				i = -1;
		}
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			ctrl.getMovies()[i].printMovie();
			s2ws(ctrl.getMovies()[i].getTrailer());
			ShellExecute(0, 0, s2ws(ctrl.getMovies()[i].getTrailer()).c_str(), 0, 0, SW_SHOW);
			std::cout << "Add movie to watch List? (y/n or stop): ";
			std::cin >> answer;
			if (answer == "y")
				this->watchCtrl.add(ctrl.getMovies()[i]);
			else if (answer == "stop")
				break;
			if (i == n-1)
				i = -1;
		}

	}

}

void UI::listWatchList()
{
	for (auto s : watchCtrl.getList())
		s.printMovie();
}

void UI::deleteWatchList()
{
	std::string tit, like;
	std::cout << "Name of the movie watched: ";
	std::cin >> tit;
	this->watchCtrl.del(tit);
	std::cout << "Like the Movie? (y/n): ";
	std::cin >> like;
	if (like == "y")
		this->ctrl.incLikes(tit);
	else if (like != "n")
		std::cout << "invalid option! \n";

}

std::wstring UI::s2ws(const std::string & s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}


std::string UI::getCommand()
{
	std::cout << "Your wish is my command: ";
	std::string cmd;
	std::cin >> cmd;
	return cmd;
}
