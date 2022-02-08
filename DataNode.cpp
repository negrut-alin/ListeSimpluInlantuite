#include "DataNode.h"

void AdaugareInformatie(Node** newNode) {

	static unsigned idAux = 1; // Pastreaza valoarea dupa fiecare apel al functiei 

	char tempLine[MAX_BUFFER];

	(*newNode)->utilizator.nrCrt = idAux++; // utilizator.nrCrt se egaleaza cu valoarea lui idAux SI se incrementeaza cu 1 punct DUPA

	printf("Dati-mi numele : ");
	scanf_s("%s", &tempLine, (unsigned)sizeof(tempLine)); // Primim numele 

	ConvertToCharPointer(&(*newNode)->utilizator.username, tempLine);

	printf("Dati-mi adresa de mail : ");
	scanf_s("%s", &tempLine, (unsigned)sizeof(tempLine)); // Primim adresa de mail 

	ConvertToCharPointer(&(*newNode)->utilizator.email, tempLine);

	printf("Dati-mi parola : ");
	scanf_s("%s", &tempLine, (unsigned)sizeof(tempLine)); // Primim parola

	ConvertToCharPointer(&(*newNode)->utilizator.password, tempLine);

	printf("Dati-mi numarul de posturi : ");
	scanf_s("%u", &(*newNode)->utilizator.nrPosturi);  // Preluare Numar de Posturi 

	printf("Dati-mi numarul de urmaritori : ");
	scanf_s("%u", &(*newNode)->utilizator.followers.nrFollowers); // Preluare Numar de Urmaritori 

	(*newNode)->utilizator.followers.followers = (char**)malloc
	(sizeof(char*) * (**newNode).utilizator.followers.nrFollowers);   // Alocare Spatiu pentru o succesiune de siruri de caractere

	for (unsigned i = 0; i < (**newNode).utilizator.followers.nrFollowers;i++) {
		printf("Dati-mi numele urmaritorului [%u] : ", i + 1);
		scanf_s("%s", &tempLine, (unsigned)sizeof(tempLine)); // Inserare fiecare urmaritor 
		ConvertToCharPointer(&(*newNode)->utilizator.followers.followers[i], tempLine);
	}

}

void StergereNod(Node* currentNode)
{
	// Eliberare Siruri de Caractere 

	// Vom elibera informatia alocata si nodul actual . 

	free(currentNode->utilizator.username);
	free(currentNode->utilizator.email);
	free(currentNode->utilizator.password);
	for (unsigned i = 0; i < currentNode->utilizator.followers.nrFollowers;i++)
		free(currentNode->utilizator.followers.followers[i]);

	free(currentNode->utilizator.followers.followers);
	free(currentNode);
}