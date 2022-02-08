#include "OtherOperations.h"

// Algoritm Pentru Cautare in Lista 

unsigned CautareLista(Node* PrimulNode, char* numeUtilizator) {

	unsigned contor = 1, gasit = 0; // Retinem pozitia unde am gasit elementul 

	if (!listaActiva(PrimulNode))
		gasit = 0; // NU AVEM ELEMENTE SA CAUTAM

	else {
		while (PrimulNode != NULL) // Parcurgem Lista Pana la sfarsit
		{
			if (!strcmp(numeUtilizator, PrimulNode->utilizator.username)) // Am gasit numele de utilizator
			{
				gasit = 1;

				break; // Oprim ciclarea 
			}
			contor++;
			PrimulNode = PrimulNode->nextNode; // Navigam catre urmatorul nod
		}
	}

	return gasit != 0 ? contor : 0; // Daca gasim elementul tinem cont de pozitie daca nu , returnam 0 
}

void TraversareLista(Node* PrimulNode) {
	// E Necesar doar valoarea primului nod 

	Node* Iterator = PrimulNode;

	printf("\n\n -------------> Utilizatori LeagueCS <-------------------\n\n");

	while (Iterator != NULL)// Pana la ultimul element
	{
		printf("NrCrt = %u | Nume Utilizator : %s | Adresa de Mail : %s | Parola : %s | Numar Posturi : %u \n",
			Iterator->utilizator.nrCrt, Iterator->utilizator.username, Iterator->utilizator.email,
			Iterator->utilizator.password, Iterator->utilizator.nrPosturi);

		// Afisarea Urmaritorilor 

		for (unsigned i = 0; i < Iterator->utilizator.followers.nrFollowers; i++)
			printf("Urmaritor[%u] : %s ; ", i + 1, Iterator->utilizator.followers.followers[i]);


		printf("\n\n");

		Iterator = Iterator->nextNode; // Navigam catre urmatorul nod 
	}
}

unsigned numarElementeLista(Node* CapNod) { // Returneaza Numarul de elemente 
   
	unsigned contor = 0;  // Pornim de la 0 elemente 

	while (CapNod != NULL) {
		contor++;
		CapNod = CapNod->nextNode;
	}

	return contor;

}



