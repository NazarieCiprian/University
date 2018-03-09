#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "PharmacyRepo.h"

MedsRepo * createRepo()
{
	MedsRepo *repo = (MedsRepo*)malloc(sizeof(MedsRepo));
	repo->meds = createDynamicArray(CAPACITY);
	return repo;
}

void destroyRepo(MedsRepo* repo)
{
	if (repo == NULL)
		return;
	int i;
	for (i = 0; i < getLength(repo->meds); i++)
	{
		Medication* med = getElement(repo->meds, i);
		destroyMedication(med);
	}
	destroyArray(repo->meds);
	free(repo);

}

int findPos(MedsRepo * repo, char * name, int concentration)
{
	int i, length;
	length = getLength(repo->meds);
	Medication* med;
	for (i = 0; i < length; i++)
	{
		med = getElement(repo->meds, i);
		if (strcmp(getName(med), name) == 0 && getConcentration(med) == concentration)
			return i;
	}
	return -1;
}

Medication * findMed(MedsRepo * repo, char * name, int concentration)
{
	if (repo == NULL)
		return NULL;
	int result = findPos(repo, name, concentration);
	if (result == -1)
		return NULL;
	return getElement(repo->meds, result);
}

int addMedication(MedsRepo * repo, Medication* med)
{
	if (repo == NULL)
		return -1;
	//search for an existing medication by name and concetration;if we find a match we increase its quantity
	if (findMed(repo, med->name, med->concentration) != NULL)
	{
		updateQuantity(repo->meds, findPos(repo, med->name, med->concentration), med->quantity);
		return 0;
	}
	Medication* copy = copyMedication(med);
	addToArray(repo->meds, copy);
	return 1;
}

int deleteMedication(MedsRepo * repo, char* name, int concentration)
{
	if (repo == NULL)
		return -1;
	int pos = findPos(repo, name, concentration);
	if (pos == -1)
		return 0;
	Medication* m = getElement(repo->meds, pos);
	destroyMedication(m);
	deleteFromArray(repo->meds, pos);
	return 1;

}

int updateMedication(MedsRepo * repo, Medication * med)
{
	if (repo == NULL)
		return -1;
	int pos = findPos(repo, med->name, med->concentration);
	if (pos == -1)
		return 0;
	updateInArray(repo->meds, pos, med->quantity, med->price);
	return 1;
}

int getRepoLength(MedsRepo * repo)
{
	if (repo == NULL)
		return -1;
	return getLength(repo->meds);
}

Medication* getMedOnPos(MedsRepo* repo, int pos)
{
	if (repo == NULL)
		return NULL;
	if(pos <0 || pos>=getLength(repo->meds))
	{ 
		return NULL;
	}
	return getElement(repo->meds, pos);
}

void testRepo()
{
	MedsRepo* repo = createRepo();
	Medication*a;
	Medication*b;
	Medication*c;
	Medication*d;
	a = createMedication("Algocalmin", 100, 20, 2.5);
	b = createMedication("Nurofen", 20, 100, 3.4);
	c = createMedication("Ibuprofen", 40, 50, 7.8);
	d = createMedication("Loperamid", 30, 10, 4.5);
	//test add
	addMedication(repo, a);
	assert(getRepoLength(repo) == 1);
	addMedication(repo, b);
	assert(getRepoLength(repo) == 2);
	addMedication(repo, c);
	assert(getRepoLength(repo) == 3);
	addMedication(repo, d);
	assert(getRepoLength(repo) == 4);
	//test delete
	deleteMedication(repo, "Nurofen",20);
	assert(getLength(repo->meds) == 3);
	//test update
	Medication *e = createMedication("Nurofen", 20, 150, 4.5);
	assert(updateMedication(repo, e) == 0);
	//test getMedOnPos
	Medication *tst = getMedOnPos(repo, 1);
	assert(strcmp(getName(tst), "Ibuprofen") == 0);
	destroyRepo(repo);
	destroyMedication(a);
	destroyMedication(b);
	destroyMedication(c);
	destroyMedication(e);
	destroyMedication(d);
}


