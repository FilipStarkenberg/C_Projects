#ifndef STATISTICS_H
#define STATISTICS_H
#include <stdio.h>

/********************************************************
   
   DVA104, Lab 5, Statistics.h
   Innehåller funktioner för att hålla reda på 
   statistik över hur många byten och jämförelser man gör 
   i sorteringsalgoritmer.

   Stefan Bygde VT2016 

*********************************************************/

struct statistics
{
	unsigned int comparisons;
	unsigned int swaps;
};

typedef struct statistics Statistics;

// Nollställer statistiken
void resetStatistics(Statistics* statistics);

// Skriver statistiken till fil
void printStatistics(const Statistics* statistics, FILE* file);

// Jämförelseoperatorer med statistik
int lessThan(unsigned int element1, unsigned int element2, Statistics* statistics); // sant om element1 < element2
int greaterThan(unsigned int element1, unsigned int element2, Statistics* statistics); // sant om element1 > element2
int equalTo(unsigned int element1, unsigned int element2, Statistics* statistics); // sant om element1 == element2
int lessThanOrEqualTo(unsigned int element1, unsigned int element2, Statistics* statistics); // sant om element1 <= element2
int greaterThanOrEqualTo(unsigned int element1, unsigned int element2, Statistics* statistics); // sant om element >= element2

// Byter plats på element1 och element2 med statistik
void swapElements(unsigned int* element1, unsigned int* element2, Statistics* statistics);

#endif