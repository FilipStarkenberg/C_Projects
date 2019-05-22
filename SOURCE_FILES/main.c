#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

#include "Statistics.h"
#include "Array.h"
#include "SortingAlgorithms.h"

void printAlgorithmBanner(SortingAlgorithm algorithm, FILE* file);

int main(void)
{
	unsigned int i;
	ElementType* unsortedArray[NUMBER_OF_SIZES], *forwardArray[NUMBER_OF_SIZES], *backwardArray[NUMBER_OF_SIZES];
	unsigned int sizes[NUMBER_OF_SIZES] = { 10 , 20 , 40 }; // Ändra dessa värden om ni vill ändra storlekar på arrayen
	SortingArray forward[NUMBER_OF_SIZES], backward[NUMBER_OF_SIZES], unsorted[NUMBER_OF_SIZES];
	char filename[] = "result.txt";
	FILE* file;

	// Skapa osorterade, frammåtsorterade samt bakåtsorterade arrayer av olika storlekar
	for (i = 0; i < NUMBER_OF_SIZES; i++)
	{
		unsortedArray[i] = createUnsortedArray(sizes[i]);
		forwardArray[i] = createForwardSortedArray(sizes[i]);
		backwardArray[i] = createBackwardSortedArray(sizes[i]);
 	}
	printf("Sorting...\n");

	file = fopen(filename, "w");
	if (file)
	{
		for (i = 0; i < SORTING_ALGORITHMS; i++)
		{
			SortingAlgorithm algorithm = (SortingAlgorithm)i;

			if (isImplemented(algorithm))
			{
				printAlgorithmBanner(algorithm, file);

				fprintf(file, "Unsorted: \n");
				sortAndPrint(unsorted, algorithm, unsortedArray, sizes, file);

				fprintf(file, "Sorted: \n");
				sortAndPrint(forward, algorithm, forwardArray, sizes, file);

				fprintf(file, "Reverse sorted: \n");
				sortAndPrint(backward, algorithm, backwardArray, sizes, file);

				freeArray(unsorted);
				freeArray(forward);
				freeArray(backward);
				printf("%s done...\n", getAlgorithmName(algorithm));
			}
		}
		printf("The result is placed in: %s", filename);
		fclose(file);
	}
	else
	{
		printf("could not create file %s", filename);
		return -1;
	}
	return 0;
}


void printAlgorithmBanner(SortingAlgorithm algorithm, FILE* file)
{
	assert(file != NULL);
	fprintf(file, "---------------------------------------------\n");
	fprintf(file, "--------       %s       ---------\n", getAlgorithmName(algorithm));
	fprintf(file, "---------------------------------------------\n\n");
}

