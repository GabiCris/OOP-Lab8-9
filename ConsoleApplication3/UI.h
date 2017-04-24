#pragma once
#include "Controller.h"
#include "ListCtrl.h"

class UI
{
private:
	moviesCtrl ctrl;
	listCtrl watchCtrl;
public:
	UI (const moviesCtrl& c, const listCtrl& w): ctrl(c),watchCtrl(w) {}

	void appStart();

	void addUi();

	void listUi();

	void deleteUi();

	void updateUi();
	
	void taskA();

	void listWatchList();

	void deleteWatchList();

	std::wstring s2ws(const std::string& s);

	std::string getCommand();
};