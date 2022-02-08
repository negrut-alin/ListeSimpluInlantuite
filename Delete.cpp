#include "Delete.h"

void DezalocareLista(Node* PrimulNod) // Dezalocare Totala
{
    Node* temp = NULL;

    while (PrimulNod != NULL)  // Ciclare pana la finalizare 
    {
        temp = PrimulNod; // Preluam nodul curent 

        PrimulNod = PrimulNod->nextNode; // Vom naviga la urmatorul nod 

        StergereNod(temp); // Stergere Nod Curent 
    }

}

void DezalocarePrimNod(Node** PrimulNod) // Dezalocare Primului Nod 
{

    if (!listaActiva(*PrimulNod))
    {
        printf("\n NU SE POATE EFECTUA ACEASTA OPERATIUNE PE O LISTA GOALA ! \n");
        return;
    }

    Node* temp = *PrimulNod;

    *PrimulNod = (* PrimulNod)->nextNode; // Mutam capul la urmatorul element 

    StergereNod(temp); // Dezalocare Prim Nod 

}

void DezalocareNodTerminal(Node* PrimulNod) // Dezalocare Ultim Nod 
{


    if (!listaActiva(PrimulNod))
    {
        printf("\n NU SE POATE EFECTUA ACEASTA OPERATIUNE PE O LISTA GOALA ! \n");
        return;
    }


    Node* Iterator = PrimulNod;

    while (Iterator->nextNode->nextNode != NULL) // Parcurgem lista pana la penultimul element 
        Iterator = Iterator->nextNode;

    StergereNod(Iterator->nextNode);  // Eliberam ultimul element din lista 

    Iterator->nextNode = NULL; // Scoatem ultimul element din lista 

}

void DezalocareNodDupaOAnumitaPozitie(Node** PrimulNod, char* username)
{

    Node* nodCautat = *PrimulNod, *nodCautatAnterior = NULL;  // Preluam referinta capului actual 

    if (!listaActiva(*PrimulNod))
    {
        printf("\n NU SE POATE EFECTUA ACEASTA OPERATIUNE PE LISTE GOALE !\n");
        return;
    }

    unsigned pozitieElementCautat = CautareLista(*PrimulNod,username);  // Preluare Pozitie 

    if (pozitieElementCautat == 0) // Daca elementul cu numele cautat nu exista 
    {
        printf("\n NU EXISTA ELEMENT CU ACEST NUME !\n");
        return;
    }

    else if (pozitieElementCautat == 1) // Daca elementul cautat se afla pe prima pozitie 
        DezalocarePrimNod(PrimulNod);

    else if (numarElementeLista(*PrimulNod) == pozitieElementCautat) // Ultimul element este cel cautat
        DezalocareNodTerminal(*PrimulNod);

    else {  // Daca elementul SE AFLA IN LISTA DAR NU PE PRIMUL LOC 
         
        for (unsigned i = 1; i < pozitieElementCautat;i++)
        {
            nodCautatAnterior = nodCautat;
            nodCautat = nodCautat->nextNode;
        }

        nodCautatAnterior->nextNode = nodCautat->nextNode; // Inlaturare Nod din Lista 

        StergereNod(nodCautat); // Eliberare Nod Cautat 

    }

    printf("Nod-ul asociat cu numele \"%s\ a fost eliminat !", username);

    
}
