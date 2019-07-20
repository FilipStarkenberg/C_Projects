#include "stack.h"
#include<assert.h>


Stack initializeStack(void)
{
	Stack stack = createEmptyList();
	return stack; // Ers�tt denna rad med r�tt returv�rde
}

int stackIsEmpty(const Stack stack)
{
	return isEmptyList(stack); // Ers�tt denna rad med r�tt returv�rde
}

int stackIsFull(const Stack stack)
{
	return 0; // Ers�tt denna rad med r�tt returv�rde
}

void push(Stack* stack, const Data data)
{
	assert(!stackIsFull(*stack));
	addFirst(stack, data);
	assert((*stack)->next->data == data);
	// Precondition: stacken f�r inte vara full
	// Postcondition 'data' ligger �verst p� stacken
}

void pop(Stack* stack)
{
	assert(!isEmptyList(*stack));
	// Precondition: stacken f�r inte vara tom
	removeFirst(stack);
}

Data peekStack(const Stack stack)
{
	assert(!isEmptyList(stack));
	// Precondition: stacken f�r inte vara tom
	Data data = stack->next->data;
	return data; // Ers'tt denna rad med r�tt returv�rde
}
