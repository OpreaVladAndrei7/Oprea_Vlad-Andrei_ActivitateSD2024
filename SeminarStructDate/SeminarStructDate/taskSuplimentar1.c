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

struct Avion* vectorAvioane(struct Avion* avioane, int dimensiune) {
	int k = 0;
	for (int i = 0; i < dimensiune; i++) {
		if (avioane[i].locuri % 2 == 0) {
			k++;
		}
	}
	struct Avion* avs = malloc(k * sizeof(avioane[0]));
	for (int i = 0; i < dimensiune; i++) {
		if (avioane[i].locuri % 2 == 0) {
			avs[i] = avioane[i];
		}
	}
	return avs;
}

struct Avion* vectorAvioaneNoi(struct Avion* avioane, int dimensiune) {
	int k = 0;
	for (int i = 0; i < dimensiune; i++) {
		if (avioane[i].denumire[0] == "A") {
			k++;
		}
	}
	struct Avion* avs1 = malloc(k * sizeof(avioane[0]));
	for (int i = 0; i < dimensiune; i++) {
		if (avioane[i].denumire == "A") {
			avs1[i] = avioane[i];
		}
	}
	return avs1;
}
struct Avion* concatVect(struct Avion* av5, int dim1, struct Avion* av6, int dim2){
	struct Avion* av7 = malloc((dim1+dim2)*sizeof(av5[0]));
	for (int i = 0; i < dim1; i++) {
		av7[i] = av5[i];
	}
	for (int i = dim1; i < dim1+dim2; i++) {
		av7[i] = av6[i-dim1];
	}
	return av7;
};

void afisareVector(struct Avion* avv, int dimensiune) {
	for (int i = 0; i < dimensiune; i++) {
		afisareAvion(avv[i]);
		printf("\n");
	}
}
void afisareFis(const char* denFisier, struct Avion av) {
	FILE *fisier = fopen(denFisier, "w");
	if (fisier == NULL) {
		printf("Nu se poate deschide fisierul \n");
	}
	fprintf(fisier, "%d\n", av.locuri);
	fprintf(fisier, "%d\n", strlen(av.denumire));
	fprintf(fisier, "%s\n", av.denumire);
	fprintf(fisier, "%d\n", av.nrPasageri);
	for (int i = 0; i < av.nrPasageri; i++) {
		fprintf(fisier, "%d ", av.codPasager[i]);
	}
	fprintf(fisier, "\n");
	fclose(fisier);
}
struct Avion citireFis(const char* denFisier) {
	struct Avion av;
	FILE* fisier = fopen(denFisier, "r");
	if (fisier == NULL) {
		printf("Nu se poate deschide fisierul \n");
		return av;
	}
	fscanf(fisier, "%d\n", &av.locuri);
	int nrCaractere = 0;
	fscanf(fisier, "%d\n", &nrCaractere);
	if (av.denumire != NULL) {
		free(av.denumire);
	}
	av.denumire = malloc(sizeof(char)*(nrCaractere + 1));
	fscanf(fisier, "%s\n", av.denumire);
	fscanf(fisier, "%d\n", &av.nrPasageri);
	if (av.codPasager != NULL) {
		free(av.codPasager);
	}
	av.codPasager = malloc(sizeof(int) * av.nrPasageri);
	for (int i = 0; i <= av.nrPasageri; i++) {
		fscanf(fisier, "%d", &av.codPasager[i]);
	}
	fclose(fisier);
	return av;
}


void main() {
	struct Avion av = citireAvion();
	printf("%d \n", minCodPasager(av));
	modificareLocuri(&av, 20);
	printf("%d \n", av.locuri);
	afisareAvion(av);
	

	struct Avion* avioane = malloc(5*sizeof(struct Avion));
	avioane[0] = av;
	avioane[1] = av;
	avioane[2] = av;
	avioane[3] = av;
	avioane[4] = av;

	afisareVector(avioane,5);

	afisareVector(concatVect(avioane,5,avioane,5),10);

	afisareVector(vectorAvioane,5);
	
	afisareVector(vectorAvioaneNoi, 5);

	char* fisier = malloc(9* sizeof(char));
	strcpy(fisier, "avio.txt");
	afisareFis(fisier, av);
	struct Avion* avioneF = malloc(10 * sizeof(struct Avion));
	for (int i = 0; i < 10; i++) {
		avioneF[i] = citireFis(fisier);
	}
	free(av.denumire);
	free(av.codPasager);
}