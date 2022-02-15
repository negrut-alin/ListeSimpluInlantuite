#include "Sortare.h"


void sortareDupaNumeUtilizator(Node** CapLista)  // Aplicam o modificare in lista 
{
    Node* Iterator = *CapLista, * nextNode; // Definim Iteratorul si Urmatorul Element dupa Iterator 
    UtilizatorLeagueCS informatieNod;

    while (Iterator != NULL) // Ciclare Pana la terminarea listei 
    {

        // Preluam urmatorul nod dupa cel curent 
        nextNode = Iterator->nextNode;

        while (nextNode != NULL)  // Navigam (i+1 , i+2 ... n) , unde i -> este indexul curent  
        {

            if (strcmp(Iterator->utilizator.username, nextNode->utilizator.username) > 0)
            {
                // Daca NU ESTE RESPECTATA ORDINEA ALFABETICA , APLICAM O INTERSCHIMBARE 

                IntershimbareNoduri(&Iterator, &nextNode); // Apelare Interschimbare 
            }

            nextNode = nextNode->nextNode;
        }

        Iterator = Iterator->nextNode; // Navigam spre urmatorul nod (i , i+1 , i+2 ..... n) , unde i -> indexul curent 
    }
}


// Acelasi algoritm doar ca se schimba criteriul de comparatie 

void sortareDupaNumarDePosturi(Node** CapLista)  // Aplicam o modificare in lista 
{
    Node* Iterator = *CapLista, * nextNode; // Definim Iteratorul si Urmatorul Element dupa Iterator 
    UtilizatorLeagueCS informatieNod;

    while (Iterator != NULL) // Ciclare Pana la terminarea listei 
    {

        // Preluam urmatorul nod dupa cel curent 
        nextNode = Iterator->nextNode;

        while (nextNode != NULL)  // Navigam (i+1 , i+2 ... n) , unde i -> este indexul curent  
        {

            if (Iterator->utilizator.nrPosturi > nextNode->utilizator.nrPosturi)
            {
                // Daca NU ESTE RESPECTATA ORDINEA ALFABETICA , APLICAM O INTERSCHIMBARE 

                IntershimbareNoduri(&Iterator, &nextNode); // Apelare Interschimbare 
            }

            nextNode = nextNode->nextNode;
        }

        Iterator = Iterator->nextNode; // Navigam spre urmatorul nod (i , i+1 , i+2 ..... n) , unde i -> indexul curent 
    }
}
