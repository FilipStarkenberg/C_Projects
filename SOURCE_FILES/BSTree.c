#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "BSTree.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>


int numberOfNodes(const BSTree tree);

// Statiska hj�lpfunktioner /////////////////////////////////////////////////////////////

static int compare( const void* a, const void* b)
{
     int int_a = * ( (int*) a );
     int int_b = * ( (int*) b );

     if ( int_a == int_b ) return 0;
     else if ( int_a < int_b ) return -1;
     else return 1;
}

// Skapar en tr�dnod med det givna datat samt allokerar minne f�r det
static struct treeNode* createNode(int data)
{
	BSTree tree = (BSTree)malloc(sizeof(BSTree));
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return tree; // Ers�tt med r�tt returv�rde
}


static int isInArray(int * array, int data, int size){
	for(int i = 0; i < size; i++){
		if(array[i] == data){
			return 1;
		}
	}
	return 0;
}

static void writeSortedToArrayHelper(const BSTree tree, int * array, int* counter) {
	if(tree->left != NULL){
		writeSortedToArrayHelper(tree->left, array, counter);
	}
    array[*counter] = tree->data;
    ++*counter;
	if(tree->right != NULL){
		writeSortedToArrayHelper(tree->right, array, counter);
	}

}
// Returnerar en dynamiskt allokerad array som inneh�ller tr�dets data sorterat
static int* writeSortedToArray(const BSTree tree, int* sizeOut)
{
	assert(!isEmpty(tree));
	int size = numberOfNodes(tree);
	int* array = (int*)malloc(sizeof(int)*size);
	int counter = 0;
	writeSortedToArrayHelper(tree, array, &counter);
	//qsort(array, size, sizeof(int), compare);
    *sizeOut = size;
	return array;
}

static void numberOfNodesHelper(const BSTree tree, int* counter){
	(*counter)++;
	if(tree->left != NULL){
		numberOfNodesHelper(tree->left, counter);
	}
	if(tree->right != NULL){
		numberOfNodesHelper(tree->right, counter);

	}
}

static void depthHelper(const BSTree tree, int* counter, int* max){
	(*counter)++;
	if(*counter > *max) *max = *counter;
	if(tree->left != NULL){
		depthHelper(tree->left, counter, max);
		(*counter)--;
	}
	if(tree->right != NULL){
		depthHelper(tree->right, counter, max);
		(*counter)--;
	}
}

static void insertSortedHelper(BSTree *tree, int data){
	if(data > (*tree)->data){
		if((*tree)->right != NULL){
			insertSortedHelper(&((*tree)->right), data);
		}
		else{
			BSTree newNode = createNode(data);
			(*tree)->right = newNode;
		}
	}
	if(data < (*tree)->data){
		if((*tree)->left != NULL){
			insertSortedHelper(&((*tree)->left), data);
		}
		else{
			BSTree newNode = createNode(data);
			(*tree)->left = newNode;
		}
	}
}
static void findHelper(BSTree tree, int data, int* out){
	if(*out == 1) return;
	if(data == tree->data){
		*out = 1;
		return;
	}
	if(tree->left != NULL){
		findHelper(tree->left, data, out);
	}
	if(tree->right != NULL){
		findHelper(tree->right, data, out);
	}
}
static void findNodeWithDataHelper(BSTree tree, int data, BSTree* node){
	if(*node != NULL) return;
	if(tree->data == data){
		*node = tree;
		return;
	}

	if(tree->left != NULL){
		if(data == tree->left->data){
			*node = tree;
			return;
		}
	}
	if(tree->right != NULL){
		if(data == tree->right->data){
			*node = tree;
			return;
		}
	}
	if(tree->left != NULL && data < tree->data){
		findNodeWithDataHelper(tree->left, data, node);
	}
	if(tree->right != NULL && data > tree->data){
		findNodeWithDataHelper(tree->right, data, node);
	}
}

static BSTree findNodeWithData(BSTree tree, int data){
	BSTree node = NULL;
	findNodeWithDataHelper(tree, data, &node);
	assert(node != NULL);
	return node;
}

static int numberOfChilds(const BSTree tree){
	int counter = 0;
	if(tree->left != NULL){
		counter++;
	}
	if(tree->right != NULL){
		counter++;
	}
	return counter;
}

static void findLowest(BSTree tree, int* out){
	assert(tree != NULL);
	*out = tree->data;
	if(tree->left != NULL){
		findLowest(tree->left, out);
	}
}

static void findHighest(BSTree tree, int* out){
	assert(tree != NULL);
	*out = tree->data;
	if(tree->right != NULL){
		findHighest(tree->right, out);
	}
}

static int findBestNode(BSTree tree){
	assert(numberOfChilds(tree) == 2);
	int node1;
	int node2;
	findLowest(tree->right, &node1);
	findHighest(tree->left, &node2);
	if(abs(node1 - tree->data) < abs(node2 - tree->data)){
		return node1;
	}
	else{
		return node2;
	}
}



