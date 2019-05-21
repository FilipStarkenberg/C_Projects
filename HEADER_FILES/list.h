/* Laboration 2 - Datastrukturer och Algoritmer */
/* Lankad lista */

#ifndef LIST_H
#define LIST_H
#define _CRT_SECURE_NO_WARNINGS // For visual studio users
#include <stdio.h>
#include "Bucket.h"


typedef struct Bucket Data; // �ndra 'int' till n�got annat om du vill att dina lista ska lagra n�got annat �n just ints


/**********************************************
 * 		1. Nodtyp
 *      Kommentera bort exakt *EN* av structerna nedan
 *
 ***********************************************/


// Kommentera bort nedanst�ende rader om du vill g�ra en enkell�nkad lista
//typedef struct singleLinkedNode
//{
//	Data data;
//	struct node *next;
//} Node;



 // Kommentera bort nedanst�ende rader om du vill g�ra en dubbell�nkad lista
typedef struct doubleLinkedNode
{
	Data data;
	struct doubleLinkedNode *next;
	struct doubleLinkedNode *previous;
} Node;





/********************************************************
 * 		2. Listtyp
 *      Kommentera bort exakt *EN* av typedefarna nedan
 *
 ********************************************************/


// Kommentera bort nedanst�ende rad om du vill representera en lista som en nodpekare
typedef Node* List;

// Kommentera bort nedanst�ende rad om du vill representera en lista som en struct (det g�r bra att l�gga till fler medlemmar till structen)
//typedef struct list { Node* head; } List;

// Kommentera bort nedanst�ende rad om du vill representera en lista som en pekare till f�rsta och sista elementet
//typedef struct list { Node* head; Node* tail;} List;


/**********************************************************
* Interface
* Du ska _INTE_ gora forandringar i interfacet
*
***********************************************************/

//Returnera en tom lista
List createEmptyList(void);

//Returnerar 1 om listan ar tom, annars 0
int isEmptyList(const List list);

//Lagg till nod forst i listan
void addFirst(List *list, const Data data);

//lagg till nod sist i listan
void addLast(List *list, const Data data);

//Ta bort forsta noden i listan
void removeFirst(List *list);

//ta bort sista noden i listan
void removeLast(List *list);

//ta bort data ur listan (forsta forekomsten), returnera 0 om datat inte finns, annars 1
int removeElement(List *list, const Data data);

//Sok efter data i listan, returnera 1 om datat finns, annars 0.
int searchList(const List list, const Data data);

//returnera hur manga noder som finns i listan
int numberOfNodesInList(const List list);

//tom listan /ta bort allt data (alla noder) ur listan
void clearList(List *list);

//returnera forsta datat i listan
Data getFirstElement(const List list);

//returnera sista datat i listan
Data getLastElement(const List list);


#endif
