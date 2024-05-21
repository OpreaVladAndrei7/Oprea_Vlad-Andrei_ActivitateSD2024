//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<malloc.h>
//
//typedef struct Casa Casa;
//typedef struct Nod Nod;
//typedef struct Nod2 Nod2;
//typedef struct ListaDubla ListaDubla;
//
//struct Casa {
//	char* strada;
//	int suprafata;
//};
//
//struct Nod {
//	Casa casa;
//	Nod* next;
//};
//
//struct ListaDubla {
//	Nod2* inceput;
//	Nod2* final;
//};
//
//struct Nod2
//{
//	Nod2* next;
//	Nod2* prev;
//	Casa casa;
//};
//
//Nod* adaugareListaLIFO(Nod* rad, Casa c) {
//	Nod* nod = malloc(sizeof(Nod));
//	nod->casa = c;
//	nod->next = rad;
//	return nod;
//}
//
//void adaugareListaFIFO(Nod** rad, Casa c) {
//	Nod* nod = malloc(sizeof(Nod));
//	nod->casa = c;
//	nod->next = NULL;
//	if ((*rad) == NULL) {
//		(*rad) = nod;
//	}
//	else {
//		while ((*rad)->next != NULL) {
//			(*rad) = (*rad)->next;
//		}
//		(*rad)->next = nod;
//	}
//}
//
//Casa initCasa(char* strada, int suprafata) {
//	struct Casa c;
//	c.strada = malloc(strlen(strada) + 1);
//	strcpy(c.strada, strada);
//	c.suprafata = suprafata;
//	return c;
//}
//
//void afisareCasa(Casa c) {
//	printf("Strada: %s, suprafata: %d\n", c.strada, c.suprafata);
//}
//
//void afisareListaS(Nod* rad) {
//	while (rad != NULL) {
//		afisareCasa(rad->casa);
//		rad = rad->next;
//	}
//}
//
//Casa* vectorLIFOAdaugare(Casa c, Casa** vector, int nrElemente) {
//	Casa* aux = malloc(sizeof(Casa) * (nrElemente + 1));
//	aux[0] = c;
//	for (int i = 0; i < nrElemente; i++) {
//		aux[i + 1] = (*vector)[i];
//	}
//	free(*vector);
//	return aux;
//}
//
//Casa* vectorFIFOAdaugare(Casa c, Casa** vector, int nrElemente) {
//	Casa* aux = malloc(sizeof(Casa) * (nrElemente + 1));
//	aux[nrElemente] = c;
//	for (int i = 0; i < nrElemente; i++) {
//		aux[i] = (*vector)[i];
//	}
//	free(*vector);
//	return aux;
//}
//
//void adaugareInceputLD(ListaDubla* ld, Casa c) {
//	Nod2* nod = malloc(sizeof(Nod2));
//	if (nod != NULL) {
//		nod->casa = c;
//		nod->prev = NULL;
//		nod->next = (*ld).inceput;
//
//		if ((*ld).inceput != NULL) {
//			(*ld).inceput->prev=nod;
//		}
//		else {
//			(*ld).final = nod ;
//		}
//		(*ld).inceput = nod;
//	}
//}
//
//void adaugareFinalListaDubla(ListaDubla* ld, Casa c) {
//	Nod2* nod = malloc(sizeof(Nod2));
//	nod->next = NULL;
//	nod->casa = c;
//	if (ld->final == NULL) {
//		nod->prev = NULL;
//		(*ld).inceput = (*ld).final = nod;
//	}
//	else {
//		nod->prev = (*ld).final;
//		(*ld).final->next = nod;
//		(*ld).final = nod;
//	}
//}
//
//void afisareLD(ListaDubla ld) {
//	while (ld.inceput != NULL) {
//		afisareCasa(ld.inceput->casa);
//		ld.inceput = ld.inceput->next;
//	}
//}
//
//void freeCasa(Casa c) {
//	free(c.strada);
//}
//
//void freeListaS(Nod* rad) {
//	while (rad != NULL) {
//		Nod* temp = rad;
//		rad = rad->next;
//		freeCasa(temp->casa);
//		free(temp);
//	}
//}
//
//void freeListaDubla(ListaDubla ld) {
//	Nod2* current = ld.inceput;
//	while (current != NULL) {
//		Nod2* temp = current;
//		current = current->next;
//		freeCasa(temp->casa);
//		free(temp);
//	}
//}
//
//void main() {
//	Casa c1 = initCasa("Biruintei", 120);
//	Casa c2 = initCasa("Iuliu Maniu", 60);
//	Casa c3 = initCasa("Rezervelor",55);
//	
//	Casa* vector = NULL;
//	vector = vectorLIFOAdaugare(c1, &vector, 0);
//	vector = vectorLIFOAdaugare(c2, &vector, 1);
//	vector = vectorLIFOAdaugare(c3, &vector, 2);
//
//	for (int i = 0; i < 3; i++) {
//		afisareCasa(vector[i]);
//	}
//
//	printf("\n\n");
//	Nod* nod = NULL;
//	nod = adaugareListaLIFO(nod, c1);
//	nod = adaugareListaLIFO(nod, c2);
//	nod = adaugareListaLIFO(nod, c3);
//	afisareListaS(nod);
//
//
//	printf("\n\n");
//
//	ListaDubla ld;
//	ld.inceput = ld.final = NULL;
//	adaugareInceputLD(&ld, c1);
//	adaugareInceputLD(&ld, c2);
//	adaugareInceputLD(&ld, c3);
//
//	afisareLD(ld);
//
//
//	printf("\n\n");
//
//	Casa* vectorFIFO = NULL;
//	vectorFIFO = vectorFIFOAdaugare(c1, &vectorFIFO, 0);
//	vectorFIFO = vectorFIFOAdaugare(c2, &vectorFIFO, 1);
//	vectorFIFO = vectorFIFOAdaugare(c3, &vectorFIFO, 2);
//
//	for (int i = 0; i < 3; i++) {
//		afisareCasa(vectorFIFO[i]);
//	}
//
//	printf("\n\n");
//
//	Nod* nodFIFO = NULL;
//	adaugareListaFIFO(&nodFIFO, c1);
//	Nod* inceput = nodFIFO;
//	adaugareListaFIFO(&nodFIFO, c2);
//	adaugareListaFIFO(&nodFIFO, c3);
//
//	afisareListaS(inceput);
//
//
//	printf("\n\n");
//	ListaDubla ldFIFO;
//	ldFIFO.inceput = ldFIFO.final = NULL;
//	adaugareFinalListaDubla(&ldFIFO, c1);
//	adaugareFinalListaDubla(&ldFIFO, c2);
//	adaugareFinalListaDubla(&ldFIFO, c3);
//
//	afisareLD(ldFIFO);
//
//	for (int i = 0; i < 3; i++) {
//		freeCasa(vector[i]);
//	}
//
//	free(vector);
//}