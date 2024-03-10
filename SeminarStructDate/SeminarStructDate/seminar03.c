//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#include<stdlib.h>
//
//struct Masina {
//	int id;
//	char* producator;
//	int nrUsi;
//	float pret;
//};
//
//struct Masina* adaugareVector(struct Masina* masini, struct Masina m, int* nrMasini) {
//
//	struct Masina* aux = (struct Masina*)malloc(sizeof(struct Masina) * ((*nrMasini) + 1));
//	for (int i = 0; i < nrMasini; i++) {
//		aux[i] = masini[i];
//	}
//	aux[*nrMasini] = m;
//	(*nrMasini)++;
//	if (masini != NULL) {
//		free(masini);
//	}
//	return aux;
//}
//
//struct Maisna* citireMasinaFis(const char* numeFisier, int *nrMasini) {
//	FILE* f = fopen(numeFisier, "r");
//	char buffer[100];
//	char delimitare[] = ",\n";
//	struct Masina* masini=NULL;
//	nrMasini = 0;
//	while (fgets(buffer, 100, f) != NULL) {
//		char* element = strtok(buffer, delimitare);
//		struct Masina m;
//		m.id = atoi(element);
//		element = strtok(NULL, delimitare);
//		m.producator = malloc(strlen(element + 1));
//		strcpy(m.producator, element);
//		element = strtok(NULL, delimitare);
//		m.nrUsi = atoi(element);
//		element = strtok(NULL, delimitare);
//		m.pret = atof(element);
//		masini = adaugareVector(masini, m, nrMasini);
//	}
//	return masini;
//	fclose(f);
//}
//
//
//
//
//int main() {
//
//}