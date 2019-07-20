#define _CRT_SECURE_NO_WARNINGS // For visual studio users

#include <stdio.h>
#include "list.h"
#include <assert.h>

/*Denna kan du anvanda for att testa specifika funktioner
 (du far givetvis skriva en egen menyfunktion om du vill det)*/
void menu(List head);

/*Kors programmet felfritt genom denna funktion sa fungerar det som specificerat (observera att utskriften maste testas manuellt.
  OBS! Innan alla funktioner är implementerade sa kommer exekveringen fastna i olika asserts*/
void testFunction(List head);


int main(void)
{
    List list = createEmptyList();

    /*Kommentera eller avkommentera beroende pa om det ar menyn eller testfunktionen som ska koras*/
     testFunction(list);
    //menu(list);


    return 0;
}

void menu(List list)
{
    int choice;
    Data data;
    char c; //Anvands endast for att rensa lasbufferten

    do
    {
        printf("\n\n--------------MENU--------------\n"
               "1 - Print list\n"
               "2 - Add data first in list\n"
               "3 - Add data last in list\n"
               "4 - Remove first node in list\n"
               "5 - Remove last node in list\n"
               "6 - Remove data in list\n"
               "7 - Number of nodes in list\n"
               "8 - Is the list empty?\n"
               "9 - Get first element in list\n"
               "10 - Get last element in list\n"
               "11 - Search in list\n"
               "12 - Clear list (removes all nodes)\n"
               "13 - End program\n"
               "-----------------------------------\n"
               "Choice: ");

        scanf("%d", &choice);
        while((c = getchar()) != '\n' && c != EOF); //Rensar lasbufferten

        switch(choice)
        {
            case 1: printf("List: ");
                    printList(list, stdout); break;

            case 2: printf("Data to add first: ");
                    scanf("%d%*c", &data);
                    addFirst(&list, data);
                    printf("List: ");
                    printList(list, stdout);
                    break;

            case 3: printf("Data to add last: ");
                    scanf("%d%*c", &data);
                    addLast(&list, data);
                    printf("List: ");
                    printList(list, stdout);
                    break;

            case 4: removeFirst(&list);
                    printf("First node removed\n");
                    printf("List: ");
                    printList(list, stdout);
                    break;

            case 5: removeLast(&list);
                    printf("Last node removed\n");
                    printf("List: ");
                    printList(list, stdout);
                    break;

            case 6: printf("Data to remove: ");
                    scanf("%d%*c", &data);
                    if(removeElement(&list, data) == 1)
                        printf("First occurance of node with data %d is removed\n", data);
                    else
                        printf("No node with data %d\n", data);
                    printf("List: ");
                    printList(list, stdout);
                    break;

            case 7: printf("Number of nodes in list: %d\n", numberOfNodesInList(list)); break;

            case 8: if(isEmptyList(list) == 1)
                        printf("The list is empty\n");
                    else
                        printf("The list is not empty\n");
                    break;

            case 9: printf("First element: %d\n", getFirstElement(list)); break;

            case 10: printf("Last element: %d\n", getLastElement(list)); break;

            case 11: printf("Data to search for: ");
                scanf("%d", &data);
                if(searchList(list, data) == 1)
                {
                    printf("%d found in list ", data);
                    printList(list, stdout);
                }
                else
                {
                    printf("%d not found in list ", data);
                    printList(list, stdout);
                }
                break;

            case 12: clearList(&list); break;

            case 13: printf("\nEnding program");

            default: printf("\nWrong input");
        }
    }while(choice != 13);
}

/*Du behöver själv testa funktionen printList, tänk på att testa denna både på en befintlig lista och på en tom lista
  Testa även att det går att göra clearList på en tom lista utan att programmet krashar*/
