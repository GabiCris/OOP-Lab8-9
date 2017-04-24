#include "UI.h"
#include <assert.h>
/*
void testRep()
{
	moviesRepo repo{};
	repo.initRepo();
	assert(repo.getList().getSize() == 6);
	repo.deleteMovie("HP1");
	assert(repo.getList().getSize() == 5);
	repo.deleteMovie("HP2");
	assert(repo.getList().getSize() == 4);
	repo.addMovie(Movie{ "HP1","Fantasy",2003, 53000, "https://www.youtube.com/watch?v=rKjqZH4XQiY" });
	assert(repo.getList().getSize() == 5);
	repo.updateMovieRepo("HP1", "HP100", "Fantasy", "2300", "53000", "https://www.youtube.com/watch?v=rKjqZH4XQiY");
	assert(repo.getList()[4].getTitle() == "HP100");
}
*/

int main()
{	
	//testRep();
	moviesRepo repo{};
	listRepo watchRepo{};
	repo.initRepo();
	//std::cout << repo.getList()[1].getTitle();
	
	//repo.moviesList.push_back(Movie{ "as", "asa", 2, 3, "asas" });
	//std::cout << repo.getList()->size();
	//std::cout << repo.getList()[0].getTitle();
	
	moviesCtrl ctrl{ repo };
	listCtrl watchCtrl{ watchRepo };
	//std::cout << ctrl.getRepo()->moviesList.size();
	UI u{ ctrl, watchCtrl };
	//std::cout << u.getCtrl()->getRepo()->moviesList.size();
	u.appStart();
	return 0;
}