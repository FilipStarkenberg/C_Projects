#include "Set.h"
#include <assert.h>


Set initializeSet(void)
{
	Set set = createEmptyList();
	return set; // Ers�tt med r�tt returv�rde
}

void addToSet(Set* set, const Data element)
{
	// Precondition: set �r inte full
	assert(!isSetFull(*set));
	if(isInSet(*set, element)) return;
	addFirst(set, element);
	// Tips: t�nk p� att inte l�gga till elementet om det redan finns i *set

	// Postcondition: 'element' finns i set (tips: anv�nd isInSet() f�r att verifiera)
	assert(isInSet(*set, element));
}

void removeFromSet(Set* set, const Data element)
{
	removeElement(set, element);
	assert(!isInSet(*set, element));
	// Postcondition: 'element' finns INTE i set (tips: anv�nd isInSet() f�r att verifiera)
}

int isSetFull(const Set set)
{
	return 0; // Ers�tt med r�tt returv�rde
}

int isInSet(const Set set, const Data element)
{
	return searchList(set, element); // Ers�tt med r�tt returv�rde
}