// Bygger upp ett sorterat balancerat tr�d fr�n en sorterad array
void buildTreeSortedFromArray(BSTree* tree, int* arr, int size)
{
    if(size > 0){
        int mid = (size -1)/2;
        *tree = createNode(arr[mid]);
        buildTreeSortedFromArray(&(*tree)->left, arr, mid);
        buildTreeSortedFromArray(&(*tree)->right, arr + mid + 1, size - (mid + 1));
    }
}

// Implementation av tr�det ////////////////////////////////////////////////////////

BSTree emptyTree(void)
{
	return NULL; // Denna funktion �r klar
}

int isEmpty(const BSTree tree)
{
	if(tree == NULL) return 1;
	return 0; // Ers�tt med r�tt returv�rde
}

void insertSorted(BSTree* tree, int data)
{
	if(isEmpty(*tree)){
		BSTree newNode = createNode(data);
		*tree = newNode;
	}
	else{
		insertSortedHelper(tree, data);
	}
	assert(find(*tree, data));
	// Post-condition: data finns i tr�det
}

int find(const BSTree tree, int data)
{
	int found = 0;
	findHelper(tree, data, &found);
	return found;
}

int numberOfNodes(const BSTree tree)
{
	if(isEmpty(tree)) return 0;
	int counter = 0;
	numberOfNodesHelper(tree, &counter);

	return counter;
}

int depth(const BSTree tree)
{
	int depth = 0;
	int counter = 0;
    if(tree == NULL) return 0;
	depthHelper(tree, &counter, &depth);
	return depth;
}

int minDepth(const BSTree tree)
{
	return (int) ceil(log2(numberOfNodes(tree)+1));
}

void balanceTree(BSTree* tree)
{
    int size;
	int * array = writeSortedToArray(*tree, &size);
	freeTree(tree);
	buildTreeSortedFromArray(tree, array, size);
    free(array);
	// F�rslag p� algoritm:
	// - �verf�r tr�det till en dynamiskt allokerad array med writeSortedToArray()
	// - t�m tr�det med freeTree()
	// - bygg upp tr�det rekursivt fr�n arrayen med buildTreeSortedFromArray()
	// - frig�r minne f�r den dynamiskt allokerade arrayen
	// Post-conditions:
	// - tree har lika m�nga noder som tidigare
	// - djupet f�r tr�det �r samma som minimumdjupet f�r tr�det
}


void freeTree(BSTree* tree)
{
    if((*tree)->right != NULL)
        freeTree(&((*tree)->right));
    if((*tree)->left != NULL)
        freeTree(&((*tree)->left));
    free(*tree);
    *tree = NULL;
    assert(isEmpty(*tree));
}

void removeElement(BSTree* tree, int data)
{
	if(!find(*tree, data)) return;
	BSTree subTree = findNodeWithData(*tree, data);
	BSTree nodeToRemove = *tree;
	int LR = -1;
	if(subTree->left != NULL){
		if(subTree->left->data == data){
			nodeToRemove = subTree->left;
			LR = 0;
		}
	}
	if(subTree->right != NULL){
		if(subTree->right->data == data){
			nodeToRemove = subTree->right;
			LR = 1;
		}
	}
	//Leaf removal
	if(numberOfChilds(nodeToRemove) == 0){
		free(nodeToRemove);
		if(LR){
			subTree->right = NULL;
		}
		else{
			subTree->left = NULL;
		}
		return;
	}

	//One child removal
	else if(numberOfChilds(nodeToRemove) == 1){
		if(LR){
			if(nodeToRemove->left != NULL){
				subTree->right = nodeToRemove->left;
			}
			else{
				subTree->right = nodeToRemove->right;
			}
		}
		else{
			if(nodeToRemove->left != NULL){
				subTree->left = nodeToRemove->left;
			}
			else{
				subTree->left = nodeToRemove->right;
			}
		}
		free(nodeToRemove);
	}

	//Two childs removal
	else if(numberOfChilds(nodeToRemove) == 2){
		int nodeToReplaceData = findBestNode(nodeToRemove);
		BSTree nodeToReplace = findNodeWithData(*tree, nodeToReplaceData);

		if(numberOfChilds(nodeToReplace) == 0){
			nodeToRemove->data = nodeToReplaceData;
			free(nodeToReplace);
			nodeToReplace = NULL;
		}
		else{
			assert(numberOfChilds(nodeToReplace) == 1);
			removeElement(tree, nodeToReplaceData);
			nodeToRemove->data = nodeToReplaceData;
		}
		//Find Highest to the left or lowest to the right.
	}
}

void printPreorder(const BSTree tree)
{
    printf("%d ", tree->data);
    if(tree->left != NULL){
        printPreorder(tree->left);
    }
    if(tree->right != NULL){
        printPreorder(tree->right);
    }
}

void printInorder(const BSTree tree)
{
    if(tree->left != NULL){
        printInorder(tree->left);
    }
    printf("%d ", tree->data);
    if(tree->right != NULL){
        printInorder(tree->right);
    }

}

void printPostorder(const BSTree tree)
{
    if(tree->left != NULL){
        printPostorder(tree->left);
    }
    if(tree->right != NULL){
        printPostorder(tree->right);
    }
    printf("%d ", tree->data);
}
