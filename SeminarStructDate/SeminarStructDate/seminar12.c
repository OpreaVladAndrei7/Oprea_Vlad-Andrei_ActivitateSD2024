#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct Autobuz Autobuz;
typedef struct NodPrincipal NodPrincipal;
typedef struct NodSecundar NodSecundar;

struct Autobuz {
	int linie;
	char* capatLinie;
};

struct NodPrincipal {
	Autobuz info;
	NodPrincipal* next;
	NodSecundar* vecini;
};

struct  NodSecundar{
	NodPrincipal* nod;
	NodSecundar* next;
};

void inserarePrincipala(NodPrincipal** graf, Autobuz a) {
	NodPrincipal* nod = malloc(sizeof(NodPrincipal));
	nod->info = a;
	nod->next = NULL;
	nod->vecini = NULL;
	if ((*graf) == NULL) {
		(*graf) = nod;
	}
	else
	{
		NodPrincipal* temp = (*graf);
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = nod;  
	}
}

Autobuz initAutibuz(int linie, char* capat) {
	Autobuz a;
	a.linie = linie;
	a.capatLinie = malloc(strlen(capat) + 1);
	strcpy_s(a.capatLinie, strlen(capat)+1,capat);
	return a;
}

NodPrincipal* cautaLinie(NodPrincipal* graf, int linie) {
	while(graf && graf->info.linie != linie){
		graf = graf->next;
	}
	return graf;
}

NodSecundar* inserareSecundara(NodSecundar* cap, NodPrincipal* info) {
	NodSecundar* nou = malloc(sizeof(NodSecundar));
	nou->next = NULL;
	nou->nod = info;
	if (cap != NULL) {
		NodSecundar* p = cap;
		while (p->next) {
			p = p->next;
		}
		return cap;
	}
	else{
		return nou;
	}
	
}

void inserareMuchie(int linieStart, int linieStop, NodPrincipal* graf) {
	NodPrincipal* nodStart= cautaLinie(graf,linieStart);
	NodPrincipal* nodStop=cautaLinie(graf,linieStop);
	nodStart->vecini = inserareSecundara(nodStart->vecini, nodStop);
	nodStop->vecini = inserareSecundara(nodStop->vecini, nodStart);
}

void main() {
	NodPrincipal* graf = NULL;

	inserarePrincipala(&graf, initAutibuz(0, "Romana"));
	inserarePrincipala(&graf, initAutibuz(1, "Universitate"));
	inserarePrincipala(&graf, initAutibuz(2, "Unirii"));
	inserarePrincipala(&graf, initAutibuz(3, "Victoriei"));
	inserarePrincipala(&graf, initAutibuz(4, "Militari"));

	inserareMuchie(0, 1, graf);
	inserareMuchie( 0, 4, graf);
	inserareMuchie( 1, 2, graf);
	inserareMuchie( 2, 4, graf);
	inserareMuchie( 3, 4, graf);
	
}
