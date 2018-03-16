#include "Plate.h"
#include "RepoSet.h"
#include "Ui.h"
#include "tests.h"
using namespace std;

int main()
{
	
	testPlate();
	testRepo();
	//testIterator();
	testValidator();
	Set *repo = new Set{};
	Plate a{ "SV",10,"LAL" };
	Plate b{ "SV",87,"TZU" };
	Plate c{ "SV",11,"LAL" };
	Plate d{ "SV",82,"TZU" };
	Plate e{ "SV",13,"LAL" };
	Plate f{ "SV",84,"TZU" };
	Plate g{ "SV",14,"LAL" };
	Plate h{ "SV",85,"TZU" };
	Plate i{ "SV",23,"LAL" };
	Plate j{ "SV",44,"TZU" };
	repo->add(a);
	repo->add(b);
	repo->add(c);
	repo->add(d);
	repo->add(e);
	repo->add(f);
	repo->add(g);
	repo->add(h);
	repo->add(i);
	repo->add(j);
	Ui ui{ repo };
	ui.run();
	
	
	
	system("pause");
	return 0;

}