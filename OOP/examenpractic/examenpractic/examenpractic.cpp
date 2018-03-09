#include "examenpractic.h"

examenpractic::examenpractic(Repository& r,Programmer p,QWidget *parent)
	:repo(r),prog(p), QMainWindow(parent)
{
	ui.setupUi(this);
}

examenpractic::~examenpractic()
{

}
