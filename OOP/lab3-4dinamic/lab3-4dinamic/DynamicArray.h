#pragma once
#include "Medication.h"
#define CAPACITY 10
typedef Medication* Element;

typedef struct {
	Element* meds;
	int length;
	int capacity;
}DynamicArray;
/*
Creates a dynamic array of generic elements with a given capacity
Input: capacity - An integer, the maximum capacity of the array
Returns a pointer to the created array
*/
DynamicArray* createDynamicArray(int capacity);
/*
Destroys the dynamic array
Input: array - the dynamic array to be destroyed
*/
void destroyArray(DynamicArray* array);
/*
Adds a new element to the array 
Input: array - the dynamic array
	   med - the element to be added to the array
*/
void addToArray(DynamicArray* array, Element med);
/*
Deletes an element from the array
Input: array - the dynamic array
	   pos - the position of the element
*/
void deleteFromArray(DynamicArray* array, int pos);
/*
Update the quantity of a medication
Input: array- pointer to the array
	   pos - the position of the medication in the array
	   quantity - the quantity to be added
*/
void updateQuantity(DynamicArray* array, int pos, int quantity);
/*
Update the information of a medication
Input:array - pointer to the array
	  pos -position of the medication

*/
void updateInArray(DynamicArray* array, int pos, int quantity, double price);
/*
Returns the length of the array
Input: array - the dynamic array of which we want the length
*/
int getLength(DynamicArray* array);
/*
Returns the element from a given postion in the array
Input: array - a pointer to the array
	   pos - the position of the array
Returns the element located on the given position
*/
Element getElement(DynamicArray* array, int pos);

void reduceQuantity(DynamicArray* array, int pos, int quantity);
//Function that tests the DynamicArray
void testArray();