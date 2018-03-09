#include "examenpractic.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "programmerwindow.h"
int main(int argc, char *argv[])
{
	testRepo();
	QApplication a(argc, argv);
	Repository repo{ "files.txt" };
	//Programmer p{ "john",10,11 };
	//examenpractic w{ repo,p };
	//w.show();
	vector<Programmer> programmers = repo.getProgrammers();
	vector<ProgrammerWindow*>windows;
	for (auto it : programmers)
	{
		ProgrammerWindow* prog = new ProgrammerWindow{ repo,it };
		windows.push_back(prog);
		prog->show();
	}
	
	return a.exec();
}
