#ifndef PROGRAMMERWINDOW_H
#define PROGRAMMERWINDOW_H

#include <QWidget>
#include "ui_programmerwindow.h"
#include "Repository.h"
#include <qmessagebox.h>
#include "Observer.h"
#include <Qfont>
class ProgrammerWindow : public QWidget,public Observer
{
	Q_OBJECT

public:
	ProgrammerWindow(Repository& r,Programmer p,QWidget *parent = 0);
	~ProgrammerWindow();

	void update()override;

private:
	Ui::ProgrammerWindow ui;
	Repository& repo;
	Programmer prog;
	vector<SourceFile> files;
	void populateList();
	void connectSignalsAndSlots();
	int getSelectedIndex();


	private slots:
	void addFile();
	void reviseFile();
};

#endif // PROGRAMMERWINDOW_H
