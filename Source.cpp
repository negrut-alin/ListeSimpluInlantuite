// Include C Headers (Declaratia functiilor)

#include "LinkedListDeclaration.h"
#include "Utility.h"
#include "DataNode.h"
#include "Insert.h"
#include "Delete.h"



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
		break;
	case 5:
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