#include "Ui.h"
using namespace std;
int main()
{

	Controller c{};
	
	Ui ui{ c };
	
	ui.run();
	
	system("pause");
	return 0;
}