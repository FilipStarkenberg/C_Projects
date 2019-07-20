#include "Queue.h"
#include<assert.h>

Queue initializeQueue(void)
{
	Queue queue = createEmptyList();
	return queue;	// Ers�tt med r�tt returv�rde
}

int queueIsEmpty(const Queue queue)
{
	return isEmptyList(queue); // Ers�tt med r�tt returv�rde
}

int queueIsFull(const Queue queue)
{
	return 0;	// Ers�tt med r�tt returv�rde
}

void enqueue(Queue* queue, const Data data)
{
	// Precondition: k�n �r ej full
	assert(!queueIsFull(*queue));
	addFirst(queue, data);
}

void dequeue(Queue* queue)
{
	// Precondition: k�n �r ej tom
	assert(!isEmptyList(*queue));
	removeLast(queue);
}

Data front(const Queue queue)
{
	// Precondition: k�n �r ej tom
	assert(!isEmptyList(queue));
	return getLastElement(queue);	// Ers�tt med r�tt returv�rde
}
