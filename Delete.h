#ifndef DELETE_DOT_H
#define DELETE_DOT_H

#include "DataNode.h" 
#include "OtherOperations.h" // Pentru cautare

void DezalocareLista(Node* PrimulNod); // Dezalocare Totala 

void DezalocarePrimNod(Node** PrimulNod); // Dezalocare Primului Nod 

void DezalocareNodTerminal(Node* PrimulNod); // Dezalocare Ultim Nod 

void DezalocareNodDupaOAnumitaPozitie(Node* PrimulNod, char* username); // Dezalocare dupa nume (un criteriu relevant)


#endif 
