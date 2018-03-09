#pragma once
#include "Medication.h"
#include "DynamicArray.h"
typedef struct {

	Medication* med;
	char* operationType;
}Operation;
/*
Creates a new operation
Input: m - the medication on which we operate
	   operationType - the operation we perform
*/
Operation* createOperation(Medication* m, char* operationType);
/*
Destroys an operation type object
*/
void destroyOperation(Operation* o);
/*
Makes a copy of an operation type
*/
Operation* copyOperation(Operation* o);
/*
Returns the type of the operation
*/
char* getOperationType(Operation* o);
/*
Returns the medication on which we perform the operation
*/
Medication* getMedication(Operation* o);

//------------------------------------------------

typedef struct {
	Operation* operations[100];
	int length;
}OperationStack;
/*
Creates the operation stack on which we keep the performed operations
*/
OperationStack* createStack();
/*
Destroys the operation stack
*/
void destroyStack(OperationStack* stack);
/*
Function that adds a new element to the stack
Input:stack - the operation stack
	  o - the operation to be added
*/
void push(OperationStack* stack, Operation* o);
/*
Retrieves an element from the stack
*/
Operation* pop(OperationStack* stack);
//Tests if the stack is empty
int isEmpty(OperationStack* stack);
//Tests if the stack is full
int isFull(OperationStack* stack);