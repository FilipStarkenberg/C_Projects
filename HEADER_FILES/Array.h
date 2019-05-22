#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdio.h>

/********************************************************

DVA104, Lab 5, Array.h
Innehåller funktioner för att hantera dynamiska arrayer.

Stefan Bygde VT2016

*********************************************************/

#define SEED 245802 // Detta gör att vi får samma osorterade array varje gång, för att vi lätt ska kunna jämföra. Man kan ändra på denna till vad som helst om man vill
typedef unsigned int ElementType;

// Avgör om "array" är sorterad eller ej
int isSorted(const ElementType* array, size_t size);

// Skapar arrayer av given storlek och sortering
// Notera att dessa arrayer är dynamiskt allokerade och att minnet behöver frigöras när man använt dem färdigt
ElementType* createForwardSortedArray(size_t size);
ElementType* createBackwardSortedArray(size_t size);
ElementType* createUnsortedArray(size_t size);

// Skriver en array till fil
void printArray(const ElementType* array, size_t size, FILE* file);



#endif
