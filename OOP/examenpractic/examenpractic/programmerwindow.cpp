#include "programmerwindow.h"

ProgrammerWindow::ProgrammerWindow(Repository& r,Programmer p,QWidget *parent)
	: repo(r),prog(p),QWidget(parent)
{
	ui.setupUi(this);
	this->repo.addObserver(this);
	this->setWindowTitle(QString::fromStdString(prog.getName()));
	this->files = this->repo.getFiles();
	this->populateList();
	this->connectSignalsAndSlots();
}

ProgrammerWindow::~ProgrammerWindow()
{
	this->repo.removeObserver(this);
}

void ProgrammerWindow::update()
{
	this->files = this->repo.getFiles();
	this->populateList();
}

void ProgrammerWindow::populateList()
{
	if (ui.filesList->count() > 0)
		ui.filesList->clear();
	for (auto it : this->files)
	{
		QString itemInList = QString::fromStdString(it.getName() + "," + it.getStatus() + "," + it.getFCreator() + "," + it.getReviser());
		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		if (it.getStatus() == "revised")
		{
			//item->setFont(0,QFont::bold);
			item->setTextColor(Qt::green);
		}
		ui.filesList->addItem(item);
	}

	if (ui.filesList->count() > 0)
		ui.filesList->setCurrentRow(0);
	ui.toRevise->setText(QString::number(prog.getTotalFile() - prog.getNrRevised()));
	ui.revised->setText(QString::number(prog.getNrRevised()));
}

void ProgrammerWindow::connectSignalsAndSlots()
{
	QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addFile()));
	QObject::connect(ui.reviseButton, SIGNAL(clicked()), this, SLOT(reviseFile()));
}

int ProgrammerWindow::getSelectedIndex()
{
	if (ui.filesList->count() == 0)
		return -1;
	QModelIndexList index = ui.filesList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
		return -1;
	int idx = index.at(0).row();
	return idx;
}

void ProgrammerWindow::reviseFile()
{
	int idx = this->getSelectedIndex();
	if (idx >= this->files.size())
		return;

	SourceFile file = this->files[idx];
	if (file.getStatus() == "not_revised"&& prog.getName() != file.getFCreator())
	{
		file.setStatus("revised");
		file.setReviser(prog.getName());
		try
		{
			this->repo.updateFile(file);
			this->files = this->repo.getFiles();
			this->populateList();
			prog.setNrRevised(prog.getNrRevised() + 1);
			ui.revised->setText(QString::number(prog.getNrRevised()));
			ui.toRevise->setText(QString::number(prog.getTotalFile() - prog.getNrRevised()));
			
		}
		catch (Exception& e)
		{
			QMessageBox messagebox;
			messagebox.critical(0, "Error", QString::fromStdString(e.getMessage()));
		}
	}
	if (prog.getTotalFile() - prog.getNrRevised() == 0)
	{
		QMessageBox messagebox;
		messagebox.information(0, "Congratulations", "You have revised all your files!");
	}
}

void ProgrammerWindow::addFile()
{
	string file;
	if (ui.nameLineEdit->text().isEmpty())
	{
		QMessageBox messagebox;
		messagebox.critical(0, "Error", "Please enter a name");
	}
	else
	{
		file = ui.nameLineEdit->text().toStdString();
		SourceFile f{ file,"not_revised",prog.getName(),"-" };
		try
		{
			this->repo.addFile(f);
			this->files = this->repo.getFiles();
			this->populateList();
		}
		catch (Exception& e)
		{
			QMessageBox messagebox;
			messagebox.critical(0, "Error", QString::fromStdString(e.getMessage()));
		}
	}
}