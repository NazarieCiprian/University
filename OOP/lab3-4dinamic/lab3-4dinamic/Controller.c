#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Controller.h"

Controller * createController(MedsRepo * repo, OperationStack* undostack, OperationStack* redostack)
{
	Controller * c = (Controller*)malloc(sizeof(Controller));
	c->repo = repo;
	c->undoStack = undostack;
	c->redoStack = redostack;
	return c;
}

void destroyController(Controller * c)
{
	//detroy the repository first
	destroyRepo(c->repo);
	//destroy undostack
	destroyStack(c->undoStack);
	//destroy redostack
	destroyStack(c->redoStack);
	//destroy the controller
	free(c);
}

int addMedicationCont(Controller * c, char * name, int concentration, int quantity, double price)
{
	Medication* med = createMedication(name, concentration, quantity, price);
	int res = addMedication(c->repo, med);
	if (res == 1)
	{
		Operation* o = createOperation(med, "add");
		push(c->undoStack, o);

		destroyOperation(o);
		destroyStack(c->redoStack);
		c->redoStack = createStack();
	}
	else
	{
		if (res == 0)
		{
			Operation* o = createOperation(med, "quant");
			push(c->undoStack, o);
			//destroyOperation(o);

			destroyStack(c->redoStack);
			c->redoStack = createStack();
		}
	}
	destroyMedication(med);
	return res;
}
int deleteMedicationCont(Controller * c, char * name, int concentration)
{
	int res;
	Medication* med = createMedication(getName(findMed(c->repo, name, concentration)), getConcentration(findMed(c->repo, name, concentration)), getQuantity(findMed(c->repo, name, concentration)), getPrice(findMed(c->repo, name, concentration)));
	res = deleteMedication(c->repo, name, concentration);
	
	if (res == 1)
	{
		Operation* o = createOperation(med, "delete");
		push(c->undoStack, o);
	}
	destroyMedication(med);
	return res;
}
int updateMedicationCont(Controller * c, char * name, int concentration, int newquantity, double newprice)
{
	int res;
	Medication* med = createMedication(name, concentration, newquantity, newprice);
	Medication *m = createMedication(getName(findMed(c->repo, name, concentration)), getConcentration(findMed(c->repo, name, concentration)), getQuantity(findMed(c->repo, name, concentration)), getPrice(findMed(c->repo, name, concentration)));
	res = updateMedication(c->repo, med);
	if (res == 1)
	{
		Operation* o = createOperation(m, "update");
		push(c->undoStack, o);
		destroyStack(c->redoStack);
		c->redoStack = createStack();
	}
	destroyMedication(m);
	destroyMedication(med);
	return res;
}
void swap(Medication** a, Medication** b)
{
	Medication *aux;
	 aux = *a;
	*a = *b;
	*b = aux;

}
MedsRepo * showByName(Controller * c, char string[])
{
	int i,j;
	MedsRepo* res = createRepo();
	if (strcmp(string, "null") == 0)
	{
		int length;
		length = getRepoLength(c->repo);
		for (i = 0; i < length; i++)
		{
			Medication* med;
			med = getMedOnPos(c->repo, i);
			addMedication(res, med);
			
		}
		for (i = 0; i < length; i++)
			for (j = i + 1; j < length; j++)
				if (strcmp(res->meds->meds[i]->name, res->meds->meds[j]->name) > 0)
					swap(&res->meds->meds[i], &res->meds->meds[j]);

	}
	else
	{
		int length = getRepoLength(c->repo);
		for (i = 0; i < length; i++)
		{
			Medication* med = getMedOnPos(c->repo, i);
			if (strstr(getName(med), string) != NULL)
			{
				addMedication(res, med);
			}
			
		}
		int lung = getRepoLength(res);
		for (i = 0; i < lung; i++)
			for (j = i + 1; j < lung-1; j++)
				if (strcmp(res->meds->meds[i]->name,res->meds->meds[j]->name) > 0)
					swap(&res->meds->meds[i], &res->meds->meds[j]);
	}
	return res;
	
}
MedsRepo* lessThen(Controller* c, int quantity)
{
	MedsRepo *res = createRepo();
	int i, length;
	length = getRepoLength(c->repo);
	for (i = 0; i < length; i++)
	{
		Medication *med = getMedOnPos(c->repo, i);
		if (med->quantity < quantity)
			addMedication(res, med);
	}
	return res;
}
MedsRepo* showDescending(Controller* c, char string[])
{
	int i, j;
	MedsRepo* res = createRepo();
	if (strcmp(string, "null") == 0)
	{
		int length;
		length = getRepoLength(c->repo);
		for (i = 0; i < length; i++)
		{
			Medication* med;
			med = getMedOnPos(c->repo, i);
			addMedication(res, med);

		}
		for (i = 0; i < length; i++)
			for (j = i + 1; j < length; j++)
				if (res->meds->meds[i]->concentration > res->meds->meds[j]->concentration)
					swap(&res->meds->meds[i], &res->meds->meds[j]);

	}
	else
	{
		int length = getRepoLength(c->repo);
		for (i = 0; i < length; i++)
		{
			Medication* med = getMedOnPos(c->repo, i);
			if (strstr(getName(med), string) != NULL)
			{
				addMedication(res, med);
			}

		}
		int lung = getRepoLength(res);
		for (i = 0; i < lung; i++)
			for (j = i + 1; j < lung - 1; j++)
				if (res->meds->meds[i]->concentration > res->meds->meds[j]->concentration)
					swap(&res->meds->meds[i], &res->meds->meds[j]);
	}
	return res;
}
MedsRepo* getRepo(Controller* c)
{
	return c->repo;
}

