#pragma once
#include "Controller.h"

class UI
{
private:
	moviesCtrl ctrl;
public:
	void setUI(moviesCtrl c);

	moviesCtrl getCtrl();

	void appStart();

	void addUi();

	void listUi();


	std::string getCommand();
};