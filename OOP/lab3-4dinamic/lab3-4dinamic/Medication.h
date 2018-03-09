#pragma once
typedef struct {
	char* name;
	int concentration;
	int quantity;
	double price;
}Medication;

/*
Creates a Medication entity
Input: name - the name of the new medication
		concentration - the concentration for the new medication
		quantity - the quantity of the new medication
		price - the price of the medication
*/
Medication* createMedication(char* name, int concentration, int quantity, double price);
void destroyMedication(Medication* med);
Medication* copyMedication(Medication* med);
//Returns the name of the medication
char* getName(Medication* med);
//Returns the concentration
int getConcentration(Medication* med);
//Returns the quantity
int getQuantity(Medication* med);
//Returns the price of the medication
double getPrice(Medication* med);
void toString(Medication* med, char str[]);