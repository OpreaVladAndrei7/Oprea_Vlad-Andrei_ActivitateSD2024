#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

struct Avion{
	int locuri;
	char* denumire;
	int nrPasageri;
	int* codPasager;
};

struct Avion citireAvion() {
	struct Avion av1;
	scanf_s("%d", &av1.locuri);
	av1.denumire = (char*)malloc(40 * sizeof(char));
	scanf("%s", av1.denumire);
	scanf("%d", &av1.nrPasageri);
	av1.codPasager = (int*)malloc(sizeof(int) * av1.nrPasageri);
	for (int i = 0; i < av1.nrPasageri; i++) {
		scanf("%d", &av1.codPasager[i]);
	}
	return av1;
}

int minCodPasager(struct Avion av2) {
	int min = av2.codPasager[0];
	for (int i = 1; i < av2.nrPasageri; i++) {
		if (av2.codPasager[i] < min) {
			min = av2.codPasager[i];
		}
	}
	return min;
}

void modificareLocuri(struct Avion* av3, int locuriModificate) {
	av3->locuri = locuriModificate;
}

void afisareAvion(struct Avion av4) {
	printf("Avionul are locuri= %d \n", av4.locuri);
	printf("Denumire= %s \n", av4.denumire);
	printf("Nr pasageri= %d \n", av4.nrPasageri);
	for (int i = 0; i < av4.nrPasageri; i++) {
		printf("Pasagerul %d are codul: %d ", i+1, av4.codPasager[i]);
	}
}

void main() {
	struct Avion av = citireAvion();
	printf("%d \n", minCodPasager(av));
	modificareLocuri(&av, 20);
	printf("%d \n", av.locuri);
	afisareAvion(av);
	free(av.denumire);
	free(av.codPasager);
}