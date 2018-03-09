#include "GUI.h"

GUI::GUI(Controller* c,QWidget* parent) :ctrl(c),QWidget{ parent } 
{
	this->initGUI();
	this->allInRepo = this->ctrl->getCoats();
	this->populateRepoList();
}

GUI::~GUI()
{
}

void GUI::initGUI()
{
	//set general layout
	QHBoxLayout* layout = new QHBoxLayout{ this };
	//set left side
	QWidget* leftwidget = new QWidget{};
	QVBoxLayout* leftside = new QVBoxLayout{ leftwidget };
	//set list from left side
	this->coats = new QListWidget{};
	this->coats->setSelectionMode(QAbstractItemView::SingleSelection);
	//create the layout and widget for each atribute
	QWidget* coatDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ coatDataWidget };

	this->sizeEdit = new QLineEdit{};
	this->colourEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	this->priceEdit = new QLineEdit{};
	this->photoEdit = new QLineEdit{};
	//add the data to form layout
	formLayout->addRow("&Size:", sizeEdit);
	formLayout->addRow("&Colour:", colourEdit);
	formLayout->addRow("&Quantity:", quantityEdit);
	formLayout->addRow("&Price", priceEdit);
	formLayout->addRow("&Photo", photoEdit);
	//create buttons for add update delete filter
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->saveButton = new QPushButton{ "Save" };
	this->addButton = new QPushButton{ "Add" };
	this->deleteButton = new QPushButton{ "Delete" };
	this->updateButton = new QPushButton{ "Update" };
	this->filterButton = new QPushButton{ "Filter" };
	//add the buttons to the layout
	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	gridLayout->addWidget(filterButton, 0, 3);
	gridLayout->addWidget(saveButton, 1, 0);
	//add the widgets created so far to the left side layout
	leftside->addWidget(new QLabel{ "All coats" });
	leftside->addWidget(coats);
	leftside->addWidget(coatDataWidget);
	leftside->addWidget(buttonsWidget);
	//create the middle section layout 
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* middleSide = new QVBoxLayout{ middleWidget };
	// create the filtered list
	this->filtered = new QListWidget{};
	this->filtered->setSelectionMode(QAbstractItemView::SingleSelection);
	//create layout for the list
	QWidget* filterDataWidget = new QWidget{};
	QFormLayout* formLayout2 = new QFormLayout{filterDataWidget};
	this->filterEdit = new QLineEdit{};
	formLayout2->addRow("&Size:", filterEdit);
	//add the widgets to the middle layout
	middleSide->addWidget(new QLabel{ "Filtered by size" });
	middleSide->addWidget(filtered);
	middleSide->addWidget(filterDataWidget);
	//create the layout for right side
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };
	//create list
	cart = new QListWidget{};
	//create the button
	QWidget* cartButtonWidget = new QWidget{};
	QHBoxLayout* cartButtonLayout = new QHBoxLayout{cartButtonWidget};

	QWidget* cartButtonWidget1 = new QWidget{};
	QHBoxLayout* cartButtonLayout1 = new QHBoxLayout{ cartButtonWidget1 };
	this->billButton = new QPushButton{ "Bill" };
	this->buyButton= new QPushButton("Buy");
	cartButtonLayout->addWidget(buyButton);
	cartButtonLayout1->addWidget(billButton);
	//add the widgets to the right side layout
	rightSide->addWidget( new QLabel{"Cart"} );
	rightSide->addWidget(cart);
	rightSide->addWidget(cartButtonWidget);
	rightSide->addWidget(cartButtonWidget1);

	//create the widget and layout for the sorted
	QWidget* rightWidget2 = new QWidget{};
	QVBoxLayout* rightSide2 = new QVBoxLayout{ rightWidget2 };
	sorted = new QListWidget{};
	//create 2 radio buttons 1 for sort one for shuffle
	QButtonGroup * buttonGroup = new QButtonGroup{};
	QWidget* radioButtonWidget1 = new QWidget{};
	QHBoxLayout* radioButtonLayout1 = new QHBoxLayout{ radioButtonWidget1 };
	this->sortedButton = new QRadioButton("Sorted");
	radioButtonLayout1->addWidget(sortedButton);

	QWidget* radioButtonWidget2 = new QWidget{};
	QHBoxLayout* radioButtonLayout2 = new QHBoxLayout{ radioButtonWidget2 };
	this->shuffleButton = new QRadioButton("Shuffled");
	radioButtonLayout2->addWidget(shuffleButton);
	buttonGroup->addButton(sortedButton);
	buttonGroup->addButton(shuffleButton);
	
	//adding the list widget and the buttons to layout
	rightSide2->addWidget(new QLabel{ "Sorted/Shuffled" });
	rightSide2->addWidget(sorted);
	rightSide2->addWidget(radioButtonWidget1);
	rightSide2->addWidget(radioButtonWidget2);
	
	//adding the widgets for each side to the general layout
	layout->addWidget(leftwidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);
	layout->addWidget(rightWidget2);
	
	this->connectSignalAndSlots();

}

