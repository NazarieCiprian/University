#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Medication.h"

Medication * createMedication(char * name, int concentration, int quantity, double price)
{
	Medication* med = (Medication*)malloc(sizeof(Medication));
	med->name = (char*)malloc(strlen(name) + 1);
	strcpy(med->name, name);
	med->concentration = concentration;
	med->quantity = quantity;
	med->price = price;
	return med;
}

void destroyMedication(Medication * med)
{
	free(med->name);
	free(med);
}

Medication * copyMedication(Medication * med)
{
	if (med == NULL)
		return NULL;
	Medication* newmed = createMedication(getName(med), getConcentration(med), getQuantity(med), getPrice(med));
	return newmed;
}

char * getName(Medication * med)
{
	return med->name;
}

int getConcentration(Medication * med)
{
	return med->concentration;
}

int getQuantity(Medication * med)
{
	return med->quantity;
}

double getPrice(Medication * med)
{
	return med->price;
}

void toString(Medication * med, char str[])
{
	sprintf(str, "Medication %s has concentration %d; its quantity is %d and has the price %lf", med->name, med->concentration, med->quantity, med->price);
}



