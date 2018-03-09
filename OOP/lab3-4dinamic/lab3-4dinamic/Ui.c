#include "Ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Ui * createUi(Controller * c)
{
	Ui* ui = (Ui*)malloc(sizeof(Ui));
	ui->ctrl = c;
	return ui;
}

void destroyUi(Ui * ui)
{
	//destroy the controller;
	destroyController(ui->ctrl);
	free(ui);

}
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;
	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);
		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");

	}
	return res;
}
int validCommand(int command)
{
	if (command >= 0 && command <= 10)
		return 1;
	return 0;
}
int addMedicationUi(Ui* ui)
{
	//read data for medication
	char name[50];
	int concentration, quantity;
	double price;
	printf("Please enter the name of the medication: ");
	scanf("%49s", &name);
	printf("Please enter the concentration: ");
	scanf("%d", &concentration);
	printf("Pleas enter the quantity: ");
	scanf("%d", &quantity);
	printf("Please enter the price: ");
	scanf("%lf", &price);
	return addMedicationCont(ui->ctrl, name, concentration, quantity, price);
}
int deleteMedicationUi(Ui*ui)
{
	char name[50];
	int concentration;
	printf("Enter the name of the medication: ");
	scanf("%49s", &name);
	printf("Enter the concentration: ");
	scanf("%d", &concentration);
	return deleteMedicationCont(ui->ctrl, name, concentration);
}
int updateMedicationUi(Ui* ui)
{
	char name[50];
	int concentration, newquantity;
	double newprice;
	printf("Enter the name of the medication: ");
	scanf("%49s", &name);
	printf("Enter the concentration: ");
	scanf("%d", &concentration);
	printf("Enter the new quantity: ");
	scanf("%d", &newquantity);
	printf("Enter the new price: ");
	scanf("%lf", &newprice);
	return updateMedicationCont(ui->ctrl, name, concentration, newquantity, newprice);
}
void showByNameUi(Ui* ui)
{
	char string[200];
	printf("Enter the string you want to search after or null: ");
	scanf("%s", &string);
	MedsRepo* result = showByName(ui->ctrl, string);
	int length = getRepoLength(result);
	if (length == 0)
	{
		printf("There are no medications which contain the given string \n");
	}
	else
	{
		int i;
		for (i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedOnPos(result, i), str);
			printf("%s\n", str);
		}
	}
}
void showDescendingUi(Ui* ui)
{
	char string[200];
	printf("Enter the string or null: ");
	scanf("%s", &string);
	MedsRepo* result = showDescending(ui->ctrl, string);
	int length = getRepoLength(result);
	if (length == 0)
	{
		printf("There are no meds containing the string\n");

	}
	else
	{
		int i;
		for (i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedOnPos(result, i), str);
			printf("%s\n", str);
		}
	}
}
void lessThenUi(Ui* ui)
{
	int quantity;
	printf("Give a quantity: ");
	scanf("%d", &quantity);
	MedsRepo* result = lessThen(ui->ctrl, quantity);
	int length = getRepoLength(result);
	if (length == 0)
	{
		printf("There are no medication satisfying the condition\n");
	}
	else
	{
		int i;
		for (i = 0; i < length; i++)
		{
			char str[200];
			toString(getMedOnPos(result, i), str);
			printf("%s\n", str);
		}
	}
}

void showAllMedicationUi(Ui* ui)
{
	MedsRepo* repo = getRepo(ui->ctrl);
	int length = getRepoLength(repo);
	if (length == 0)
	{
		char* str = "There are no medications.";
		printf("%s \n", str);
	}
	int i;
	for (i = 0; i < length; i++)
	{
		char str[200];
		toString(getMedOnPos(repo, i), str);
		printf("%s\n", str);
	}
}
void printMenu()
{
	printf("\n#################################################\n");
	printf("0 - for exiting the app\n");
	printf("1 - for adding a new medication\n");
	printf("2 - to see the list of medications\n");
	printf("3 - for deleting a medication\n");
	printf("4 - for updating the information of a medication\n");
	printf("5 - to see the medication which contain a given string sorted alphabetically\n");
	printf("6 - to see all the medication that are short in supply\n");
	printf("7 - to undo an operation\n");
	printf("8 - to redo an operation\n");
	printf("9 - to see the meds containing a given string sorted ascending after concentration\n");
	printf("#####################################################\n");
}
void startUi(Ui* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			
			printf("Please enter a valid command\n");
			command = readIntegerNumber("Input command: ");
		
		}
		if (command == 0)
		{
			printf("Bye bye");
			break;
		}
		if (command == 1)
		{
			int res = addMedicationUi(ui);
			if (res == 0)
			{
				printf("Medication already exists;quantity increased!\n");
			}
			else
			{
				if (res == 1)
					printf("Medication added!\n");
				else
					printf("Error!Medication could not be added!\n");
			}
			
		}
		if (command == 2)
		{
			showAllMedicationUi(ui);
		}
		if (command == 3)
		{
			int res= deleteMedicationUi(ui);
			if (res == 0)
			{
				printf("Could not find the medication!\n");
			}
			else
			{
				if (res == 1)
				{
					printf("Medication deleted!\n");
				}
				else
					printf("Error!");
			}
		}
		if (command == 4)
		{
			int res;
			res = updateMedicationUi(ui);
			if (res == 1)
			{
				printf("Update was succesful\n");
			}
			else
			{
				printf("Update was not succesful\n");
			}
		}
		if (command == 5)
		{
			showByNameUi(ui);
		}
		if (command == 6)
		{
			lessThenUi(ui);
		}
		if (command == 7)
		{
			int res=undo(ui->ctrl);
			if (res == 1)
			{
				printf("Undo was succesfull\n");
			}
			else
			{
				printf("Undo was not succesfull\n");
			}
		}
		if (command == 8)
		{
			int res = redo(ui->ctrl);
			if (res == 1)
			{
				printf("Redo was succesfull\n");
			}
			else
			{
				printf("Redo was not succesful\n");
			}
		}
		if (command == 9)
		{
			showDescendingUi(ui);
		}


	}
}