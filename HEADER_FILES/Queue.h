#ifndef QUEUE_H
#define QUEUE_H

typedef int Data;

/* 1. Välj implementation. *****************************/
/*    Avkommentera exakt en av dessa två rader.        */
#define QUEUE_LIST_IMP // Avkommentera denna rad för att implementera kön som en länkad lista
//#define QUEUE_ARRAY_IMP // Avkommentera denna rad för att implementera kön som en array


/* 2A. Om kön implementeras som en länkad lista *************************/
#ifdef QUEUE_LIST_IMP
#include "list.h"    // Er lista inkluderas
typedef List Queue;  // Ordet 'Queue' kommer att vara er listtyp
#else



/* 2B. Om kön implementeras som en array (cirkulär kö) ********************/
#ifdef QUEUE_ARRAY_IMP
#define MAXLENGTH 20
struct arrayQueue
{
	Data data[MAXLENGTH];  // Detta är arrayen av element

	/* 2B. Lägg till fler struct-medlemmar om det behövs */
};
typedef struct arrayQueue Queue; // Ordet 'Queue' kommer att vara denna struct-typ



/* Ignorera detta (men ta inte bort det) *************************************/
#else
typedef int Queue; // Används ej
#endif
#endif
/*****************************************************************************/


/* 3. Interface **************************************************************/
/* Detta får inte ändras på något vis. Typen 'Queue' kommer att bero på vilken */
/* Implementation ni valt.                                                     */

// Skapar en ny tom kö
Queue initializeQueue(void);

// Returnerar 1 om kön är tom, 0 annars
int queueIsEmpty(const Queue queue);

// Returnerar 1 om kön är full, 0 annars
int queueIsFull(const Queue queue);

// Lägger ett nytt element sist i kön
void enqueue(Queue* queue, const Data data);

// Tar bort elementet som är först i kön
void dequeue(Queue* queue);

// Returnerar elementet som är först i kön
Data front(const Queue queue);


#endif // Ska vara sist
