#pragma once
#include<vector>
#include <algorithm>
#include "Controller.h"
#include "Repository.h"
#include <QtWidgets/qmainwindow.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qradiobutton.h>
#include <QtWidgets/qmessagebox.h>
#include <QtWidgets/qbuttongroup.h>
class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(Controller* c,QWidget* parent = 0);
	//GUI(QWidget* parent = 0);
	~GUI();

private:
	QListWidget* coats;
	QListWidget* cart;
	QListWidget* filtered;
	QListWidget* sorted;
	QLineEdit* sizeEdit;
	QLineEdit* colourEdit;
	QLineEdit* quantityEdit;
	QLineEdit* priceEdit;
	QLineEdit* photoEdit;
	QLineEdit* filterEdit;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* filterButton;
	QPushButton* buyButton;
	QRadioButton* shuffleButton;
	QRadioButton* sortedButton;
	QPushButton* billButton;
	QPushButton* saveButton;
	void initGUI();
	void populateRepoList();
	void populateSorted(vector<TrenchCoat> v);
	void populateFiltered(vector<TrenchCoat> v);
	void populateCart(vector<TrenchCoat> v);
	void connectSignalAndSlots();
	int getCoatsSelectionIndex();
	int getFilteredSelectionIndex();
	
	Controller* ctrl;
	vector<TrenchCoat> allInRepo;
	vector<TrenchCoat> filteredCoats;

	private slots:
	void listItemChanged();
	void sortList();
	void shuffleList();
	void addNewCoat();
	void deleteCoat();
	void updateCoat();
	void filterSize();
	void getCart();
	void showBill();
	void saveToFile();

};