int undo(Controller* c)
{
	if (isEmpty(c->undoStack))
	{
		return 0;
	}
	Operation* o = pop(c->undoStack);
	if (strcmp(getOperationType(o), "add") == 0)
	{
		Medication* med = getMedication(o);
		char name[50];
		int concentration;
		strcpy(name, getName(med));
		concentration = getConcentration(med);
		Medication *newmed = createMedication(name, concentration, getQuantity(med), getPrice(med));
		Operation* newo = createOperation(newmed, "delete");
		push(c->redoStack, newo);
		deleteMedication(c->repo, name, concentration);
	}
	else if (strcmp(getOperationType(o), "quant") == 0)
	{
		Medication* med = getMedication(o);
		char name[50];
		int pos,concentration,quantity;
		strcpy(name, getName(med));
		concentration = getConcentration(med);
		quantity = getQuantity(med);
		pos = findPos(c->repo, name, concentration);
		Medication* newmed = createMedication(name, concentration, quantity, getPrice(med));
		Operation* newo=createOperation(newmed,"quant");
		push(c->redoStack, newo);
		reduceQuantity(c->repo->meds,pos,quantity);

	}
	else if (strcmp(getOperationType(o), "delete") == 0)
	{
		Medication* med = getMedication(o);
		Medication* newmed = createMedication(getName(med), getConcentration(med), getQuantity(med), getPrice(med));
		Operation* newo = createOperation(newmed, "add");
		push(c->redoStack, newo);
		addMedication(c->repo, med);
		
	}
	else if (strcmp(getOperationType(o), "update") == 0)
	{
		Medication* med = getMedication(o);
		char name[50];
		int concentration = getConcentration(med);
		strcpy(name, getName(med));
		Medication* newmed = createMedication(getName(findMed(c->repo, name, concentration)), getConcentration(findMed(c->repo, name, concentration)), getQuantity(findMed(c->repo, name, concentration)), getPrice(findMed(c->repo, name, concentration)));
		Operation* newo = createOperation(newmed, "update");
		push(c->redoStack, newo);
		updateMedication(c->repo, med);
		
	}
	//destroyOperation(o);
	return 1;
	
}

int redo(Controller* c)
{
	if (isEmpty(c->redoStack))
	{
		return 0;
	}
	Operation* o = pop(c->redoStack);
	if (strcmp(getOperationType(o), "delete") == 0)
	{
		Medication* med = getMedication(o);
		char name[50];
		int concentration;
		strcpy(name, getName(med));
		concentration = getConcentration(med);
		addMedication(c->repo, med);
	}
	else if (strcmp(getOperationType(o), "quant") == 0)
	{
		Medication* med = getMedication(o);
		char name[50];
		int concentration, pos;
		strcpy(name, getName(med));
		concentration = getConcentration(med);
		pos = findPos(c->repo, name, concentration);
		updateQuantity(c->repo->meds, pos, getQuantity(med));

	}
	else if (strcmp(getOperationType(o), "add") == 0)
	{
		Medication* med = getMedication(o);
		Medication* newmed = createMedication(getName(med), getConcentration(med), getQuantity(med), getPrice(med));
		char name[50];
		int concentration;
		strcpy(name, getName(med));
		concentration = getConcentration(med);
		deleteMedication(c->repo, name, concentration);

	}
	else if (strcmp(getOperationType(o), "update") == 0)
	{
		Medication* med = getMedication(o);
		Medication* newmed = createMedication(getName(med), getConcentration(med), getQuantity(med), getPrice(med));
		updateMedication(c->repo, newmed);
	}
	return 1;
}

void testController()
{
	MedsRepo* repo = createRepo();
	OperationStack* undoStack, *redoStack;
	undoStack = createStack();
	redoStack = createStack();
	Controller* ctrl = createController(repo,undoStack,redoStack);
	Medication*a;
	Medication*b;
	Medication*c;
	Medication*d;
	a = createMedication("Algocalmin", 100, 20, 2.5);
	b = createMedication("Nurofen", 20, 100, 3.4);
	c = createMedication("Ibuprofen", 40, 50, 7.8);
	d = createMedication("Loperamid", 30, 10, 4.5);
	addMedicationCont(ctrl , getName(a), getConcentration(a), getQuantity(a), getPrice(a));
	assert(getRepoLength(repo) == 1);
	addMedicationCont(ctrl, getName(b), getConcentration(b), getQuantity(b), getPrice(b));
	assert(getRepoLength(repo) == 2);
	addMedicationCont(ctrl, getName(c), getConcentration(c), getQuantity(c), getPrice(c));
	assert(getRepoLength(repo) == 3);
	addMedicationCont(ctrl, getName(d), getConcentration(d), getQuantity(d), getPrice(d));
	assert(getRepoLength(repo) == 4);
	assert(updateMedicationCont(ctrl, "Algocalmin", 100, 30, 4.5)==1);
	
	deleteMedicationCont(ctrl, "Algocalmin", 100);
	assert(getRepoLength(repo) == 3);
	destroyMedication(a);
	destroyMedication(b);
	destroyMedication(c);
	destroyMedication(d);
	
}