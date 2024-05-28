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
		p->next = nou;
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

void afisareAutobuz(Autobuz A) {
	printf("%d are capatul la %s \n", A.linie, A.capatLinie);
}

#pragma region MyRegion

typedef struct nodCoada nodCoada;

struct nodCoada {
	int id;
	nodCoada* next;
};

void inserareCoada(nodCoada** cap, int id) {
	nodCoada* nou = (nodCoada*)malloc(sizeof(nodCoada));
	nou->id = id;
	nou->next = NULL;
	if (*cap) {
		nodCoada* p = *cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
	}
	else {
		*cap = nou;
	}
}

void inserareStiva(nodCoada** cap, int id) {
	nodCoada* nou = malloc(sizeof(nodCoada));
	nou->id = id;
	nou->next = *cap;
	*cap = nou;
}


int extragereDinCoada(nodCoada** cap) {
	if (*cap) {
		int rezultat = (*cap)->id;
		nodCoada* temp = (*cap)->next;
		free(*cap);
		*cap = temp;
		return rezultat;
	}
	else {
		return -1;
	}
}

int extrageStiva(nodCoada** cap) {
	return extragereDinCoada(cap);
}

int getNrNoduri(NodPrincipal* graf) {
	int s = 0;
	while (graf) {
		s++;
		graf = graf->next;
	}
	return s;
}

void afisareCuParcurgereInLatime(NodPrincipal* graf, int nodPlecare) {
	//initializari
	nodCoada* coada = NULL;
	int nrNoduri = getNrNoduri(graf);
	char* vizitate = malloc(sizeof(char)*nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		vizitate[i] = 0;
	}
	inserareCoada(&coada, nodPlecare);
	vizitate[nodPlecare] = 1;

	while (coada) {
		//extragem noudl din coada
		int idNodCurent = extragereDinCoada(&coada);
		NodPrincipal* nodCurent= cautaLinie(graf, idNodCurent);
		NodSecundar* temp = nodCurent->vecini;
		afisareAutobuz(nodCurent->info);
		//inserare in coada si marcare ca vizitat fiecare vecin
		while (temp) {
			if (vizitate[
				temp->nod->info.linie] == 0) {
				vizitate[temp->nod->info.linie] = 1;
				inserareCoada(&coada, temp->nod->info.linie);
			}
			temp = temp->next;
		}
	}
	if (vizitate) {
		free(vizitate);
	}
}

void afisareCuParcurgereInAdancime(NodPrincipal* graf, int nodPlecare) {
	//initializari
	nodCoada* stiva = NULL;
	int nrNoduri = getNrNoduri(graf);
	char* vizitate = malloc(sizeof(char) * nrNoduri);
	for (int i = 0; i < nrNoduri; i++) {
		vizitate[i] = 0;
	}
	inserareStiva(&stiva, nodPlecare);
	vizitate[nodPlecare] = 1;

	while (stiva) {
		//extragem noudl din coada
		int idNodCurent = extragereDinCoada(&stiva);
		NodPrincipal* nodCurent = cautaLinie(graf, idNodCurent);
		NodSecundar* temp = nodCurent->vecini;
		afisareAutobuz(nodCurent->info);
		//inserare in coada si marcare ca vizitat fiecare vecin
		while (temp) {
			if (vizitate[temp->nod->info.linie] == 0) {
				vizitate[temp->nod->info.linie] = 1;
				inserareStiva(&stiva, temp->nod->info.linie);
			}
			temp = temp->next;
		} 		
	}
	if (vizitate) {
		free(vizitate);
	}
}

#pragma endregion

void stergereListVecinin(NodSecundar** cap) {
	NodSecundar* p = (*cap);
		while (p) {
			NodSecundar* aux = p;
			p = p->next;
			free(aux);
		}
		*cap = NULL;
}

void stergereGraf(NodPrincipal** graf) {
	while (*graf) {
		free((*graf)->info.capatLinie);
		stergereListVecinin(&(*graf)->vecini);
		NodPrincipal* temp = (*graf);
		*graf = temp->next;
		free(temp);
	}
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
	
	afisareCuParcurgereInLatime(graf, 0);
	printf("\n\n");
	afisareCuParcurgereInAdancime(graf, 0);
	stergereGraf(&graf);
}
