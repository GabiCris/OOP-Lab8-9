#include "UI.h"


int main()
{
	moviesRepo repo = moviesRepo();
	repo.initRepo();
	
	//repo.moviesList.push_back(Movie{ "as", "asa", 2, 3, "asas" });
	std::cout << repo.getList().size();
	//std::cout << repo.getList()[0].getTitle();
	
	moviesCtrl ctrl = moviesCtrl();
	ctrl.setRepo(repo);
	std::cout << ctrl.getRepo().moviesList.size();
	UI u = UI();
	u.setUI(ctrl);
	std::cout << u.getCtrl().getRepo().moviesList.size();
	u.appStart();
	return 0;
}