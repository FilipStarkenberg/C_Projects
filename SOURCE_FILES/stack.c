#include "stack.h"
#include <assert.h>
#include <stdlib.h>


Stack initializeStack(void)
{
	Stack stack;
	stack.size = 0;
	return stack;
}

int stackIsEmpty(const Stack stack)
{
	if(stack.size == 0) return 1;
	return 0;
}

int stackIsFull(const Stack stack)
{
	if(stack.size == MAXLENGTH) return 1;
	return 0;
}

void push(Stack* stack, const Data data)
{
	assert(!stackIsFull(*stack));
	stack->elements[stack->size++] = data;
	// Precondition: stacken f�r inte vara full
	// Postcondition 'data' ligger �verst p� stacken
	assert(data == peekStack(*stack));
}

void pop(Stack* stack)
{
	assert(!stackIsEmpty(*stack));
	stack->size--;

	// Precondition: stacken f�r inte vara tom
}

Data peekStack(const Stack stack)
{
	assert(!stackIsEmpty(stack));
	return stack.elements[stack.size-1];
	// Precondition: stacken f�r inte vara tom
}
