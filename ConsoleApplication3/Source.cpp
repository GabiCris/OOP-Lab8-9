#include "UI.h"

int main()
{	
	//testRepo();
	moviesRepo repo{};
	repo.initRepo();
	std::cout << repo.getList()[1].getTitle();
	
	//repo.moviesList.push_back(Movie{ "as", "asa", 2, 3, "asas" });
	//std::cout << repo.getList()->size();
	//std::cout << repo.getList()[0].getTitle();
	
	moviesCtrl ctrl{ repo };
	//std::cout << ctrl.getRepo()->moviesList.size();
	UI u{ ctrl };
	//std::cout << u.getCtrl()->getRepo()->moviesList.size();
	u.appStart();
	//return 0;
}