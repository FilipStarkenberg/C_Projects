#ifndef STACK_H
#define STACK_H

typedef int Data;

/* 1. V�lj implementation. *****************************/
/*    Avkommentera exakt en av dessa tv� rader.        */

//#define STACK_LIST_IMP // Avkommentera denna rad om stacken ska implementeras som en l�nkad lista
#define STACK_ARRAY_IMP // Avkommentera denna rad om stacken ska implementeras som en array



/* 2A. Om stacken implementeras som en l�nkad lista *************************/

#ifdef STACK_LIST_IMP
#include "list.h"		// Er lista inkluderas
typedef List Stack;     // Ordet 'Stack' kommer att vara er listtyp
#else



/* 2B. Om stacken implementeras som en array ********************************/

#ifdef STACK_ARRAY_IMP
#define MAXLENGTH 20
struct arrayStack
{
	Data elements[MAXLENGTH];
	int size;				// Detta �r arrayen av element

	/* 2B: L�gg till fler struct-medlemmar om det beh�vs */
};
typedef struct arrayStack Stack;	// Ordet 'Stack' kommer att vara denna struct-typ



/* Ignorera detta (men ta inte bort det) *************************************/
#else
typedef int Stack;	// Ingen implementation, anv�nds ej
#endif
#endif
/*****************************************************************************/


/* 3. Interface ****************************************************************/
/* Detta f�r inte �ndras p� n�got vis. Typen 'Stack' kommer att bero p� vilken */
/* Implementation ni valt.                                                     */

// Skapar en ny tom stack
Stack initializeStack(void);

// Returnerar 1 om stacken �r tom, 0 annars
int stackIsEmpty(const Stack stack);

// Returnerar 1 om stacken �r full, 0 annars
int stackIsFull(const Stack stack);

// L�gger ett element �verst p� stacken
void push(Stack* pStack, const Data element);

// Tar bort det �versta elementet fr�n stacken
void pop(Stack* pStack);

// Returnerar det �versta elementet p� stacken
Data peekStack(const Stack stack);


#endif // Ska vara sist
