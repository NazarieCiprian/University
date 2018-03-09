#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DynamicArray.h"

DynamicArray * createDynamicArray(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (da == NULL) //test that the space was allocated
		return NULL;
	da->capacity = capacity;
	da->length = 0;
	//allocate space for elements
	da->meds = (Element*)malloc(capacity * sizeof(Element));
	if (da->meds == NULL) 
		return da;

}

void destroyArray(DynamicArray * array)
{
	if (array == NULL)
		return;
	free(array->meds);
	array->meds = NULL;
	free(array);
	array = NULL;

}

void resize(DynamicArray* array)
{
	if (array == NULL)
		return;
	array->capacity *= 2;
	array->meds = (Element*)realloc(array->meds, array->capacity*sizeof(Element));

}
void addToArray(DynamicArray * array, Element med)
{
	if (array == NULL)
		return;
	if (array->meds == NULL)
		return;
	if (array->capacity == array->length)
		resize(array);
	array->meds[array->length++] = med;
}

void deleteFromArray(DynamicArray * array, int pos)
{
	if (array == NULL)
		return;
	if (array->meds == NULL)
		return;
	int i;
	for (i = pos; i < array->length - 1; i++)
		array->meds[i] = array->meds[i + 1];
	array->length--;

}
void updateQuantity(DynamicArray* array, int pos, int quantity)
{
	if (array == NULL)
		return;
	if (array->meds == NULL)
		return;
	array->meds[pos]->quantity += quantity;
}
void updateInArray(DynamicArray * array, int pos, int quantity, double price)
{
	if (array == NULL)
		return;
	if (array->meds == NULL)
		return;
	array->meds[pos]->quantity = quantity;
	array->meds[pos]->price = price;
}
int getLength(DynamicArray * array)
{
	if (array == NULL)
		return -1;
	return array->length;
}

Element getElement(DynamicArray * array, int pos)
{
	return array->meds[pos];
}

void reduceQuantity(DynamicArray * array, int pos, int quantity)
{
	if (array == NULL)
		return;
	array->meds[pos]->quantity -= quantity;
}

void testArray()
{
	DynamicArray* array= createDynamicArray(CAPACITY);
	Medication*a;
	Medication*b;
	Medication*c;
	Medication*d;
	a = createMedication("Algocalmin", 100, 20, 2.5);
	b = createMedication("Nurofen", 20, 100, 3.4);
	c = createMedication("Ibuprofen", 40, 50, 7.8);
	d = createMedication("Loperamid", 30, 10, 4.5);
	//test addToArray
	addToArray(array, a);
	assert(getLength(array) == 1);
	addToArray(array, b);
	assert(getLength(array) == 2);
	addToArray(array, c);
	assert(getLength(array) == 3);
	addToArray(array, d);
	assert(getLength(array) == 4);
	//test updateQuantity
	updateQuantity(array, 1, 20);
	assert(getQuantity(getElement(array, 1)) == 120);
	//test reduceQuantity
	reduceQuantity(array, 2, 20);
	assert(getQuantity(getElement(array, 2)) == 30);
	//test update
	updateInArray(array, 2, 70, 5.5);
	assert(getQuantity(getElement(array, 2)) == 70);
	assert(getPrice(getElement(array, 2)) == 5.5);
	//test remove
	deleteFromArray(array, 2);
	assert(getLength(array) == 3);

	
}