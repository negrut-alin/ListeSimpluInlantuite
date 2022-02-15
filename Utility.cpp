#include "Utility.h"

int listaActiva(Node* PrimulNod)
{
	return PrimulNod != NULL ? 1 : 0;
}

void ConvertToCharPointer(char** Destination, char* Source) {

	size_t lengthDestination = strlen(Source) + 1; // Stabilirea Dimensiunii pentru alocare a sirului de caractere 

	*Destination = (char*)malloc(lengthDestination); // Alocare Sir de Caractere

	strcpy_s(*Destination, lengthDestination, Source); // Copiere de la Sursa la Destinatie 
}

void IntershimbareNoduri(Node** FirstNode, Node** SecondNode)
{
	UtilizatorLeagueCS informatieNod = (*FirstNode)->utilizator;  // Preluare Informatie din Primul Nod 

	// Interschimbare infomatie intre noduri 
	(*FirstNode)->utilizator = (*SecondNode)->utilizator;
	(*SecondNode)->utilizator = informatieNod;
}
