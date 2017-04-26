#include "UI.h"
#include <assert.h>

void test_repo()
{
	moviesRepo repo{};
	repo.initRepo();
	assert(repo.getList().size() == 6);
	repo.deleteMovie("HP1");
	assert(repo.getList().size() == 5);
	repo.deleteMovie("HP2");
	assert(repo.getList().size() == 4);
	repo.addMovie(Movie{ "HP1","Fantasy",2003, 53000, "https://www.youtube.com/watch?v=rKjqZH4XQiY" });
	assert(repo.getList().size() == 5);
	repo.updateMovieRepo("HP1", "HP100", "Fantasy", "2300", "53000", "https://www.youtube.com/watch?v=rKjqZH4XQiY");
	assert(repo.deleteMovie("asas") == false);

	repo.increaseLike("HP1");

	assert(repo.getList()[0] < repo.getList()[1] == true);
	assert(repo.getList()[0].getGenre() == "Fantasy");
	assert(repo.getList()[0].getLikes() == 91000);
	assert(repo.getList()[0].getYear() == 2006);
	assert(repo.getList()[0].getTrailer() == "https://www.youtube.com/watch?v=3IRpfht3X50");

	//assert(repo.getList()[4].getTitle() == "HP100");
}

void test_ctrl()
{
	moviesRepo repo{};
	repo.initRepo();
	moviesCtrl ctrl{ repo };
	ctrl.deleteMovieCtrl("HP1");
	std::vector<Movie> test = ctrl.getMovies();
	moviesRepo testRepo = ctrl.getRepo();
	ctrl.incLikes("HP2");
	ctrl.addMovieCtrl(Movie{ "HP1","Fantasy",2003, 53000, "https://www.youtube.com/watch?v=rKjqZH4XQiY" });
	ctrl.updateMovieCtrl("HP1", "HP100", "Fantasy", "2300", "53000", "https://www.youtube.com/watch?v=rKjqZH4XQiY");
}
void test_all()
{
	test_repo();
	test_ctrl();
}

int main()
{	
	test_all();
	/*
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
	*/

	return 0;
}