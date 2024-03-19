#include <stdio.h>
#include <malloc.h>

typedef struct Santier Santier;
typedef struct Nod Nod;
struct Santier {
	char* numeProiect;
	int nrMuncitori;
	float suprafata;
};

struct Nod {
	Santier santier;
	Nod* next;
};

Santier initSantier(const char* numeProiect, int nrMuncitori, float suprafata) {
	Santier santier;
	santier.numeProiect = (char*)malloc(strlen(numeProiect) + 1);
	strcpy(santier.numeProiect, numeProiect);
	santier.nrMuncitori = nrMuncitori;
	santier.suprafata = suprafata;
	return santier;
}

Nod* inserareInceput(Santier santier, Nod* lista) {
	Nod* nod= (Nod *)malloc(sizeof(Nod));
	nod->santier = santier;
	nod->next = lista;
	return nod;
}

void afisareSantier(Santier santier) {
	printf("Santierul %s are %d muncitori si o suprafata %5.2f m2 \n", santier.numeProiect, santier.nrMuncitori, santier.suprafata);
}
void afiseazaLista(Nod* lista) {
	while (lista != NULL) {
		//procesare
		afisareSantier(lista->santier);
		lista = lista->next;
	}
}

int nrMuncitoriTotal(Nod* lista) {
	int nrMuncitoriTotal = 0;
	while (lista != NULL) {
		nrMuncitoriTotal += lista->santier.nrMuncitori;
		lista = lista->next;
	}
	return nrMuncitoriTotal;
}

void stergereLista(Nod** lista) {
	while ((*lista) != NULL) {
		free((*lista)->santier.numeProiect);
		Nod* aux = malloc(sizeof(Nod));
		aux = (*lista)->next;
		free(*lista);
		(*lista) = aux;
	}
	(*lista) = NULL;
}

float densitateSantier(Santier santier) {
	if (santier.suprafata > 0) {
		return santier.nrMuncitori / santier.suprafata;
	}
	else return 0;
}

char* numeSantierDens(Nod* lista) {
	float max = 0;
	char* aux = NULL;
	while (lista != NULL) {
		if (densitateSantier(lista->santier) > max) {
			aux = lista->santier.numeProiect;
			max = densitateSantier(lista->santier);
		}
		lista = lista->next;
	}
	if (aux != NULL) {
		char* numeProDens = (char*)malloc(strlen(aux) + 1);
		strcpy(numeProDens, aux);
		return numeProDens;
	}
	else return 0;
}
int main() {
	Nod* lista = NULL;
	Santier s1 = initSantier("Santier 1", 10, 300);
	Santier s2 = initSantier("Santier 2", 20, 500);
	Santier s3 = initSantier("Santier 3", 50, 800);
	lista = inserareInceput(initSantier("Santier 4", 10, 44), lista);
	lista = inserareInceput(s1, lista);
	lista = inserareInceput(s2, lista);
	lista = inserareInceput(s3, lista);

	afiseazaLista(lista);

	printf("Numarul total de muncitori %d", nrMuncitoriTotal(lista));

	printf("\n%s\n", numeSantierDens(lista));

	stergereLista(&lista);
	afiseazaLista(lista);

}