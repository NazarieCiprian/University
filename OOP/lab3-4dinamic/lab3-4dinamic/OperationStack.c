#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "OperationStack.h"

Operation * createOperation(Medication * m, char * operationType)
{
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->med = copyMedication(m);
	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(strlen(operationType) + 1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;
	return o;
}

void destroyOperation(Operation * o)
{
	if (o == NULL)
		return;
	destroyMedication(o->med);
	free(o->operationType);
	free(o);
}

Operation * copyOperation(Operation * o)
{
	if (o == NULL)
		return;
	Operation* newop = createOperation(o->med, o->operationType);
	return newop;
}

char * getOperationType(Operation * o)
{
	return o->operationType;
}

Medication * getMedication(Operation * o)
{
	return o->med;
}

//-------------------------------------------------

OperationStack * createStack()
{
	OperationStack* stack = (OperationStack*)malloc(sizeof(OperationStack));
	stack->length = 0;
	return stack;
}

void destroyStack(OperationStack * stack)
{
	if (stack == NULL)
		return;
	int i;
	for (i = 0; i < stack->length; i++)
		destroyOperation(stack->operations[i]);
	free(stack);
}

void push(OperationStack * stack, Operation * o)
{
	if (isFull(stack))
		return ;
	
	stack->operations[stack->length++] = copyOperation(o);

}

Operation * pop(OperationStack * stack)
{
	if (isEmpty(stack))
		return NULL;
	stack->length--;
	return stack->operations[stack->length];
}

int isEmpty(OperationStack * stack)
{
	return (stack->length == 0);
}

int isFull(OperationStack * stack)
{
	return (stack->length == 100);
}


//-------------------------------------------------

