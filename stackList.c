#include "stack.h"
#include<assert.h>


Stack initializeStack(void)
{
	Stack stack = createEmptyList();
	return stack; // Ersätt denna rad med rätt returvärde
}

int stackIsEmpty(const Stack stack)
{
	return isEmptyList(stack); // Ersätt denna rad med rätt returvärde
}

int stackIsFull(const Stack stack)
{
	return 0; // Ersätt denna rad med rätt returvärde
}

void push(Stack* stack, const Data data)
{
	assert(!stackIsFull(*stack));
	addFirst(stack, data);
	assert((*stack)->next->data == data);
	// Precondition: stacken får inte vara full
	// Postcondition 'data' ligger överst på stacken
}

void pop(Stack* stack)
{
	assert(!isEmptyList(*stack));
	// Precondition: stacken får inte vara tom
	removeFirst(stack);
}

Data peekStack(const Stack stack)
{
	assert(!isEmptyList(stack));
	// Precondition: stacken får inte vara tom
	Data data = stack->next->data;
	return data; // Ers'tt denna rad med rätt returvärde
}
