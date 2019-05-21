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
    List list = (List) malloc(sizeof(List));
    if(list == NULL){
        return NULL;
    }
    else{
        list->next = NULL;
        list->previous = NULL;
        return list; // Ersatt med ratt returvarde
    }
}


int isEmptyList(const List list)
{
    if(list->next == NULL){
        return 1;
    }
    else return 0; //ersatt med ratt returvarde
}


void addFirst(List *list, const Data data)
{
    // Anropa createListNode for att skapa den nya noden
    // Om createListNode kan returnera NULL maste detta fall tas hand om
    Node* head = *list;
    Node* newNode = createListNode(data);
    if(newNode == NULL){
        return;
    }
    newNode->previous = head;
    if(!isEmptyList(*list)){
        head->next->previous = newNode;
    }
    newNode->next = head->next;
    head->next = newNode;
   /* Postcondition: Det nya datat ligger forst i listan (testa med assert, anvand funktionen getFirstElement()) */
}

void addLast(List *list, const Data data)
{
    Node* last = *list;
    while(last->next != NULL){
        last = last->next;
    }
    Node* newNode = createListNode(data);
    if(newNode == NULL){
        return;
    }
    last->next = newNode;
    newNode->previous = last;
  /* Postcondition: Det nya datat ligger forst i listan (testa med assert, anvand funktionen getLastElement()) */
}

void removeFirst(List *list)
{
	/* Precondition: listan ar inte tom (testa med assert) */
    Node* head = *list;
    Node* nodeToRemove = head->next;
    head->next = nodeToRemove->next;
    if(nodeToRemove->next != NULL){
        nodeToRemove->next->previous = head;
    }
    free(nodeToRemove);
	//Glom inte att frigora minnet for den nod som lankas ur listan.
}

void removeLast(List *list)
{
	/* Precondition: listan ar inte tom (testa med assert) */
    Node* head = *list;
    Node* nodeToRemove = head;
    while(nodeToRemove->next != NULL){
        nodeToRemove = nodeToRemove->next;
    }
    nodeToRemove->previous->next = NULL;
    free(nodeToRemove);
    //Glom inte att frigora minnet for den nod som lankas ur listan.
}

int removeElement(List *list, const Data data)
{
	/* Precondition: listan ar inte tom (testa med assert) */
    if(isEmptyList(*list)) return 0;
    Node* head = *list;
    Node* nodeToRemove = head;
    while(nodeToRemove->data.key != data.key){
        if(nodeToRemove->next == NULL){
            return 0;
        }
        nodeToRemove = nodeToRemove->next;
    }
    if(nodeToRemove->next != NULL){
        nodeToRemove->previous->next = nodeToRemove->next;
    }
    else{
        nodeToRemove->previous->next = NULL;
    }
    if(nodeToRemove->next != NULL){
        nodeToRemove->next->previous = nodeToRemove->previous;
    }

    free(nodeToRemove);
    return 1; //Ersatt med ratt returvarde
}

int searchList(const List list, const Data data)
{
    Node* head = list;
    Node* searchNode = head;
    while(searchNode->data.key != data.key){
        if(searchNode->next == NULL) return 0;
        searchNode = searchNode->next;
    }
    return 1; //Ersatt med ratt returvarde
}

int numberOfNodesInList(const List list)
{
    Node* node = list;
    int counter = 0;
    while(node->next != NULL){
        node = node->next;
        counter++;
    }
    return counter; //Ersatt med ratt returvarde
}

void clearList(List *list)
{
    //Alla noder maste avallokeras en och en, det racker inte att endast frigora list!
    Node* head = *list;
    while(head->next != NULL) removeLast(list);
    assert(head->next == NULL);
	/* Postcondition: Listan ar tom (testa med assert) */
}

/*Skriv ut listan
  Vid anropet kan man ange stdout som argument 2 for att skriva ut p� skarmen.
  Anvanda fprintf for att skriva ut.
  Den har typen av utskriftfunktion blir mer generell da man kan valja att skriva ut till skarmen eller till fil.*/
void printList(const List list, FILE *textfile)
{
    Node * firstNode = list->next;
    while(firstNode != NULL){
        fprintf(textfile, "\n%d", firstNode->data);
        firstNode = firstNode->next;
    }
}


Data getFirstElement(const List list)
{
    /* Precondition: listan ar inte tom (testa med assert) */
    assert(!isEmptyList(list));
    return list->next->data; //Ersatt med ratt returvarde
}


Data getLastElement(const List list)
{
	/*  Precondition: listan ar inte tom (testa med assert) */
    assert(!isEmptyList(list));
    Node* head = list;
    Node* lastNode = head;
    while(lastNode->next != NULL){
        lastNode = lastNode->next;
    }
    return lastNode->data; //Ersatt med ratt returvarde
}
