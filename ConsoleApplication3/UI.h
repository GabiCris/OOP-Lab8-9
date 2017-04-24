#pragma once
#include "Controller.h"

class UI
{
private:
	moviesCtrl ctrl;
public:
	UI (const moviesCtrl& c): ctrl(c) {}

	void appStart();

	void addUi();

	void listUi();

	void deleteUi();

	void updateUi();

	std::string getCommand();
};