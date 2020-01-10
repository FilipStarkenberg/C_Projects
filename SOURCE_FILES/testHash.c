#define _CRT_SECURE_NO_WARNINGS // Beh�vs i Visual studio f�r att till�ta vissa funktioner
#include "HashTable.h"

#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "Person.h"

/*
	Uppgift 3: skriv en storlek p� tabellen som du tycker verkar ge en bra avv�gning mellan kollisioner och minneseffektivtet:

	Antal element: 50
	Tabellstorlek    : ???? <- fyll i ditt svar h�r
	Load Factor      : ???? <- fyll i ditt svar h�r
	Antal kollisioner: ???? <- fyll i ditt svar

*/







#define DATA_SIZE 50
#define NUMBER_OF_RUNS 1000

typedef struct {
	unsigned int tableSize;
	int collissions;
	float loadFactor;
} TableStatistics;


void compareHashTableSizes(unsigned int numberOfRuns, unsigned int sizeOfData);/*Valj hur manga olika hashtabellsstorlekar du vill jamfora. Lagger in samma data i samtliga storlekar och skriver ut antal krockar med respektive storlek*/
void runTests(unsigned int tableSize, unsigned int sizeOfData); /*Testar samtliga funktioner och olika fall f�r hashtabellen.*/
void interactiveHashTable(void); /*A menu to test your functions with manual data och random data*/

// Help functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int addRandomPersonToTable(HashTable* htable)
{
	Person person = getRandomPerson();
	insertElement(htable, person.personalNumber, person);
	assert(lookup(htable, person.personalNumber)->personalNumber == person.personalNumber); // Se till att personnummret returnerar namnet
	return person.personalNumber;
}

static void fillArrayWithRandomPersons(Person personArray[], int arraySize)
{
	int i;
	for (i = 0; i < arraySize; i++)
		personArray[i] = getRandomPerson();
}


static int addPersonsToTable(HashTable *htable, const Person *personArray, int amount)
{
	int collissions = 0, i;
	for (i = 0; i < amount; i++)
	{
		int key = personArray[i].personalNumber;
		collissions += insertElement(htable, key, personArray[i]);
		assert(lookup(htable, key) != NULL);
		assert(getPersonalNumber(lookup(htable, key)) == key);
	}
	return collissions;
}

static unsigned int getTableSizeFromUser(unsigned int minSize)
{
	unsigned int tableSize;

	do
	{
		printf("Enter size of hashtable (at least %d): ", minSize);
		scanf("%u", &tableSize);
	} while (tableSize < minSize);

	return tableSize;
}

static TableStatistics* createStatisticsArray(unsigned int tableCount, unsigned int minSize)
{
	TableStatistics* statisticsArray = (TableStatistics*)malloc(sizeof(TableStatistics)*tableCount);
	assert(statisticsArray != NULL);

	unsigned int i;
	for (i = 0; i < tableCount; i++)
	{
		unsigned int tableSize;
		do
		{
			printf("Enter size of table %d (at least %d): ", i + 1, minSize);
			scanf("%u", &tableSize);
		} while (tableSize < minSize);

		statisticsArray[i].tableSize = tableSize;
		statisticsArray[i].collissions = 0;
		statisticsArray[i].loadFactor = 0;
	}

	return statisticsArray;
}


static void createStatistics(TableStatistics statisticsArray[], const Person personArray[], unsigned int arraySize, unsigned int sizeOfData)
{
	unsigned int i;

	for (i = 0; i < arraySize; i++)
	{
		HashTable table = createHashTable(statisticsArray[i].tableSize);
		statisticsArray[i].collissions += addPersonsToTable(&table, personArray, sizeOfData); // Accumulate all collisions for all runs, will be averaged in presentation
		statisticsArray[i].loadFactor = getLoadFactor(&table);
		freeHashTable(&table);
	}

}

void compareHashTableSizes(unsigned int numberOfRuns, unsigned int sizeOfData)
{
	unsigned int tableCount;

	printf("How many hashtables do you want to compare: ");
	scanf("%d", &tableCount);
	if (tableCount <= 0)
	{
		printf("No tables selected\n");
		return;
	}


	TableStatistics* statisticsArray = createStatisticsArray(tableCount, sizeOfData);
	Person* personArray = (Person*)malloc(sizeof(Person)*sizeOfData);

	// Create statistics for the tables
	unsigned int i;
	for (i = 0; i < numberOfRuns; i++)
	{
		fillArrayWithRandomPersons(personArray, sizeOfData);
		createStatistics(statisticsArray, personArray, tableCount, sizeOfData);
	}

	free(personArray);

	// Show summary of statistics
	printf("\n-- Summary ----------------------\n");
	printf("Average collisions on %d runs. Inserted %d persons.\n", numberOfRuns, sizeOfData);

	for (i = 0; i < tableCount; i++)
	{
		unsigned int tableSize = statisticsArray[i].tableSize;
		int avgCollisions = statisticsArray[i].collissions / numberOfRuns;
		float loadFactor = statisticsArray[i].loadFactor;

		printf("Table %d (size %d) - average number of collisions: %d - load factor: %.2f\n", i + 1, tableSize, avgCollisions, loadFactor);
	}
	printf("----------------------------------\n\n");

}


