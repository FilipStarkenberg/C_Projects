#ifndef STATISTICS_H
#define STATISTICS_H
#include <stdio.h>

/********************************************************

   DVA104, Lab 5, Statistics.h
   Inneh�ller funktioner f�r att h�lla reda p�
   statistik �ver hur m�nga byten och j�mf�relser man g�r
   i sorteringsalgoritmer.

   Stefan Bygde VT2016

*********************************************************/

struct statistics
{
	unsigned int comparisons;
	unsigned int swaps;
};

typedef struct statistics Statistics;

// Nollst�ller statistiken
void resetStatistics(Statistics* statistics);

// Skriver statistiken till fil
void printStatistics(const Statistics* statistics, FILE* file);

// J�mf�relseoperatorer med statistik
int lessThan(int element1, int element2, Statistics* statistics); // sant om element1 < element2
int greaterThan(int element1, int element2, Statistics* statistics); // sant om element1 > element2
int equalTo(int element1, int element2, Statistics* statistics); // sant om element1 == element2
int lessThanOrEqualTo(int element1, int element2, Statistics* statistics); // sant om element1 <= element2
int greaterThanOrEqualTo(int element1, int element2, Statistics* statistics); // sant om element >= element2

// Byter plats p� element1 och element2 med statistik
void swapElements(unsigned int* element1, unsigned int* element2, Statistics* statistics);

#endif
