#ifndef DSTRING_H
#define DSTRING_H
#include <stdio.h>

typedef char* DString;

/* Returnerar en sträng som innehåller samma text som textsträngen 'str'.
  Den returnerade strängen är dynamiskt allokerad (dvs, på heapen) */
DString dstring_initialize(const char* str);

/* Slår ihop originalsträngen med source */
int dstring_concatenate(DString* destination, DString source);

/* Förkortar *destination så att den innehåller högst truncatedLength tecken
  Om 'truncatedLength' är längre än strängens längd händer inget */
void dstring_truncate(DString* destination, unsigned int truncatedLength);

/* Skriver strängen till en textfil.
   Textfilen förväntas redan vara öppnad och fortsätter vara öppnad efter anropet */
void dstring_print(DString stringToPrint, FILE* textfile);

/* Frigör minnet för en dynamisk sträng och sätter strängen (*stringToDelete) till NULL */
void dstring_delete(DString* stringToDelete);

#endif
