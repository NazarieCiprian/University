#ifndef EXAMENPRACTIC_H
#define EXAMENPRACTIC_H

#include <QtWidgets/QMainWindow>
#include "ui_examenpractic.h"
#include "Repository.h"
class examenpractic : public QMainWindow
{
	Q_OBJECT

public:
	examenpractic(Repository& repo,Programmer p,QWidget *parent = 0);
	~examenpractic();

private:
	Ui::examenpracticClass ui;
	Repository& repo;
	Programmer prog;
};

#endif // EXAMENPRACTIC_H
