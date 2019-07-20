#include "Set.h"
#include <assert.h>


Set initializeSet(void)
{
	Set set = createEmptyList();
	return set; // Ersätt med rätt returvärde
}

void addToSet(Set* set, const Data element)
{
	// Precondition: set är inte full
	assert(!isSetFull(*set));
	if(isInSet(*set, element)) return;
	addFirst(set, element);
	// Tips: tänk på att inte lägga till elementet om det redan finns i *set

	// Postcondition: 'element' finns i set (tips: använd isInSet() för att verifiera)
	assert(isInSet(*set, element));
}

void removeFromSet(Set* set, const Data element)
{
	removeElement(set, element);
	assert(!isInSet(*set, element));
	// Postcondition: 'element' finns INTE i set (tips: använd isInSet() för att verifiera)
}

int isSetFull(const Set set)
{
	return 0; // Ersätt med rätt returvärde
}

int isInSet(const Set set, const Data element)
{
	return searchList(set, element); // Ersätt med rätt returvärde
}
