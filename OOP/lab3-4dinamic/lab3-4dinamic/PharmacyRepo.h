#pragma once
#include "Medication.h"
#include "DynamicArray.h"
typedef struct {
	DynamicArray* meds;

}MedsRepo;

/*
Creates the repository and returns a pointer to it
Output: a pointer to the created repository
*/
MedsRepo* createRepo();
void destroyRepo(MedsRepo* repo);
/*
Finds the position of the element in the array if it exists
Input: repo - a pointer to the repository
	   name - the name of the medication
	   concentration - the concentratio of the medication
Returns an integer representing the position of the element or -1 if no element has been found
*/
int findPos(MedsRepo *repo, char* name, int concentration);
/*
Searches for a medication in the repository 
Input:repo - the repository 
	  name - the name of the medication we are looking for
	  concentration - the concentration of the medication
Returns the medication if we find it or NULL if it does not exist
*/
Medication* findMed(MedsRepo* repo, char* name, int concentration);
/*
Adds a new medication to the repository
Input: repo - a pointer to the repository
	   med- the new medication
Returns 1 if we added a new medication and 0 if we increased its quantity -1 if we cannot perform the operation
*/
int addMedication(MedsRepo* repo, Medication* med);
/*
Deletes a medication from the repository
Input: repo - a pointer to the repository
	   med - the medication we want to delete
Returns
*/
int deleteMedication(MedsRepo*repo, char* name, int concentration);
/*
Updates the information of a given medication
Input: repo - a pointer to the repository
       med - a pointer to the medication
Returns
*/
int updateMedication(MedsRepo* repo, Medication* med);
/*
Returns the length of the current repository
Input: repo - a pointer to the current repository
Output:Returns the length of the repository
*/
int getRepoLength(MedsRepo* repo);
/**/
Medication* getMedOnPos(MedsRepo* repo, int pos);

/*
Tests the functions from the repository
*/
void testRepo();