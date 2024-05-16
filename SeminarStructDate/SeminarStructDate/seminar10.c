//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//typedef struct Rezervare Rezervare;
//struct Rezervare {
//	int id;
//	char* numeClient;
//	int nrPersoane;
//};
//
//typedef struct Nod Nod;
//struct Nod {
//	Nod* stg;
//	Nod* dr;
//	Rezervare info;
//};
//
//Rezervare citireRezervare(FILE* f) {
//	Rezervare r;
//	char aux[30];
//	fscanf(f, "%d",&r.id);
//	fscanf(f, "%s", &aux);
//	r.numeClient = malloc(strlen(aux) + 1);
//	strcpy(r.numeClient, aux);
//	fscanf(f, "%d", &r.nrPersoane);
//	return r;
//}
//
//Nod* inserareInArbore(Nod* arbore, Rezervare rez) {
//	if (arbore != NULL) {
//		if (arbore->info.id < rez.id) {
//			arbore->dr = inserareInArbore(arbore->dr, rez);
//		}
//		else {
//			arbore->stg = inserareInArbore(arbore->stg, rez);
//		}
//	}
//	else {
//		Nod* rad = malloc(sizeof(Nod));
//		rad->info = rez;
//		rad->dr = NULL;
//		rad->stg = NULL;
//
//		arbore = rad;
//	}
//	return arbore;
//}
//
//void citireFisier(const char* numeFisier, Nod** radacina) {
//	FILE* f = fopen(numeFisier, "r");
//	int nrRezervari;
//	fscanf(f, "%d", &nrRezervari);
//
//	for (int i = 0; i < nrRezervari; i++) {
//		Rezervare rez = citireRezervare(f);
//		(*radacina) = inserareInArbore(*radacina, rez);
//	}
//
//}
//
//void afisareRezervare(Rezervare rez) {
//	printf("%d %s %d\n", rez.id, rez.numeClient, rez.nrPersoane);
//}
//
//void afisareArborePreordine(Nod* arbore){
//	if (arbore != NULL) {
//		afisareRezervare(arbore->info);
//		afisareArborePreordine(arbore->stg);
//		afisareArborePreordine(arbore->dr);
//	}
//}
//
//void afisareArboreInOrdine(Nod* arbore) {
//	if(arbore!=NULL){
//		afisareArboreInOrdine(arbore->stg);
//		afisareRezervare(arbore->info);
//		afisareArboreInOrdine(arbore->dr);
//	}
//}
//
//void afisareArborePostOrdine(Nod* arbore) {
//	if (arbore != NULL) {
//		afisareArborePostOrdine(arbore->stg);
//		afisareArborePostOrdine(arbore->dr);
//		afisareRezervare(arbore->info);
//	}
//}
//
//Rezervare cautaRezerevareDupaId(Nod* radacina, int id) {
//	if (radacina != NULL) {
//		if (radacina->info.id < id) {
//			return cautaRezerevareDupaId(radacina->dr, id);
//		}
//		else {
//			if (radacina->info.id > id) {
//				return cautaRezerevareDupaId(radacina->stg, id);
//			}
//			else {
//				return radacina->info;
//			}
//		}
//	}
//	else {
//		Rezervare r;
//		r.id = -1;
//		r.numeClient = NULL;
//		r.nrPersoane = -1;
//
//		return r;
//	}
//}
//
//int nrTotalPerosane(Nod* rad) {
//	if (rad) {
//		int rPersoane = rad->info.nrPersoane;
//		int sPeroane = nrTotalPerosane(rad->stg);
//		int dPeroane = nrTotalPerosane(rad->dr);
//		int suma = rPersoane + dPeroane + sPeroane;
//		return suma;
//	}
//	else {
//		return 0;
//	}
//}
//
//void main() {
//	Nod* radacina = NULL;
//	citireFisier("Rezervari.txt", &radacina);
//	afisareArborePreordine(radacina);
//
//
//	afisareRezervare(cautaRezerevareDupaId(radacina, 10));
//	printf("\n\n");
//	printf("Nr total pers %d", nrTotalPerosane(radacina));
//}