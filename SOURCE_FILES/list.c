#include "list.h"
#include <stdlib.h>
#include <assert.h>

/* Det ar helt tillatet och rekommenderat att lagga till statiska hjalpfunktioner, men du far inte andra de funktioner som redan finns */

/* Hjalpfunktion till add-funktionerna
   Allokerar minne for en ny nod och returnerar den, nodens next-pekare ska vara NULL
   */
static Node* createListNode(const Data data)
{
    Node* node = (Node*) malloc(sizeof(Node));
    if(node == NULL){
        return NULL;
    }
    // Du kan valja om du ska se allokerad nod som ett post-condition eller returnera NULL vid misslyckande
    else {
        node->data = data;
        node->next = NULL;
        node->previous = NULL;
        return node;
    }
}

List createEmptyList(void)
{
    return NULL; // Ersatt med ratt returvarde
}


int isEmptyList(const List list)
{
    if(list == NULL) return 1;
    return 0;
}


void addFirst(List *list, const Data data)
{
    // Anropa createListNode for att skapa den nya noden
    // Om createListNode kan returnera NULL maste detta fall tas hand om
    Node* newNode = createListNode(data);
    if(newNode == NULL){
        printf("Allocation error\n");
        return;
    }
    newNode->next = *list;
    if(newNode->next != NULL)
        newNode->next->previous = newNode;
    *list = newNode;
   /* Postcondition: Det nya datat ligger forst i listan (testa med assert, anvand funktionen getFirstElement()) */
   assert(getFirstElement(*list) == data);
}

void addLast(List *list, const Data data)
{
    Node* newNode = createListNode(data);
    if(isEmptyList(*list)){
        addFirst(list, data);
        return;
    }
    Node* lastNode;
    for(lastNode = *list; lastNode->next != NULL; lastNode = lastNode->next);
    lastNode->next = newNode;
    newNode->previous = lastNode;
    assert(getLastElement(*list) == data);
  /* Postcondition: Det nya datat ligger forst i listan (testa med assert, anvand funktionen getLastElement()) */
}

void removeFirst(List *list)
{
    assert(!isEmptyList(*list));
	/* Precondition: listan ar inte tom (testa med assert) */
    Node* nodeToRemove = *list;
    *list = nodeToRemove->next;
    if(nodeToRemove->next != NULL)
        nodeToRemove->next->previous = NULL;
    free(nodeToRemove);
    nodeToRemove = NULL;

	//Glom inte att frigora minnet for den nod som lankas ur listan.
}

void removeLast(List *list)
{
	/* Precondition: listan ar inte tom (testa med assert) */
    assert(!isEmptyList(*list));
    if(numberOfNodesInList(*list) == 1){
        removeFirst(list);
        return;
    }
    Node* lastNode;
    for(lastNode = *list; lastNode->next != NULL; lastNode = lastNode->next);
    if(lastNode->previous != NULL)
        lastNode->previous->next = NULL;
    free(lastNode);
    lastNode = NULL;

    //Glom inte att frigora minnet for den nod som lankas ur listan.
}

int removeElement(List *list, const Data data)
{
	/* Precondition: listan ar inte tom (testa med assert) */
    if(isEmptyList(*list)) return 0;
    Node* nodeToRemove;
    if(data == getFirstElement(*list)){
        removeFirst(list);
        return 1;
    }
    else if(data == getLastElement(*list)){
        removeLast(list);
        return 1;
    }
    for(nodeToRemove = *list; nodeToRemove->next != NULL && nodeToRemove->data != data; nodeToRemove = nodeToRemove->next);
    if(nodeToRemove->data != data)
        return 0;

    if(nodeToRemove->next != NULL)
        nodeToRemove->next->previous = nodeToRemove->previous;

    if(nodeToRemove->previous != NULL)
        nodeToRemove->previous->next = nodeToRemove->next;

    free(nodeToRemove);
    nodeToRemove = NULL;
    return 1; //Ersatt med ratt returvarde
}

int searchList(const List list, const Data data)
{
    if(isEmptyList(list)) return 0;
    Node* searchNode;
    for(searchNode = list; searchNode->next != NULL && searchNode->data != data; searchNode = searchNode->next);
    if(searchNode->data == data)
        return 1; //Ersatt med ratt returvarde
    return 0;
}

int numberOfNodesInList(const List list)
{
    if(isEmptyList(list)) return 0;
    Node* node = list;
    int counter = 0;
    while(node != NULL){
        counter++;
        node = node->next;
    }
    return counter; //Ersatt med ratt returvarde
}

void clearList(List *list)
{
    //Alla noder maste avallokeras en och en, det racker inte att endast frigora list!
    while(*list != NULL) removeLast(list);
    assert(isEmptyList(*list));
	/* Postcondition: Listan ar tom (testa med assert) */
}


Data getFirstElement(const List list)
{
    /* Precondition: listan ar inte tom (testa med assert) */
    assert(!isEmptyList(list));
    return list->data; //Ersatt med ratt returvarde
}

void printList(const List list, FILE *textfile)
{
    Node* firstNode = list;
    while(firstNode != NULL){
        fprintf(textfile, "\n%d", firstNode->data);
        firstNode = firstNode->next;
    }
    printf("\n");
}

Data getLastElement(const List list)
{
	/*  Precondition: listan ar inte tom (testa med assert) */
    assert(!isEmptyList(list));
    Node* lastNode;
    for(lastNode = list; lastNode->next != NULL; lastNode = lastNode->next);
    return lastNode->data; //Ersatt med ratt returvarde
}
