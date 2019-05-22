#define _CRT_SECURE_NO_WARNINGS
#include "HashTable.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>

#define UNUSED 0	// Anv�nds f�r att markera en ledig plats i Hashtabellen vid �ppen adressering


static int hash(Key key, int tablesize)
{
	return (key % tablesize); // Ers�tt med r�tt v�rde
}

static Data createBucket(Key key, Value value){
	Data newBucket;
	newBucket.key = key;
	newBucket.value = value;
	return newBucket;
}


HashTable createHashTable(unsigned int size)
{
	HashTable htable;
	htable.size = size;
	htable.table = (List*) malloc(sizeof(List) * size);
	for(unsigned int i = 0; i < htable.size; i++){
		htable.table[i] = createEmptyList();
	}
	// Initiera tabellen h�r
	return htable;
}

int insertElement(HashTable* htable, const Key key, const Value value)
{
	unsigned int thash = hash(key, htable->size);
	assert(thash < htable->size);
	Data newBucket = createBucket(key, value);
	addLast(&htable->table[thash], newBucket);
	//printf("Test\n");
	return numberOfNodesInList(htable->table[thash]) -1;
	/*if(isEmptyList(htable->table[thash])){
		addLast(&htable->table[thash], newBucket);
	}
	else if(searchList(htable->table[thash], newBucket));
	else{
		addLast(&htable->table[thash], newBucket);
	}
	printf("Insert Done\n");
	return 0; // Retunera antal kollisioner
	*/
}

void deleteElement(HashTable* htable, const Key key)
{
	removeElement(&htable->table[hash(key, htable->size)], createBucket(key, getRandomPerson()));
	// Post-condition: key finns ej i tabellen, anv�nd lookup() f�r att verifiera
	assert(lookup(htable, key) == NULL);
}

const Value* lookup(const HashTable* htable, const Key key)
{
	if(isEmptyList(htable->table[hash(key, htable->size)])){
		return NULL;
	}
	else{ //if(searchList(htable->table[hash(key, htable->size)], createBucket(key, getRandomPerson()))){
		List list;
		for(list = htable->table[hash(key, htable->size)]; list->data.key != key && list->next != NULL; list = list->next);
		if(list->data.key == key){
			return &list->data.value;
		}
	}
	return NULL; // Ers�tt med r�tt v�rde. NULL ska returneras om key inte finns
}

// Denna funktion �r f�rdigimplementerad, ni beh�ver inte g�ra n�got h�r
unsigned int getSize(const HashTable* htable)
{
	return htable->size;
}

void freeHashTable(HashTable* htable)
{
	for(int i = 0; i < htable->size; i++){
		if(!isEmptyList(htable->table[i]))
			clearList(&htable->table[i]);
	}
	free(htable->table);
	htable->table = NULL;
	htable->size = 0;
    // Post-condition: storleken p� tabellen �r 0
}

void printHashTable(const HashTable* htable)
{
	// Ni kan anv�nda printPerson() fr�n person.h f�r att skriva ut en person
}


float getLoadFactor(const HashTable* htable)
{
	if(htable->size == 0) return 0.0;
	int counter = 0;
	for(int i = 0; i < htable->size; i++){
		if(!isEmptyList(htable->table[i])) counter++;
	}
	return (float) counter/htable->size; // Ers�tt med r�tt v�rde
}
