#include <assert.h>
#include <string.h>

#include "dstring.h"

/* Detta program testar funktionaliteten för ADTn DString */
int main(void)
{
	DString str1, str2;
	str1 = dstring_initialize("Department of ");
	str2 = dstring_initialize("Redundancy ");
	dstring_concatenate(&str1, str2); // Slår ihop str1 och str2 och lägger resultatet i str1. Str1 innehåller nu "Department of Redundancy"

	/* Om någon av dessa misslyckas så är det något fel på er implementation
	   Använd debuggern för att ta reda på vad */

	assert(str1 != NULL);
	assert(str2 != NULL);
	assert(strlen(str2) == 11); 
	assert(strlen(str1) == 25); // Den sammanslagna strängen ska ha längden 25

	/* Följande ska skriva ut "Department of Redundancy Department" på skärmen
	   stdout är en textfil som representerar konsollfönstret */

	dstring_print(str1, stdout);	// Skriver ut "Department of Redundancy" 
	dstring_truncate(&str1, 10);	// Förkortar str1 så att den bara innehåller de 10 första tecknen i strängen, dvs "Department"
	dstring_print(str1, stdout);	// Skriver ut "Department"

	/* Frigör det dynamiskt allokerade minnet för strängarna */
	dstring_delete(&str1);
	dstring_delete(&str2);

	/* Se till att strängarna blivit nollställda */
	assert(str1 == NULL);
	assert(str2 == NULL);
	return 0;
}