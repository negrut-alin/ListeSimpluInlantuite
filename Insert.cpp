#include "Insert.h"

void AdaugaElementLaInceput(Node** NodCap) {
	Node* newNode = (Node*)malloc(sizeof(Node)); // Alocare in Heap a unui nod 

	// Adaugare Informatie 

	AdaugareInformatie(&newNode);

	// Capul actual va fi urmatorul nod al noului cap 

	newNode->nextNode = *NodCap;

	// Noul nod va deveni capul listei 

	*NodCap = newNode;

}

void AdaugaElementLaSfarsit(Node** NodCap) {

	Node* newNode = (Node*)malloc(sizeof(Node));  // Alocare in HEAP a unui nod 

	// Adaugare Informatie 

	AdaugareInformatie(&newNode);

	newNode->nextNode = NULL; // Setam adresa urmaritorului nod (NULL)

	if (!listaActiva(*NodCap)) // Lista VIDA
		*NodCap = newNode; // newNode va fi capul listei 


	else
	{
		// LISTA CU ELEMENTE (NEVIDA)

		Node* Iterator = *NodCap;

		while (Iterator->nextNode != NULL) // Parcurgem Lista 
			Iterator = Iterator->nextNode;

		Iterator->nextNode = newNode; // Inserare La Final a noului nod 

	}

}


void InserareNodLaoAnumitaPozitie(Node** PrimulNode, char* NumeUtilizator) {

	// Se poate face pe orice criteriu , totusi , numele de utilizator mi se pare cel mai relevant criteriu

	// Alocare Nod 

	Node* newNode = (Node*)malloc(sizeof(Node));

	AdaugareInformatie(&newNode); // Adauga Informatia in Nod

	if (!listaActiva(*PrimulNode))
		*PrimulNode = newNode; // Daca lista nu e activa , vom face acel nod capul listei 

	else {

		unsigned pozitie = CautareLista(*PrimulNode, NumeUtilizator); // Preluare Pozitie 

		if (pozitie == 0)
			printf(" \n Elementul NU A FOST GASIT sau LISTA NU ESTE ACTIVA  ! \n");

		else
		{
			Node* Iterator = *PrimulNode;

			for (unsigned i = 1; i < pozitie; i++, Iterator = Iterator->nextNode) // Navigam pana la aceea pozitie 
				continue;

			newNode->nextNode = Iterator->nextNode; // urmatorul noului nod va fi urmatorul nod a lui iterator

			Iterator->nextNode = newNode; // Urmatorul nod va fi nodul creat
		}
	}

}