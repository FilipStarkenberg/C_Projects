#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include "BSTree.h"
#include <stdio.h>

void testTree(void)
{
	BSTree tree = emptyTree();
	assert(isEmpty(tree));

	// S�tt in 7 element i tr�det
	int arr[7] = {5,10,1,3,7,18,20}, i;
	for (i = 0; i < 7; i++)
	{
		insertSorted(&tree, arr[i]);
	}
	for (i = 0; i < 7; i++)
	{
		// Verifiera att alla element finns i tr�det
		assert(find(tree, arr[i]));
	}

	assert(numberOfNodes(tree) == 7);
	assert(depth(tree) == 4); // Om vi s�tter in noderna i denna ordning blir djupet 4
	assert(minDepth(tree) == 3); // Med 7 noder �r minimidjupet 3

	removeElement(&tree, 18); // Tar bort ett element med ett barn
	removeElement(&tree, 5); // Tar bort ett element med tv� barn


	assert(numberOfNodes(tree) == 5); // Tv� noder har blivit borttagna

	// Verifiera att talen blivit borttagna
	assert(!find(tree, 18));
	assert(!find(tree, 5));

	// Addera 10 element s� att tr�det blir obalancerat
	for (i = 0; i < 10; i++)
		insertSorted(&tree, i+100);

	assert(numberOfNodes(tree) == 10 + 5);


	balanceTree(&tree);
	assert(numberOfNodes(tree) == 10 + 5); // Verifiera att antalet noder �r detsamma
	assert(depth(tree) == minDepth(tree)); // Verifiera att tr�det �r balancerat

	printPreorder(tree);
	printf("\n");
	printInorder(tree);
	printf("\n");
	printPostorder(tree);
	printf("\n");

	// T�m tr�det och kontrollera att det �r tomt
	freeTree(&tree);
	assert(isEmpty(tree));
	assert(numberOfNodes(tree) == 0);
	assert(depth(tree) == 0);
}


int main(void)
{
	testTree();
	printf("Test compleeted\n");
}