void GUI::populateRepoList()
{
	if (this->coats->count() > 0)
		this->coats->clear();
	for (auto c : this->allInRepo)
	{
		stringstream buffer;
		buffer << c.getSize() << "," << c.getColour() << "," << c.getQuantity() << "," << c.getPrice();
		QString itemInList = QString::fromStdString(buffer.str());
		QListWidgetItem* item3 = new QListWidgetItem(itemInList);
		this->coats->addItem(item3);
	}
	if (this->allInRepo.size() > 0)
		this->coats->setCurrentRow(this->coats->count()-1);

}

void GUI::populateSorted(vector<TrenchCoat> v)
{
	if (this->sorted->count() > 0)
		this->sorted->clear();
	for (auto it : v)
	{
		stringstream buffer;
		buffer << it.getSize() << " " << it.getColour() << " " << it.getQuantity() << " " << it.getPrice() << " " << it.getPhoto();
		QString itemInList = QString::fromStdString(buffer.str());
		QListWidgetItem*item3 = new QListWidgetItem(itemInList);
		this->sorted->addItem(item3);
	}
	if (v.size() > 0)
		this->sorted->setCurrentRow(0);
}

void GUI::populateFiltered(vector<TrenchCoat> v)
{
	//if (this->filtered->count() > 0)
		this->filtered->clear();

	for (auto it : v)
	{
		stringstream buffer;
		buffer << it.getSize() << "," << it.getColour() << "," << it.getQuantity() << "," << it.getPrice();
		QString itemInList = QString::fromStdString(buffer.str());
		QListWidgetItem *item3 = new QListWidgetItem{ itemInList };
		this->filtered->addItem(item3);
	}
	if (v.size() > 0)
		this->sorted->setCurrentRow(0);

}

void GUI::populateCart(vector<TrenchCoat> v)
{
	if (this->cart->count() > 0)
		this->cart->clear();

	for (auto it : v)
	{
		stringstream buffer;
		buffer << it.getSize() << "," << it.getColour() << "," << it.getQuantity() << "," << it.getPrice();
		QString itemInList = QString::fromStdString(buffer.str());
		QListWidgetItem *item3 = new QListWidgetItem{ itemInList };
		this->cart->addItem(item3);
	}
	if (v.size() > 0)
		this->cart->setCurrentRow(0);
}

void GUI::connectSignalAndSlots()
{
	QObject::connect(this->coats, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->sortedButton, SIGNAL(clicked()), this, SLOT(sortList()));
	QObject::connect(this->shuffleButton, SIGNAL(clicked()), this, SLOT(shuffleList()));
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewCoat()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteCoat()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateCoat()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterSize()));
	QObject::connect(this->buyButton, SIGNAL(clicked()), this, SLOT(getCart()));
	QObject::connect(this->billButton,SIGNAL(clicked()),this,SLOT(showBill()));
	QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(saveToFile()));
}


int GUI::getCoatsSelectionIndex()
{
	if (this->coats->count() == 0)
		return  -1;
	QModelIndexList index = this->coats->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->sizeEdit->clear();
		this->colourEdit->clear();
		this->quantityEdit->clear();
		this->priceEdit->clear();
		this->photoEdit->clear();
		return -1;

	}
	int idx = index.at(0).row();
	return idx;
}



void GUI::sortList()
{
	vector<TrenchCoat> sorted = this->ctrl->getSortedCoats();
	this->populateSorted(sorted);


}

void GUI::shuffleList()
{
	vector<TrenchCoat> shuffled;
	shuffled = this->ctrl->getCoats();
	this->populateSorted(shuffled);
}