void testFunction(List list)
{
    printf("Starting test\n");

    assert(isEmptyList(list)); //Listan ska vara tom fran borjan

    //Testar addFirst
    addFirst(&list, 6);
    addFirst(&list, 5);
    addFirst(&list, 4);
    addFirst(&list, 3);
    addFirst(&list, 2);

    assert(numberOfNodesInList(list) == 5);
    assert(getFirstElement(list) == 2);
    assert(getLastElement(list) == 6);
    //listan består nu av 2-3-4-5-6

    //Testar addLast på existerande lista
    addLast(&list, 7);
    addLast(&list, 8);
    assert(numberOfNodesInList(list) == 7);
    assert(getFirstElement(list) == 2);
    assert(getLastElement(list) == 8);
    //listan består nu av 2-3-4-5-6-7-8
    //Testar removeFirst på existerande lista
    removeFirst(&list);
    assert(numberOfNodesInList(list) == 6);
    assert(getFirstElement(list) == 3);
    assert(getLastElement(list) == 8);
    //listan består nu av 3-4-5-6-7-8
    //Testar removeLast på existerande lista
    removeLast(&list);
    assert(numberOfNodesInList(list) == 5);
    assert(getFirstElement(list) == 3);
    assert(getLastElement(list) == 7);
    //listan består nu av 3-4-5-6-7
    //Testar att ta bort en nod (som finns) i mitten av befintlig listan
    removeElement(&list, 5);
    assert(numberOfNodesInList(list) == 4);
    assert(getFirstElement(list) == 3);
    assert(getLastElement(list) == 7);
    //listan består nu av 3-4-6-7
    //Testar att ta bort forsta noden med removeElement i befintlig lista
    removeElement(&list, 3);
    assert(numberOfNodesInList(list) == 3);
    assert(getFirstElement(list) == 4);
    assert(getLastElement(list) == 7);
    //listan består nu av 4-6-7
    //Testar att ta bort sista noden med removeElement i befintlig lista
    removeElement(&list, 7);
    assert(numberOfNodesInList(list) == 2);
    assert(getFirstElement(list) == 4);
    assert(getLastElement(list) == 6);
    //listan består nu av 4-6
    //testar att ta bort en nod som inte finns med removeElement i en befintlig lista
    assert(removeElement(&list, 5) == 0);

    assert(!isEmptyList(list)); //Listan ska inte vara tom (4 och 6 ar kvar i listan)

    //Testar att ta bort ett ensamt element med removeElement
    removeElement(&list, 6);
    assert(numberOfNodesInList(list) == 1);
    assert(getFirstElement(list) == 4);
    removeElement(&list, 4);
    assert(isEmptyList(list)); //Listan ska nu vara tom
    //Testar att lagga till data till en tomd lista
    addLast(&list, 5); //testar att lägga till sist i tom lista
    assert(getFirstElement(list) == getLastElement(list));
    removeFirst(&list); //ta bort sista elementet med removeFirst
    assert(isEmptyList(list)); //tom lista igen
    addFirst(&list, 5);
    assert(getFirstElement(list) == getLastElement(list));
    removeLast(&list); //ta bort sista elementet med removeLast
    assert(isEmptyList(list)); //tom lista igen
    addFirst(&list, 5);
    addFirst(&list, 4);
    addFirst(&list, 3);
    addFirst(&list, 2);
    assert(numberOfNodesInList(list) == 4);
    assert(getFirstElement(list) == 2);
    assert(getLastElement(list) == 5);
    //listan består nu av 2-3-4-5
    //Testar search (mitt i, forst, sist, data som inte finns)
    assert(searchList(list, 4) == 1);
    assert(searchList(list, 2) == 1);
    assert(searchList(list, 5) == 1);
    assert(searchList(list, 7) == 0);
    //Testar att tomma hela listan
    clearList(&list);
    assert(isEmptyList(list));

    assert(searchList(list, 5) == 0);//Testar att soka i en tom lista
    assert(removeElement(&list, 3) == 0); //testar att ta bort från tom lista
    assert(numberOfNodesInList(list) == 0); //testar att räkna noderna i en tom lista

    printf("Congratulations!\nYour program passed the test\n");
}
