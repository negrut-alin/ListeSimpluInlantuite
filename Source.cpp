// Include C Headers (Declaratia functiilor)

#include "LinkedListDeclaration.h"
#include "Utility.h"
#include "DataNode.h"
#include "Insert.h"
#include "Delete.h"
#include "Sortare.h"



void AfisareMeniuPrincipal() {  // Functia care preia interfata

	// Static pentru a isi pastra valoarea la fiecare ciclare din entrypoint 

	static Node* PrimulNode = NULL; // Primul Nod din Lista (lista cu multime de elemente VIDA) 

	unsigned choice; // Numar  Natural Pozitiv 
REVENIRE:
	printf("\n\n -----------> Meniu Operatiuni Lista Inlantuita <---------------------- \n\n");
	printf(" 1. Inserare Nod ;\n");
	printf(" 2. Stergere Nod ;\n");
	printf(" 3. Afisare Lista ; \n");
	printf(" 4. Aflare numar de elemente in Lista ;\n");
	printf(" 5. Sortare Lista ; \n");
	printf(" 6. Inversare Lista ; \n");
	printf(" 7. Cautare Element Lista ; \n");
	printf(" 8. Aflarea Numarului de Posturi Medie : \n");
	printf(" 9. Eliberare Lista ; \n");
	printf("10. Iesire din Program ; \n\n\n");

	printf("Insereaza optiunea ta : ");
	scanf_s(" %u", &choice);  // Interogare Choice de la tastatura 

	switch (choice) {
	case 1:
		// Alt meniu 
		unsigned choice1;
	REVENIRE1: // De aici ne putem intoarce in cazul in care s-a gresit inputul
		system("cls"); // Stergere buffer din consola 
		printf("\n\n -----------> Inserare Lista Inlantuita <---------------------- \n\n");
		printf(" 1. Inserare Nod de la inceput ;\n");
		printf(" 2. Inserare Nod de la sfarsit ;\n");
		printf(" 3. Inserare Nod intr-o anumita pozitie ; \n\n\n");

		printf("Insereaza Optiunea Ta : ");
		scanf_s(" %u", &choice1);

		system("cls");

		switch (choice1)
		{
		case 1: // Adaugare la inceput 
			AdaugaElementLaInceput(&PrimulNode);
			break;
		case 2: // Adaugare la sfarsit
			AdaugaElementLaSfarsit(&PrimulNode);
			break;
		case 3:
			char tempLine[MAX_BUFFER];
			printf("\n\n Dati-mi numele de utilizator : ");
			scanf_s(" %s", &tempLine, (unsigned)sizeof(tempLine));
			InserareNodLaoAnumitaPozitie(&PrimulNode, tempLine);
			break;
		default:
			goto REVENIRE1; // Daca s-a gresit alegerea , ne intoarcem spre REVENIRE1 .
			break;
		}
		break;
	case 2:
		// MENIU STERGERE 
		unsigned choice2;
	REVENIRE2: // De aici ne putem intoarce in cazul in care s-a gresit inputul
		system("cls"); // Stergere buffer din consola 
		printf("\n\n -----------> Stergere Lista Inlantuita <---------------------- \n\n");
		printf(" 1. Stergere Nod de la inceput ;\n");
		printf(" 2. Stergere Nod de la sfarsit ;\n");
		printf(" 3. Stergere Nod dintr-o anumita pozitie ; \n\n\n");

		printf("Insereaza Optiunea Ta : ");
		scanf_s(" %u", &choice2);

		system("cls");

		switch (choice2)
		{
		case 1: // Stergere Nod De la Inceput 
			DezalocarePrimNod(&PrimulNode);
			printf("\n S-a sters primul nod ! \n");
			break;
		case 2: // Adaugare la sfarsit
			//AdaugaElementLaSfarsit(&PrimulNode);
			DezalocareNodTerminal(PrimulNode);
			printf("\n S-a sters ultimul nod ! \n");
			break;
		case 3:
			char tempLine[MAX_BUFFER];
			printf("\n\n Dati-mi numele de utilizator : ");
			scanf_s(" %s", &tempLine, (unsigned)sizeof(tempLine));
			DezalocareNodDupaOAnumitaPozitie(&PrimulNode, tempLine);
			break;
		default:
			goto REVENIRE2; // Daca s-a gresit alegerea , ne intoarcem spre REVENIRE1 .
			break;
		}

		break;
	case 3:
		TraversareLista(PrimulNode);
		break;
	case 4:
		printf("In Lista Actuala se afla %u elemente ! ", numarElementeLista(PrimulNode));
		break;
	case 5:
		// MENIU STERGERE 
		unsigned choice5;
	REVENIRE5: // De aici ne putem intoarce in cazul in care s-a gresit inputul
		system("cls"); // Stergere buffer din consola 
		printf("\n\n -----------> Sortare Lista Inlantuita <---------------------- \n\n");
		printf(" 1. Sortare Lista Dupa Nume de Utilizator (Ascendent) ;\n");
		printf(" 2. Sortare Lista Dupa Nume de Utilizator (Descendent) ;\n");
		printf(" 3. Sortare Lista Dupa Numarul de Posturi (Ascendent) ;\n");
		printf(" 4. Sortare Lista Dupa Numarul de Posturi (Descendent) ; \n\n\n");

		printf("Insereaza Optiunea Ta : ");
		scanf_s(" %u", &choice5);

		system("cls");


		switch(choice5)
		{
		case 1:
			sortareDupaNumeUtilizator(&PrimulNode); // Aplicare Sortare Ascendenta (Implicita)
			printf("Sortarea Ascendenta s-a efectuat cu succes ! \n");
			break;
		case 2:
			sortareDupaNumeUtilizator(&PrimulNode); // Aplicare Sortare Ascendenta (Implicita)
			InversareLista(&PrimulNode); // Inversam lista pentru a obtine o Sortare Descendenta 
			printf("Sortarea Descendenta s-a efectuat cu succes ! \n");
			break;
		case 3:
			sortareDupaNumarDePosturi(&PrimulNode); // Aplicare Sortare Ascendenta (Implicita)
			printf("Sortarea Ascendenta s-a efectuat cu succes ! \n");
			break;
		case 4:
			sortareDupaNumarDePosturi(&PrimulNode); // Aplicare Sortare Ascendenta (Implicita)
			InversareLista(&PrimulNode); // Inversam lista pentru a obtine o Sortare Descendenta 
			printf("Sortarea Descendenta s-a efectuat cu succes ! \n");
			break;
		default:
			goto REVENIRE5;
			break;
 		}

		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		if (listaActiva(PrimulNode))
		{
			DezalocareLista(PrimulNode);
			printf("\n\n AI ELIBERAT MEMORIA OCUPATA DE LISTA !\n\n");
		}
		break;
	case 10:
		if (listaActiva(PrimulNode))
		{
			DezalocareLista(PrimulNode);
			printf("\n\n NU UITA SA ELIBEREZI MEMORIA STOCATA DE LISTA !\n\n");
		}
		printf("\n PROGRAMUL SE INCHIDE .... \n");
		_getch();
		exit(0); // Inchidere Fortata A Programului 
		break;
	default:
		goto REVENIRE;
		break;

	}


}


void main() {

	while (true) {
		AfisareMeniuPrincipal();
	}

}