//#include<stdio.h>
//#include<malloc.h>
//
//struct Farmacie {
//	int id;
//	char* nume;
//	float suprafata;
//};
//
//struct Farmacie initFarmacie(int id, const char* nume, float suprafata) {
//	struct Farmacie f;
//	f.id = id;
//	f.nume = (char*)malloc(sizeof(char*) * (strlen(nume) + 1));
//	strcpy(f.nume, nume);
//	f.suprafata = suprafata;
//	return f;
//}
//
//void afisareFarmacie(struct Farmacie farmacie) {
//	printf("%d. %s are o suprafata de %5.2f \n", farmacie.id, farmacie.nume, farmacie.suprafata);
//}
//
//void afisareVector(struct Farmacie* farmacii, int nrFarmacii) {
//	for (int i = 0; i < nrFarmacii; i++) {
//		afisareFarmacie(farmacii[i]);
//	}
//}
//
//struct Farmacie* copierNElemente(struct Farmacie* vector, int nrFarmacii, int nrObiecteCopiate) {
//	if(nrObiecteCopiate<=nrFarmacii && nrObiecteCopiate>0){
//		struct Farmacie* copiat = (struct Farmacie*)malloc(sizeof(struct  Farmacie) * nrObiecteCopiate);
//		for (int i = 0; i < nrObiecteCopiate; i++) {
//			copiat[i] = initFarmacie(vector[i].id, vector[i].nume, vector[i].suprafata);
//		}
//		return copiat;
//	}
//	else {
//		return NULL;
//	}
//}
//
//struct Farmacie* copiazaFarmaciiMici(struct Farmacie* farmacii, int nrFarmacii, float pragSuprafata, int* nrFarmaciiMici) {
//	*nrFarmaciiMici = 0;
//	for (int i = 0; i < nrFarmacii; i++) {
//		if (farmacii[i].suprafata < pragSuprafata) {
//			(*nrFarmaciiMici)++;
//		}
//	}
//	struct Farmacie* vector = (struct Farmacie*)malloc(sizeof(struct Farmacie) * (*nrFarmaciiMici));
//	int k = 0;
//	for (int i = 0; i < nrFarmacii; i++) {
//		if (farmacii[i].suprafata < pragSuprafata) {
//			vector[k++] = initFarmacie(farmacii[i].id, farmacii[i].nume, farmacii[i].suprafata);
//		}
//	}
//	return vector;
//}
//
//struct Farmacie getFarmacieById(struct Farmacie* vector, int nrFarmacii, int idCautat) {
//	for (int i = 0; i < nrFarmacii; i++) {
//		if (vector[i].id == idCautat) {
//			return initFarmacie(vector[i].id, vector[i].nume, vector[i].suprafata);
//		}
//	}
//	return initFarmacie(0, "N/A", 0);
//}
//
//void dezalocareVectorFarmacii(struct Farmacie** vector, int *nrFarmacii) {
//	for (int i = 0; i < *nrFarmacii; i++) {
//		free((*vector)[i].nume);
//	}
//	free(*vector);
//	*nrFarmacii = 0;
//	*vector = NULL;
//}
//
//int main() {
//	int nrFarmacii = 4;
//	struct Farmacie* farmacii = (struct Farmacie*)malloc(sizeof(struct Farmacie) * nrFarmacii);
//
//	for (int i = 0; i < nrFarmacii; i++) {
//		farmacii[i] = initFarmacie(i + 1, "Farmacie", 30 * i + 10);
//	}
//
//	afisareVector(farmacii, nrFarmacii);
//
//	int nrObiecteCopiate = 2;
//
//	struct Farmacie* vectorCopiat = copierNElemente(farmacii, nrFarmacii, nrObiecteCopiate);
//	printf("\n\n");
//	afisareVector(vectorCopiat, nrObiecteCopiate);
//	printf("\n\n");
//	int nrFarmaciiMici = 0;
//
//	farmacii[3].suprafata = 20;
//
//	struct Farmacie* farmaciiMici = copiazaFarmaciiMici(farmacii, nrFarmacii, 80, &nrFarmaciiMici);
//	afisareVector(farmaciiMici, nrFarmaciiMici);
//
//	printf("\n\n");
//
//	struct Farmacie farmacieCautata = getFarmacieById(farmacii, nrFarmacii, 3);
//	afisareFarmacie(farmacieCautata);
//
//	free(farmacieCautata.nume);
//	dezalocareVectorFarmacii(&farmacii, &nrFarmacii);
//	dezalocareVectorFarmacii(&vectorCopiat, &nrObiecteCopiate);
//	dezalocareVectorFarmacii(&farmaciiMici, &nrFarmaciiMici);
//}