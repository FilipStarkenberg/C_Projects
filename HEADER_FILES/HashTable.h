#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Bucket.h"
#include "list.h"

//#include "List.h" // Avkommentera denna rad ifall du vill implementera Hashtabellen med länkade listor

typedef struct
{
	// Steg 1: Avkommentera exakt en av dessa rader

	//struct Bucket* table; // Avkommentera denna ifall ni vill implementera Hashtabellen med öppen adresering
	List* table;   // Avkommentera denna ifall ni vill implemenetera Hashtabellen som en array länkade listor

	unsigned int size; // Storleken på Hashtabellen
} HashTable;


// Interface //////////////////////////////////////////////////////////////////////////

HashTable createHashTable(unsigned int size);

// Sätter in paret {key,data} i Hashtabellen, om en nyckel redan finns ska värdet modifieras. Returnerar antalet krockar.
int insertElement(HashTable* htable, const Key key, const Value value);

// Tar bort datat med nyckel "key"
void deleteElement(HashTable* htable, const Key key);

// Returnerar en pekare till värdet som key är associerat med eller NULL om ingen sådan nyckel finns
const Value* lookup(const HashTable* htable, const Key key);

// Tömmer Hashtabellen
void freeHashTable(HashTable* htable);

// Ger storleken av Hashtabellen
unsigned int getSize(const HashTable* htable);

// Denna för att ni enkelt ska kunna visualisera en Hashtabell
void printHashTable(const HashTable* htable);

// Load factor är antalet fyllda "buckets" dividerat med storleken på tabellen
float getLoadFactor(const HashTable* htable);

#endif
