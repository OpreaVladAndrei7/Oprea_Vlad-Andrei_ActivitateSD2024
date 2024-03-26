#include <stdio.h>
#include <malloc.h>

typedef struct Santier Santier;
typedef struct NodLdi NodLdi;
typedef struct ListaDubla ListaDubla;
struct Santier {
	char* numeProiect;
	int nrMuncitori;
	float suprafata;
};

struct NodLdi {
	NodLdi* prev;
	NodLdi* next;
	Santier info;
};

struct ListaDubla {
	NodLdi* prim;
	NodLdi* ultim;
};

void inserareInceput( ListaDubla *lista, Santier s){
	NodLdi* aux = malloc(sizeof(NodLdi));
	aux->info = s;
	aux->prev = NULL;
	aux->next = lista->prim;
	if (lista->prim != NULL) {
		lista->prim->prev = aux;
	}
	else {
		lista->ultim = aux;
	}
	lista->prim = aux;
}


Santier initSantier(const char* numeProiect, int nrMuncitori, float suprafata) {
	Santier santier;
	santier.numeProiect = (char*)malloc(strlen(numeProiect) + 1);
	strcpy(santier.numeProiect, numeProiect);
	santier.nrMuncitori = nrMuncitori;
	santier.suprafata = suprafata;
	return santier;
}


void afisareSantier(Santier santier) {
	printf("Santierul %s are %d muncitori si o suprafata %5.2f m2 \n", santier.numeProiect, santier.nrMuncitori, santier.suprafata);
}


float densitateSantier(Santier santier) {
	if (santier.suprafata > 0) {
		return santier.nrMuncitori / santier.suprafata;
	}
	else return 0;
}

void afisareLdiInceput(ListaDubla lista) {
	for (NodLdi* nod = lista.prim; nod != NULL; nod = nod->next) {
		afisareSantier(nod->info);
	}
	printf("\n");
}

void stergereSantierNume(ListaDubla* lista, const char* numeSantier) {
	NodLdi* nod = lista->prim;
	while (nod != NULL) {
		if (strcmp(nod->info.numeProiect, numeSantier) == 0) {
			if (nod->prev == NULL) {
				if (nod->next == NULL) {
					lista->prim = lista->ultim = NULL;
				}
				else {
					nod->next->prev = NULL;
					lista->prim = nod->next;
				}
			}
			else {
				if (nod->next == NULL) {
					nod->prev->next = NULL;
					lista->ultim = nod->prev;
				}
				else {
					nod->prev->next = nod->next;
					nod->next->prev = nod->prev;
				}
			}
			free(nod->info.numeProiect);
			free(nod);
			nod = NULL;
		}
		else {
			nod = nod->next;
		}
	}
}
void setergereCompleta(ListaDubla* lista) {
	if (lista != NULL) {
		while (lista != NULL) {
			NodLdi* aux = lista->prim;
			while (aux != NULL) {
				free(aux->info.numeProiect);
				NodLdi* temp = aux->next;
				free(aux);
				aux = temp;
			}
			lista->prim=NULL;
			lista->ultim=NULL;
		}
	}
}

int nrMunctioriTotal(ListaDubla lista) {
	int suma = 0;
	for (NodLdi* i = lista.prim; i != NULL; i = i->next) {
		suma += i->info.nrMuncitori;
	}
	return suma;
}

int calcNrMuncitoriSuprafata(ListaDubla lista, float suprafataMax) {
	int suma = 0;
	for (NodLdi* i = lista.prim; i != NULL; i = i->next) {
		if (i->info.suprafata < suprafataMax) {
			suma += i->info.nrMuncitori;
		}
	}
	return suma;
}

int main() {
	Santier s1 = initSantier("Santier 1", 10, 300);
	Santier s2 = initSantier("Santier 2", 20, 500);
	Santier s3 = initSantier("Santier 3", 50, 800);
	ListaDubla lista;
	lista.prim = NULL;
	lista.ultim = NULL;
	inserareInceput(&lista, s1);
	inserareInceput(&lista, s2);
	inserareInceput(&lista, s3);
	afisareLdiInceput(lista);

	stergereSantierNume(&lista,"Santier 2");
	afisareLdiInceput(lista);
	stergereSantierNume(&lista,"Santier 1");
	afisareLdiInceput(lista);
	stergereSantierNume(&lista,"Santier 3");
	afisareLdiInceput(lista);

	printf("Nr muncitori: %d \n", nrMunctioriTotal(lista));
	printf("Nr Muncitori: %d", calcNrMuncitoriSuprafata(lista, 650));
}