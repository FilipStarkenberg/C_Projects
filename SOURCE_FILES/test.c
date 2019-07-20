#include "test.h"

void testQueue(void);
void testStack(void);
void testSet(void);

void testADT(void)
{
	// Kommentera och avkommentera vid behov
	testQueue();
	testStack();
	testSet();
	printf("%s\n", "You Completed The Test!");
}


void testQueue(void)
{
	Queue queue = initializeQueue();

	// K�n ska vara tom och inte full
	assert(queueIsEmpty(queue));
	assert(!queueIsFull(queue));

	int i;
	// Fyller k�n med 1 2 3 4 5 6 7 8 9 10
	for (i = 1; i <= 10; i++)
		enqueue(&queue, i);

	assert(!queueIsEmpty(queue));
	assert(front(queue) == 1);	// 1 ska st� f�rst i k�n

	for (i = 0; i < 5; i++)
		dequeue(&queue);	// Ta bort de fem f�rsta i k�n (b�r vara 1,2,3,4 och 5)

	assert(!queueIsEmpty(queue));
	assert(front(queue) == 6);	// 6 b�r allts� st� f�rst i k�n nu

	enqueue(&queue, 11);
	assert(front(queue) == 6);	// 6 b�r fortfarande vara f�rst i k�n

	// Ta bort alla element
	for (i = 0; i < 6; i++) // K�n ska nu inneh�lla 6 element totalt
		dequeue(&queue);

	// �terigen ska k�n vara tom och inte full
	assert(queueIsEmpty(queue));
	assert(!queueIsFull(queue));

	// L�gg till och ta bort 100 element
	for (i = 0; i < 100; i++)
	{
		enqueue(&queue, i);
		assert(front(queue) == i);
		dequeue(&queue);
		assert(queueIsEmpty(queue));
	}
}

void testStack(void)
{
	Stack stack = initializeStack();

	// Stacken ska vara tom och inte full
	assert(stackIsEmpty(stack));
	assert(!stackIsFull(stack));

	int i;
	// Fyller stacken med 1 2 3 4 5 6 7 8 9 10
	for (i = 1; i <= 10; i++)
		push(&stack, i);

	assert(!stackIsEmpty(stack));
	assert(peekStack(stack) == 10);	// �versta elementet b�r vara 10

	for (i = 0; i < 5; i++)
		pop(&stack);	// Ta bort de fem �versta i stacken (10, 9, 8, 7 och 6)

	assert(!stackIsEmpty(stack));
	assert(peekStack(stack) == 5);	// 5 b�r allts� vara �verst p� stacken nu

	push(&stack, 0); // L�gg 0 �verst p� stacken
	assert(peekStack(stack) == 0);
	pop(&stack);
	assert(peekStack(stack) == 5); // 5 �r n�st �verst

	// Ta bort de kvarvarande elementen
	for (i = 0; i < 5; i++)
		pop(&stack);

	// �terigen ska k�n vara tom och inte full
	assert(stackIsEmpty(stack));
	assert(!stackIsFull(stack));
}

void testSet(void)
{
	Set set = initializeSet();
	int i;

	for (i = 1; i <= 10; i++)
		assert(!isInSet(set, i)); // Inget element f�r finnas i settet

	for (i = 1; i <= 10; i++)
		if (i % 2 == 0)
			addToSet(&set, i);	// L�gg till alla j�mna tal mellan 1 och 10 (dvs 2,4,6,8,10)

	for (i = 1; i <= 10; i++)
		if (i % 3 == 0)
			removeFromSet(&set, i); // Ta bort alla tal som �r delbara med 3 fr�n set (dvs tar bort 6, kvar ska 2,4,8,10 vara)

	for (i = 1; i <= 10; i++)
		if (i % 2 == 0 && i % 3 != 0)
		{
			assert(isInSet(set, i)); // Talet ska finnas i set om det �r j�mnt men inte delbart med tre
		}
		else
		{
			assert(!isInSet(set, i)); // Annars ska det inte finnas
		}
}
