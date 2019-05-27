#include "Array.h"
#include "Statistics.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int isSorted(const ElementType* array, size_t size)
{
	assert(array != NULL);

	unsigned int i;

	for (i = 1; i < size; i++)
		if (array[i] < array[i - 1])	// Om tv� element �r i fel ordning �r elementen ej sorterade
			return 0;
	return 1;
}

ElementType* createForwardSortedArray(size_t size)
{
	ElementType* array = malloc(sizeof(ElementType)*size);
	unsigned int i;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
			array[i] = i;

		assert(isSorted(array, size));
	}
	return array;
}

ElementType* createBackwardSortedArray(size_t size)
{
	ElementType* array = malloc(sizeof(ElementType)*size);
	unsigned int i;

	if (array != NULL)
	{
		for (i = 0; i < size; i++)
			array[i] = size - i;

		assert(!isSorted(array, size));
	}
	return array;
}

ElementType* createUnsortedArray(size_t size)
{
	srand(SEED); // Se till att varje osorterad array �r lika

	ElementType* array = createForwardSortedArray(size); // B�rja med en sorterad array
	unsigned int randomIndex1, randomIndex2;
	unsigned int i;

	if (array != NULL)
	{
		// Byt plats p� element slumpm�ssigt
		for (i = 0; i < size; i++)
		{
			// V�lj tv� slumpm�ssiga index och byt plats p� dem
			randomIndex1 = rand() % size;
			randomIndex2 = rand() % size;
			swapElements(&array[randomIndex1], &array[randomIndex2], NULL);
		}
	}
	return array;
}

void printArray(const ElementType* array, size_t size, FILE* file)
{
	assert(array != NULL);

	unsigned int i;
	printf("[");
	for (i = 0; i < size; i++)
		fprintf(file, "%u ", array[i]);
	printf("]\n");
}
