 #ifndef SET_H
#define SET_H

typedef int Data;

/* 1. V�lj implementation. *****************************/
/*    Avkommentera exakt en av dessa tv� rader.        */

#define SET_LIST_IMP // Avkommentera denna rad om ni vill implementera set som en l�nkad lista
//#define SET_ARRAY_IMP // Avkommentera denna rad om ni vill implementera set som en array

/* 2A. Om Set implementeras som en l�nkad lista *************************/
#ifdef SET_LIST_IMP
#include "list.h"	// Er lista inkluderas
typedef List Set;   // Ordet 'Set' kommer att referera till er listtyp
#else



/* 2B. Om Set implementeras som en array ********************************/
#ifdef SET_ARRAY_IMP
#define MAXLENGTH 20
struct arraySet
{
	Data data[MAXLENGTH];
	/*2B: l�gg till fler struct-medlemmar ifall det beh�vs */
};
typedef struct arraySet Set; // Ordet 'Set' kommer att referera till denna struct



/* Ignorera detta (men ta inte bort det) *************************************/
#else
typedef int Set; // Anv�nds ej
#endif
#endif
/*****************************************************************************/




/* 3. Interface ****************************************************************/
/* Detta f�r inte �ndras p� n�got vis. Typen 'Set' kommer att bero p� vilken   */
/* Implementation ni valt.                                                     */

// Skapar ett nytt set som inte inneh�ller n�gra element
Set initializeSet(void);

// L�gger till ett element till settet, om elementet redan finns h�nder inget
void addToSet(Set* set, const Data element);

// Tar bort ett element till settet, om elementet inte finns h�nder inget
void removeFromSet(Set* set, const Data element);

// Returerar 1 ifall 'element' finns i 'set' och 0 annars
int isInSet(const Set set, const Data element);

// Returnerar 1 ifall det inte g�r att l�gga till fler element till set, 0 annars
int isSetFull(const Set set);

#endif
