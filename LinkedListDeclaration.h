#ifndef LINKEDLISTDECLARATION_DOT_H
#define LINKEDLISTDECLARATION_DOT_H

#include <stdio.h> // Pentru intrari si iesiri
#include <conio.h> // Pentru getch()
#include <string.h> // Pentru manipularea sirurilor de caractere 
#include <stdlib.h> // Pentru alocare dinamica 

#define MAX_BUFFER 32 // Lungime Maxima pentru Siruri de Caractere 

// Declaratie Articol 

// Subdiviziune Articol 
struct Followers {
	int nrFollowers;
	char** followers; // Sir de siruri de caractere
};

struct UtilizatorLeagueCS {
	unsigned nrCrt; // Unsigned 
	char* username;// Sir de Caractere
	char* email; // Sir de Caractere
	char* password; // Sir de Caractere
	unsigned nrPosturi; // Variabila Unsigned
	Followers followers; // Structura Imbracata
};

// Declaratie Lista Simpla Inlantuita 

struct Node {
	UtilizatorLeagueCS utilizator; // Informatie 
	Node* nextNode; // Pointer catre urmatorul NOD
};


#endif