void GUI::addNewCoat()
{
	double size = stod(this->sizeEdit->text().toStdString());
	string colour = this->colourEdit->text().toStdString();
	int quantity = stoi(this->quantityEdit->text().toStdString());
	double price = stod(this->priceEdit->text().toStdString());
	string photo = this->photoEdit->text().toStdString();
	TrenchCoat t{ size,colour,quantity,price,photo };
	try
	{
		this->ctrl->addCoatCont(t);
		this->allInRepo = this->ctrl->getCoats();
		this->populateRepoList();
	}
	catch (CoatException& e)
	{
		QMessageBox messageBox;
		for(auto c:e.getErrors())
			messageBox.critical(0, "Error", QString::fromStdString(c));

	}
	catch (FileException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}


}

void GUI::deleteCoat()
{
	double size = stod(this->sizeEdit->text().toStdString());
	string colour = this->colourEdit->text().toStdString();
	int quantity = stoi(this->quantityEdit->text().toStdString());
	double price = stod(this->priceEdit->text().toStdString());
	string photo = this->photoEdit->text().toStdString();
	TrenchCoat t{ size,colour,quantity,price,photo };
	try
	{
		this->ctrl->removeCoatCont(t);
		this->allInRepo = this->ctrl->getCoats();
		this->populateRepoList();
	}
	catch (CoatException& e)
	{
		QMessageBox messageBox;
		for (auto it : e.getErrors())
			messageBox.critical(0, "Error", QString::fromStdString(it));
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}

}

void GUI::updateCoat()
{
	double size = stod(this->sizeEdit->text().toStdString());
	string colour = this->colourEdit->text().toStdString();
	int quantity = stoi(this->quantityEdit->text().toStdString());
	double price = stod(this->priceEdit->text().toStdString());
	string photo = this->photoEdit->text().toStdString();
	TrenchCoat t{ size,colour,quantity,price,photo };
	
	try
	{
		this->ctrl->updateCoatCont(t);
		this->allInRepo = this->ctrl->getCoats();
		this->populateRepoList();
	}
	catch (CoatException& e)
	{
		QMessageBox messageBox;
		for (auto it : e.getErrors())
			messageBox.critical(0, "Error", QString::fromStdString(it));
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getMessage()));
	}


}

void GUI::filterSize()
{
	if (this->filtered->count() > 0)
		this->filtered->clear();
	double size = stod(this->filterEdit->text().toStdString());
	this->ctrl->emptyBasket();
	this->ctrl->showBySize(size);
	this->filteredCoats = this->ctrl->getFiltered();
	this->populateFiltered(this->filteredCoats);

}

void GUI::getCart()
{
	int idx = this->getFilteredSelectionIndex();
	if (idx == -1 || idx > this->filteredCoats.size())
		return;
	TrenchCoat c = this->filteredCoats[idx];
	this->ctrl->addToBasket(c);
	vector<TrenchCoat> cart = this->ctrl->getCart();
	//this->allInRepo = this->ctrl->getCoats();
	//this->populateRepoList();
	this->populateCart(cart);
	
}

void GUI::showBill()
{
	QMessageBox message;
	message.information(0,"Your bill is:",QString::fromStdString(to_string(this->ctrl->getBill())));
}

void GUI::saveToFile()
{
	string filename= "cart.html";
	this->ctrl->saveCart(filename);

	this->ctrl->openFile();
}

void GUI::listItemChanged()
{
	int idx = this->getCoatsSelectionIndex();
	if (idx == -1)
		return;

	std::vector<TrenchCoat> coat = this->allInRepo;
	if (idx >= coat.size())
		return;
	TrenchCoat c = coat[idx];

	this->sizeEdit->setText(QString::fromStdString(to_string(c.getSize())));
	this->colourEdit->setText(QString::fromStdString(c.getColour()));
	this->quantityEdit->setText(QString::fromStdString(to_string(c.getQuantity())));
	this->priceEdit->setText(QString::fromStdString(to_string(c.getPrice())));
	this->photoEdit->setText(QString::fromStdString(c.getPhoto()));


}
int GUI::getFilteredSelectionIndex()
{
	if (this->coats->count() == 0)
		return  -1;
	QModelIndexList index = this->filtered->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->sizeEdit->clear();
		this->colourEdit->clear();
		this->quantityEdit->clear();
		this->priceEdit->clear();
		this->photoEdit->clear();
		return -1;

	}
	int idx = index.at(0).row();
	return idx;
}