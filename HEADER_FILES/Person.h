#ifndef PERSON_H
#define PERSON_H

#define NAME_LENGTH 28
typedef struct
{
	int personalNumber;
	float weight;
	char name[NAME_LENGTH];
} Person;

Person getRandomPerson(void);
void printPerson(const Person* personToPrint);
int getPersonalNumber(const Person* person);
#endif
