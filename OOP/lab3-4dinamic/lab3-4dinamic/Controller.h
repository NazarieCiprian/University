#pragma once
#include "PharmacyRepo.h"
#include "OperationStack.h"
typedef struct {
	MedsRepo *repo;
	OperationStack* undoStack;
	OperationStack* redoStack;

}Controller;
/*
Creates the controller
Input: repo - a pointer to the repository
Returns a pointer to the cotroller
*/
Controller* createController(MedsRepo* repo, OperationStack* undostack,OperationStack* redostack);
/*
Destroys the controller
Input: c- a pointer to the controller
*/
void destroyController(Controller* c);
/*
Adds a new medication to the list or increases the qunatity of an existing one
Input: c- a pointer to the controller
	   name - the name of the medication
	   concentration - the concentration of the medication
	   quantity - the quantity of the medication
	   price - the price for the medication
Returns an integer which show what kind of operation was performed
*/
int addMedicationCont(Controller* c, char* name, int concentration, int quantity, double price);
/*
Deletes medication from repository
Input: c- a pointer to the controller
	   name - the name of the medication
	   concentration- the concentration of the repository
*/
int deleteMedicationCont(Controller* c, char*name, int concentration);
/*
Updates the information of a medication
Input: c- a pointer to the controller
		name- the name of the medication
		concentration - the concentration of the medication
		newquantity - the quanntity of the medication
		newprice - the new price
*/
int updateMedicationCont(Controller* c, char* name, int concentration, int newquantity, double newprice);
/*
Returns a list of medications which contain the given string sorted alphabetically after name
Input: c -  a pointer to the controller
	   string -  a string that contains the string to search after
Output: a list of elements that satisfy the condition sorted alphabetically
*/
MedsRepo* showByName(Controller* c, char string[]);
/*
Shows the meds containing a given string sorted ascending after concentration
Input: c - a pointer to the controller
		string - the string which we have read
*/
MedsRepo* showDescending(Controller* c, char string[]);
/*
Returns a list of medication which have the quantity less than a given number
Input:c - a pointer to the controller
	  quantity - the minimum quantity of medications that we must have 
Output:A list that contains the medications which are short in quantity
*/
MedsRepo* lessThen(Controller* c, int quantity);
MedsRepo* getRepo(Controller* c);
/*
A function that performs the undo operations
Input:c- a pointer to the controller
Returns 1 if the undo could be performed and 0 otherwise
*/
int undo(Controller* c);
/*
A function that performs the redo operations
Input:c - a pointer to the controller
Returns 1 if the redo could be performed and 0 otherwise
*/
int redo(Controller* c);
void testController();