static void askForString(const char* question, char *destination, int size)
{
	while (getchar() != '\n');
	printf("%s", question);
	fgets(destination, size, stdin);
	destination[strlen(destination) - 1] = '\0';
}

static void insertElementIntoTable(HashTable* table)
{
	int choice;
	printf("\n1 - Random data\n2 - Manual data\n\n");
	printf("Enter option: ");
	scanf("%d", &choice);
	Person personToAdd;

	switch (choice)
	{
	case 1:
		personToAdd = getRandomPerson();
		printf("Random\n%d: %s: %f\n", personToAdd.personalNumber, personToAdd.name, personToAdd.weight);
		break;
	case 2:
		askForString("Enter name: ", personToAdd.name, NAME_LENGTH);
		printf("Enter weight: ");
		scanf("%f", &personToAdd.weight);
		printf("Enter personal number (YYMMDD): ");
		scanf("%d", &personToAdd.personalNumber);
		break;
	default: printf("Invalid input\n");
		return;
	}

	int collisions = insertElement(table, personToAdd.personalNumber, personToAdd);
	if (collisions > 0)
		printf("Insertion created %d collisions\n", collisions);
	else
		printf("Insertion was collision free");
}

static void searchTable(HashTable* table)
{
	printf("Enter personal number (YYMMDD) to search for: ");
	int search;
	scanf("%d", &search);
	const Person* searchResult = lookup(table, search);

	if (searchResult == NULL)
		printf("%d could not be found in the table\n", search);
	else
		printf("Found\n%d: %s: %f\n", searchResult->personalNumber, searchResult->name, searchResult->weight);
}

static void deleteElementFromTable(HashTable* table)
{
	printf("Enter personal number (YYMMDD) to delete: ");
	int toDelete;
	scanf("%d", &toDelete);
	deleteElement(table, toDelete);
}

void interactiveHashTable(void)
{
	HashTable htable;
	htable = createHashTable(getTableSizeFromUser(1));
	int choice;

	do
	{
		printf("\n----------Menu Hashtable----------\n");
		printf("Current table size: %d. Current load factor: %.2f\n\n", getSize(&htable), getLoadFactor(&htable));
		printf("1 - Create New hashtable (and delete the old)\n");
		printf("2 - Insert element\n");
		printf("3 - Print hashtable\n");
		printf("4 - Search for element\n");
		printf("5 - Delete element\n");
		printf("6 - Back to main menu\n\n");
		printf("Enter option: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: freeHashTable(&htable); htable = createHashTable(getTableSizeFromUser(1)); break;
		case 2: insertElementIntoTable(&htable); break;
		case 3: printHashTable(&htable); break;
		case 4: searchTable(&htable); break;
		case 5: deleteElementFromTable(&htable); break;
		case 6: freeHashTable(&htable); break;
		default: printf("Invalid input\n"); break;
		}

	} while (choice != 6);
}


int main(void)
{

	int choice;
	do
	{
		printf("-- Main Menu --\n\n");
		printf("1. interactive hashtable menu\n");
		printf("2. run tests\n");
		printf("3. compare table sizes\n");
		printf("4. quit\n\n");

		printf("Enter option: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: interactiveHashTable(); break;
		case 2: runTests(75, DATA_SIZE); break;
		case 3: compareHashTableSizes(NUMBER_OF_RUNS, DATA_SIZE); break;
		default: printf("Invalid option\n\n"); break;
		}
	} while (choice != 4);

	return 0;
}

void runTests(unsigned int tableSize, unsigned int dataSize)
{
	assert(dataSize < tableSize);
	printf("Init htable\n");
	HashTable htable = createHashTable(tableSize);
	printf("Free htable\n");
	freeHashTable(&htable); // Make sure allocation/deallocation works correctly
	assert(getSize(&htable) == 0);

	printf("Init htable\n");
	htable = createHashTable(tableSize);

	srand((unsigned int)time(0));

	assert(getSize(&htable) == tableSize);

	Person* personArray = (Person*)malloc(sizeof(Person)*dataSize);
	assert(personArray != NULL);
	fillArrayWithRandomPersons(personArray, (int)dataSize);
	addPersonsToTable(&htable, personArray, (int)dataSize);
	assert(getLoadFactor(&htable) > 0.1 && getLoadFactor(&htable) < 1);
	printf("Passed loadFactor\n");

	// Remove about a 1/5 of the added people
	unsigned int i;
	for (i = 0; i < dataSize / 5; i++)
	{
		int personalNumber = getPersonalNumber(&personArray[i]);
		deleteElement(&htable, personalNumber);
		assert(lookup(&htable, personalNumber) == NULL);
	}

	// Add some more
	for (i = 0; i < dataSize / 5; i++)
		addRandomPersonToTable(&htable);

	printHashTable(&htable);
	printf("Freeing hash table\n");
	freeHashTable(&htable);
	assert(getSize(&htable) == 0);
	assert(getLoadFactor(&htable) == 0.0); // If this triggers you may have a division by zero problem

	printf("All tests passed!\n\n");
}
