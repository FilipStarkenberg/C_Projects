#include "dstring.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


DString dstring_initialize(const char* str)
{
	// Precondition: str �r ej NULL
	assert(str != NULL);
	/* Tips:
	   - Allokera tillr�ckligt med minne f�r att f� plats med str
	   - Det �r till�tet att anv�nda inbyggda str�ngfunktioner (som t.ex strcpy())
	   - Kom ih�g att anv�nda assert() */
	   DString returnString = (DString)malloc(sizeof(DString) * (strlen(str) + 1));
	   assert(returnString != NULL);
	   strcpy(returnString, str);
	   returnString[strlen(returnString)] = '\0';
	// Postcondition: returv�rdet inneh�ller samma str�ng som 'str'

	return returnString; // Ers�tt denna rad. Den �r just nu med f�r att programmet ska kompilera
}

int dstring_concatenate(DString* destination, DString source)
{
	// Precondition: destination �r ej NULL
	// Precondition: *destination �r ej NULL
	// Precondition: source �r ej NULL
	assert(destination != NULL);
	assert(*destination != NULL);
	assert(source != NULL);
	/* Tips:
	   - T�nk p� att *destination redan �r en dynamiskt allokerad str�ng
	   - T�nk p� att vi kommer att beh�va allokera mer minne f�r att f� plats med den h�r l�ngre str�ngen.*/
	DString temp = (DString) realloc(*destination, sizeof(DString) * (strlen(*destination) + strlen(source) + 1));
	assert(temp != NULL);
	*destination = temp;
	strcat(*destination, source);
	(*destination)[strlen(*destination)] = '\0';
	// Post condition: *destination inneh�ller den gamla str�ngen ihopslagen med source
	return (int)strlen(*destination); // Ers�tt denna rad. Den �r just nu med f�r att programmet ska kompilera.
}

void dstring_truncate(DString* destination, unsigned int truncatedLength)
{
	// Precondition: destination �r ej NULL, *destination �r ej NULL
	assert(destination != NULL);
	assert(*destination != NULL);
	assert(strlen(*destination) > truncatedLength);

	DString Stemp = (DString) malloc(sizeof(DString) * (truncatedLength + 1));
	strncpy(Stemp, *destination, (size_t) truncatedLength);

	//Stemp[truncatedLength] = 0;
	//DString DStemp = dstring_initialize(Stemp);
	dstring_delete(destination);
	*destination = Stemp;
	(*destination)[strlen(*destination)] = '\0';
	//free(Stemp);
	//Stemp = NULL;

	/* Tips:namelen
	   - Anv�nd realloc f�r att frig�ra det �verfl�diga minnet
	   - gl�m inte nolltermineringen */

	// Postcondition: *destination �r inte l�ngre �n 'truncatedLength' tecken
	assert(!(strlen(*destination) > truncatedLength));
}

void dstring_print(DString str, FILE* textfile)
{
	// Precondition: textfile �r inte NULL
	assert(textfile != NULL);
	fprintf(textfile, str);
	fprintf(textfile, "\n");
	/* filpekaren f�r inte st�ngas, filen ska fungera som vanligt efter anropet */
}

void dstring_delete(DString* stringToDelete)
{
	// Precondition: stringToDelete �r inte NULL
	assert(stringToDelete != NULL);
	free(*stringToDelete);
	*stringToDelete = NULL;
	// Postcondition: *stringToDelete -�R- NULL
	assert(*stringToDelete == NULL);
}
