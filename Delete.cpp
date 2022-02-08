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

void DezalocareNodDupaOAnumitaPozitie(Node* PrimulNod, char* username)
{

    if (!listaActiva(PrimulNod))
    {
        printf("\n NU SE POATE EFECTUA ACEASTA OPERATIUNE PE LISTE GOALE !\n");
        return;
    }


    // Cautam in lista  dupa acel username 
    unsigned pozitie = CautareLista(PrimulNod,username); 


    if (!pozitie)  // 
        printf("\n Utilizatorul NU a fost gasit ! \n");


    else if (pozitie == 1)  // Userul cautat este cap

        DezalocarePrimNod(&PrimulNod);
     
    else
    {
        Node* Iterator = PrimulNod,*temp; 

        //
        for (unsigned i = 1; i < (pozitie-1); i++, Iterator = Iterator->nextNode);

        // Navigam pana la ( aceea pozitie - 1 ) NODUL PRECEDENT CELUI PE CARE-L CAUTAM 

        printf("%s", Iterator->utilizator.username);

        temp = Iterator->nextNode; // Retinem nodul cautat pentru stergere 

        Iterator->nextNode = Iterator->nextNode->nextNode; // Inlaturam nodul din lista 


        StergereNod(temp);
    }
    
}
