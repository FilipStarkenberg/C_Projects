#define _CRT_SECURE_NO_WARNINGS // Behövs i Visual studio för att tillåta vissa funktioner
#include "Person.h"
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

static void getRandomName(char* name)
{
	assert(name != NULL);

	const char* names[] = { "Stefan", "Anna" , "Bengt", "Sture", "Johan", "Therese", "Alva", "Lisa", "Emma", "Linnea", "Lena", "Johanna",
		"Moa", "Per", "Alex", "Fredrik", "Kent", "Tobias", "Malin", "Sara", "Ida", "Hanna", "Sixten", "Frans" };

	const int numberOfNames = sizeof(names) / sizeof(char*);
	int index = rand() % numberOfNames;
	strcpy(name, names[index]);
}

static int getRandomPersonalNumber(void)
{
	int day = rand() % 30 + 1; // För enkelhetens skull antar vi att vaje månad har 30 dagar (blir vissa omöjliga datum i februari, men det är inte viktigt här)
	int month = rand() % 12 + 1;
	int year = rand() % 60 + 40;
	return day + 100 * month + 10000 * year;
}

Person getRandomPerson(void)
{
	Person randomPerson;
	getRandomName(randomPerson.name);
	randomPerson.personalNumber = getRandomPersonalNumber();
	randomPerson.weight = (float)(rand() % 70 + 45);
	return randomPerson;
}

void printPerson(const Person* personToPrint)
{
	assert(personToPrint != NULL);
	printf("%d: %s, weight: %.1f ", personToPrint->personalNumber, personToPrint->name, personToPrint->weight);
}

int getPersonalNumber(const Person* person)
{
	assert(person != NULL);
	return person->personalNumber;
}
