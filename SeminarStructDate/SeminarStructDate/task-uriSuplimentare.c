////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <malloc.h>
////
////struct Avion{
////	int locuri;
////	char* denumire;
////	int nrPasageri;
////	int* codPasager;
////};
////
////struct Nod {
////	struct Avion avion;         
////	struct Nod* urmator; 
////};
////
////struct Nod2 {
////	struct Avion avion;
////	struct Nod2* prev;
////	struct Nod2* next;
////};
////
////struct Nod* creareNod(struct Avion avion) {
////	struct Nod* nouNod = (struct Nod*)malloc(sizeof(struct Nod));
////	if (!nouNod) {
////		fprintf(stderr, "Eroare de alocare a memoriei.\n");
////	}
////	nouNod->avion = avion;
////	nouNod->urmator = NULL;
////	return nouNod;
////}
////
////void adaugaLaSfarsit(struct Nod** cap, struct Avion avion) {
////	struct Nod* nouNod = creareNod(avion);
////	if (*cap == NULL) {
////		*cap = nouNod;
////	}
////	else {
////		struct Nod* temp = *cap;
////		while (temp->urmator != NULL) {
////			temp = temp->urmator;
////		}
////		temp->urmator = nouNod;
////	}
////}
////
////void initializeazaListaDinVector(struct Nod** cap, struct Avion* vector, int marimeVector) {
////	for (int i = 0; i < marimeVector; i++) {
////		adaugaLaSfarsit(cap, vector[i]);
////	}
////}
////
////void stergereNod(int pozitie, struct Nod** cap) {
////	if (*cap == NULL || pozitie < 0) {
////		return;
////	}
////
////	struct Nod* temp = *cap;
////	if (pozitie == 0) {
////		*cap = temp->urmator; 
////		free(temp);
////		return;
////	}
////
////	for (int i = 0; temp != NULL && i < pozitie - 1; i++) {
////		temp = temp->urmator;
////	}
////
////	if (temp == NULL || temp->urmator == NULL) {
////		return;
////	}
////
////	struct Nod* nodDeSters = temp->urmator;
////
////	temp->urmator = nodDeSters->urmator;
////
////	free(nodDeSters);
////}
////
////struct Avion citireAvion() {
////	struct Avion av1;
////	scanf_s("%d", &av1.locuri);
////	av1.denumire = (char*)malloc(40 * sizeof(char));
////	scanf("%s", av1.denumire);
////	scanf("%d", &av1.nrPasageri);
////	av1.codPasager = (int*)malloc(sizeof(int) * av1.nrPasageri);
////	for (int i = 0; i < av1.nrPasageri; i++) {
////		scanf("%d", &av1.codPasager[i]);
////	}
////	return av1;
////}
////
////int minCodPasager(struct Avion av2) {
////	int min = av2.codPasager[0];
////	for (int i = 1; i < av2.nrPasageri; i++) {
////		if (av2.codPasager[i] < min) {
////			min = av2.codPasager[i];
////		}
////	}
////	return min;
////}
////
////void modificareLocuri(struct Avion* av3, int locuriModificate) {
////	av3->locuri = locuriModificate;
////}
////
////void afisareAvion(struct Avion av4) {
////	printf("Avionul are locuri= %d \n", av4.locuri);
////	printf("Denumire= %s \n", av4.denumire);
////	printf("Nr pasageri= %d \n", av4.nrPasageri);
////	for (int i = 0; i < av4.nrPasageri; i++) {
////		printf("Pasagerul %d are codul: %d ", i+1, av4.codPasager[i]);
////	}
////}
////
////struct Avion* vectorAvioane(struct Avion* avioane, int dimensiune) {
////	int k = 0;
////	for (int i = 0; i < dimensiune; i++) {
////		if (avioane[i].locuri % 2 == 0) {
////			k++;
////		}
////	}
////	struct Avion* avs = malloc(k * sizeof(avioane[0]));
////	for (int i = 0; i < dimensiune; i++) {
////		if (avioane[i].locuri % 2 == 0) {
////			avs[i] = avioane[i];
////		}
////	}
////	return avs;
////}
////
////struct Avion* vectorAvioaneNoi(struct Avion* avioane, int dimensiune) {
////	int k = 0;
////	for (int i = 0; i < dimensiune; i++) {
////		if (avioane[i].denumire[0] == "A") {
////			k++;
////		}
////	}
////	struct Avion* avs1 = malloc(k * sizeof(avioane[0]));
////	for (int i = 0; i < dimensiune; i++) {
////		if (avioane[i].denumire == "A") {
////			avs1[i] = avioane[i];
////		}
////	}
////	return avs1;
////}
////struct Avion* concatVect(struct Avion* av5, int dim1, struct Avion* av6, int dim2){
////	struct Avion* av7 = malloc((dim1+dim2)*sizeof(av5[0]));
////	for (int i = 0; i < dim1; i++) {
////		av7[i] = av5[i];
////	}
////	for (int i = dim1; i < dim1+dim2; i++) {
////		av7[i] = av6[i-dim1];
////	}
////	return av7;
////};
////
////void afisareVector(struct Avion* avv, int dimensiune) {
////	for (int i = 0; i < dimensiune; i++) {
////		afisareAvion(avv[i]);
////		printf("\n");
////	}
////}
////
////struct Avion** matriceVector(struct Avion* ve, int nrAvioane) {
////	struct Avion** matrice = malloc(nrAvioane * sizeof(ve));
////	if (matrice == NULL) {
////		return NULL;
////	}
////	for (int i = 0; i < nrAvioane; i++) {
////		matrice[i] = malloc(nrAvioane * sizeof(struct Avion));
////	}
////}
////
////void afisareFis(const char* denFisier, struct Avion av) {
////	FILE *fisier = fopen(denFisier, "w");
////	if (fisier == NULL) {
////		printf("Nu se poate deschide fisierul \n");
////	}
////	fprintf(fisier, "%d\n", av.locuri);
////	fprintf(fisier, "%d\n", strlen(av.denumire));
////	fprintf(fisier, "%s\n", av.denumire);
////	fprintf(fisier, "%d\n", av.nrPasageri);
////	for (int i = 0; i < av.nrPasageri; i++) {
////		fprintf(fisier, "%d ", av.codPasager[i]);
////	}
////	fprintf(fisier, "\n");
////	fclose(fisier);
////}
////struct Avion citireFis(const char* denFisier) {
////	struct Avion av;
////	FILE* fisier = fopen(denFisier, "r");
////	if (fisier == NULL) {
////		printf("Nu se poate deschide fisierul \n");
////		return av;
////	}
////	fscanf(fisier, "%d\n", &av.locuri);
////	int nrCaractere = 0;
////	fscanf(fisier, "%d\n", &nrCaractere);
////	if (av.denumire != NULL) {
////		free(av.denumire);
////	}
////	av.denumire = malloc(sizeof(char)*(nrCaractere + 1));
////	fscanf(fisier, "%s\n", av.denumire);
////	fscanf(fisier, "%d\n", &av.nrPasageri);
////	if (av.codPasager != NULL) {
////		free(av.codPasager);
////	}
////	av.codPasager = malloc(sizeof(int) * av.nrPasageri);
////	for (int i = 0; i <= av.nrPasageri; i++) {
////		fscanf(fisier, "%d", &av.codPasager[i]);
////	}
////	fclose(fisier);
////	return av;
////}
////
////
////void afisareDinMatrice(struct Avion** avs, int nrLinii, int nrColoane) {
////	for (int i = 0; i < nrColoane; i++) {
////		for (int j = 0; j < nrLinii; j++) {
////			afisareAvion(avs[i][j]);
////		}
////	}
////}
////
////void stergeNodPePozitie(struct Nod2** cap, int pozitie) {
////	if (*cap == NULL || pozitie < 0) {
////		return;
////	}
////
////	struct Nod2* temp = *cap;
////	int contor = 0;
////
////	while (temp != NULL && contor < pozitie) {
////		temp = temp->next;
////		contor++;
////	}
////
////	if (temp != NULL) {
////		if (temp == *cap) {
////			*cap = temp->next;
////		}
////
////		if (temp->prev) {
////			temp->prev->next = temp->next;
////		}
////		if (temp->next) {
////			temp->next->prev = temp->prev;
////		}
////		elibereazaAvion(&temp->avion);
////		free(temp);
////	}
////}
////
////void elibereazaAvion(struct Avion* avion) {
////	free(avion->denumire); 
////	free(avion->codPasager); 
////}
////
////void insereazaSortat(struct Nod2** cap,struct Avion avionNou) {
////	struct Nod2* nodNou = (struct Nod2*)malloc(sizeof(struct Nod2));
////	nodNou->avion = avionNou;
////	nodNou->next = nodNou->prev = NULL;
////
////	if (*cap == NULL || (*cap)->avion.nrPasageri >= avionNou.nrPasageri) {
////		nodNou->next = *cap;
////		if (*cap != NULL) {
////			(*cap)->prev = nodNou;
////		}
////		*cap = nodNou;
////	}
////	else {
////		struct Nod2* temp = *cap;
////		while (temp->next != NULL && temp->next->avion.nrPasageri < avionNou.nrPasageri) {
////			temp = temp->next;
////		}
////		nodNou->next = temp->next;
////		if (temp->next != NULL) {
////			temp->next->prev = nodNou;
////		}
////		temp->next = nodNou;
////		nodNou->prev = temp;
////	}
////}
////
////void main() {
////	struct Avion av = citireAvion();
////	printf("%d \n", minCodPasager(av));
////	modificareLocuri(&av, 20);
////	printf("%d \n", av.locuri);
////	afisareAvion(av);
////	
////
////	struct Avion* avioane = malloc(5*sizeof(struct Avion));
////	avioane[0] = av;
////	avioane[1] = av;
////	avioane[2] = av;
////	avioane[3] = av;
////	avioane[4] = av;
////
////	afisareVector(avioane,5);
////
////	afisareVector(concatVect(avioane,5,avioane,5),10);
////
////	afisareVector(vectorAvioane,5);
////	
////	afisareVector(vectorAvioaneNoi, 5);
////
////	char* fisier = malloc(9* sizeof(char));
////	strcpy(fisier, "avio.txt");
////	afisareFis(fisier, av);
////	struct Avion* avioneF = malloc(10 * sizeof(struct Avion));
////	for (int i = 0; i < 10; i++) {
////		avioneF[i] = citireFis(fisier);
////	}
////	free(av.denumire);
////	free(av.codPasager);
////}
////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <stdlib.h>
////#include <string.h>
////
////typedef struct Masini Masini;
////struct Masini {
////    int id;
////    char* producator;
////    int nrUsi;
////    float pret;
////};
////
////Masini* adaugareVector(Masini masina, Masini* masini, int* nrMasini) {
////    Masini* aux = (Masini*)malloc(sizeof(Masini) * ((*nrMasini) + 1));
////    for (int i = 0; i < *nrMasini; i++) {
////        aux[i] = masini[i];
////    }
////    aux[*nrMasini] = masina;
////    (*nrMasini)++;
////    free(masini);
////    return aux;
////}
////
////Masini* citireMasini(const char* numeFisier, int* nrMasini) {
////    FILE* f = fopen(numeFisier, "r");
////    if (f == NULL) {
////        printf("Failed to open the file\n");
////        return NULL;
////    }
////    Masini* masini = NULL;
////    *nrMasini = 0;
////    char buffer[100];
////    const char* delimitare = " ,\n";
////    while (fgets(buffer, 100, f) != NULL) {
////        Masini m;
////        char* element = strtok(buffer, delimitare);
////        m.id = atoi(element);
////        element = strtok(NULL, delimitare);
////        m.producator = malloc(strlen(element) + 1);
////        strcpy(m.producator, element);
////        element = strtok(NULL, delimitare);
////        m.nrUsi = atoi(element);
////        element = strtok(NULL, delimitare);
////        m.pret = atof(element);
////        masini = adaugareVector(m, masini, nrMasini);
////    }
////    fclose(f);
////    return masini;
////}
////
////int main() {
////    int nrMasini = 0;
////    Masini* masini = citireMasini("masini.txt", &nrMasini);
////    for (int i = 0; i < nrMasini; i++) {
////        printf("ID: %d, Producator: %s, Usi: %d, Pret: %.2f\n",
////            masini[i].id, masini[i].producator, masini[i].nrUsi, masini[i].pret);
////    }
////    // Clean up dynamically allocated memory
////    for (int i = 0; i < nrMasini; i++) {
////        free(masini[i].producator);
////    }
////    free(masini);
////    return 0;
////}
////
////#define _CRT_SECURE_NO_WARNINGS
////#include<stdio.h>
////#include<malloc.h>
////#include<string.h>
////
////typedef struct Avion Avion;
////struct Avion {
////	char* model;
////	int nrScaune;
////	float lungime;
////};
////
////Avion* salvareVector(Avion avion, Avion* avioane, int* nrAvioane) {
////	Avion* aux = (Avion*)malloc(sizeof(Avion) * ((*nrAvioane) + 1));
////	for (int i = 0; i < *nrAvioane; i++) {
////		aux[i] = avioane[i];
////	}	
////	aux[(*nrAvioane)] = avion;
////	(*nrAvioane)++;
////	if (avioane != NULL) {
////		free(avioane);
////	}
////	return aux;
////}
////
////Avion* citireAvioane(const char* numeFisier, int* nrAvioane) {
////	Avion* avioane = NULL;
////	*nrAvioane = 0;
////	const char* delimitare = ",\n";
////	char buffer[100];
////	FILE* f = fopen(numeFisier, "r");
////	while (fgets(buffer, 100, f) != NULL) {
////		Avion a;
////		char* element = strtok(buffer, delimitare);
////		a.model = malloc(strlen(element) + 1);
////		strcpy(a.model, element);
////		element = strtok(NULL, delimitare);
////		a.nrScaune = atoi(element);
////		element = strtok(NULL, delimitare);
////		a.lungime = atoi(element);
////		avioane = salvareVector(a, avioane, nrAvioane);
////	}
////	fclose(f);
////	return avioane;
////}
////
////void scriereAvion(const char* numeFisier, Avion av) {
////	FILE* f = fopen(numeFisier, "w");
////	fprintf(f,"%s,%d,%5.1f", av.model, av.nrScaune, av.lungime);
////	fclose(f);
////}
////void main() {
////	int nrAvioane = 0;
////	Avion* avioane = citireAvioane("avioane.txt", &nrAvioane);
////	for (int i = 0; i < nrAvioane; i++) {
////		printf("Modelul %s cu nr locuri %d si pretul de %5.1f\n", avioane[i].model, avioane[i].nrScaune, avioane[i].lungime);
////	}
////	scriereAvion("avi.txt", avioane[0]);
////}
//
////#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
////#include <string.h>
////#include <malloc.h>
////
////typedef struct Santier Santier;
////typedef struct Nod Nod;
////
////struct Santier {
////	char* numeProiect;
////	int nrMuncitori;
////	float suprafata;
////};
////
////struct Nod {
////	Santier santier;
////	Nod* next;
////};
////
////Santier initSantier(char* numeProiect, int nrMuncitori, float suprafata) {
////	Santier santier;
////	santier.numeProiect = malloc(strlen(numeProiect) + 1);
////	strcpy(santier.numeProiect, numeProiect);
////	santier.nrMuncitori = nrMuncitori;
////	santier.suprafata = suprafata;
////	return santier;
////}
////
////void afisareSantier(Santier santier) {
////	printf("Santierul %s are %d muncitori si o suprafata %5.2f m2 \n", santier.numeProiect, santier.nrMuncitori, santier.suprafata);
////}
////
////void afisareLista(Nod* lista) {
////	while (lista != NULL) {
////		afisareSantier(lista->santier);
////		lista = lista->next;
////	}
////}
////
////void inserareLaInceput(Nod** cap, Santier santier) {
////	Nod* nod = malloc(sizeof(Nod));
////	nod->santier = santier;
////	nod->next = *cap;
////	*cap = nod;
////}
////
////void stergereNod(Nod** lista, int pozitie) {
////	Nod* aux = *lista;
////	if(pozitie==0){		
////	*lista = aux->next;		
////	free(aux);	
////		return;
////	}
////	for (int i = 0; aux->next != NULL && i < pozitie -1; i++) {
////		aux = aux->next;
////	}
////	if (aux == NULL || aux->next == NULL) {
////		printf("Pozitia este mai mare decat lungimea listei.\n");
////		return;
////	}
////	Nod* urmator = aux->next->next;
////	free(aux->next);
////	aux->next = urmator;
////}
////void inseareNrMunc(Nod** cap, Santier santier) {
////	Nod* nod = malloc(sizeof(Nod));
////	nod->santier = santier;
////	if (*cap == NULL || (*cap)->santier.nrMuncitori > nod->santier.nrMuncitori) {
////		nod->next = (*cap);
////		(*cap) = nod;
////		return;
////	}
////	Nod* temp = *cap;
////	while (temp->next != NULL && temp->next->santier.nrMuncitori <= nod->santier.nrMuncitori) {
////			temp = temp->next;
////		}
////	nod->next = temp->next;
////	temp->next = nod;
////	}
////
////void main() {
////	Nod* cap = NULL;
////	inseareNrMunc(&cap, initSantier("Arsen", 2, 23.4));
////	inseareNrMunc(&cap, initSantier("Arseni", 5, 23.4));
////	inseareNrMunc(&cap, initSantier("Arsenie", 4, 23.4));
////	inseareNrMunc(&cap, initSantier("Arsenie", 3, 23.4));
////	stergereNod(&cap, 2);
////	afisareLista(cap);
////}
//
////#define _CRT_SECURE_NO_WARNINGS
////#include<stdio.h>
////#include<string.h>
////#include<malloc.h>
////
////typedef struct Moneda Moneda;
////typedef struct Nod Nod;
////
////struct Moneda {
////	char* taraEmitenta;
////	int valoareNominala;
////	float greutate;
////	int anEmitere;
////};
////
////struct Nod {
////	Moneda moneda;
////	Nod* next;
////};
////
////Moneda initMonezi(char* taraEmitenta, int valoareNominala, float greutate, int anEmitere) {
////	Moneda moneda;
////	moneda.taraEmitenta = malloc(strlen(taraEmitenta) + 1);
////	strcpy(moneda.taraEmitenta, taraEmitenta);
////	moneda.valoareNominala = valoareNominala;
////	moneda.greutate = greutate;
////	moneda.anEmitere = anEmitere;
////	return moneda;
////}
////
////void inserareMonezi(Nod** cap, Moneda moneda) {
////	Nod* nod = (Nod*)malloc(sizeof(Nod));
////	nod->moneda = moneda;
////	nod->next = (*cap);
////	(*cap) = nod;
////}
////
////void afisareMoneda(Moneda mon) {
////	printf("%s %d %5.2f %d \n", mon.taraEmitenta, mon.valoareNominala, mon.greutate, mon.anEmitere);
////}
////void afisareLista(Nod* cap) {
////	while (cap != NULL) {
////		afisareMoneda((*cap).moneda);
////		cap = cap->next;
////	}
////}
////Moneda greuMax(Nod* cap) {
////	Nod* aux = cap;
////	while (cap != NULL) {
////		if (aux->moneda.greutate < cap->moneda.greutate) {
////			aux = cap;
////		}
////		cap = cap->next;
////	}
////	Moneda* max = malloc(sizeof(Moneda));
////	max->taraEmitenta = malloc(strlen(aux->moneda.taraEmitenta) + 1);
////	strcpy(max->taraEmitenta, aux->moneda.taraEmitenta);
////	max->valoareNominala = aux->moneda.valoareNominala;
////	max->greutate = aux->moneda.greutate;
////	max->anEmitere = aux->moneda.anEmitere;
////	return *max;
////}
////
////void stergereMon(Nod** cap, float greutate) {
////	if ((*cap)->moneda.greutate == greutate) {
////		free(cap);
////		(*cap) = (*cap)->next;
////		return;
////	}
////	Nod* aux = malloc(sizeof(Nod));
////	Nod* temp = malloc(sizeof(Nod));
////	aux = (*cap);
////
////	while (aux != NULL && aux->moneda.greutate != greutate) {
////		temp = aux;
////		aux = aux->next;
////	}
////	if (aux == NULL && aux->moneda.greutate == greutate) {
////		temp->next = NULL;
////		free(aux);
////		return;
////	}
////	if (aux == NULL) {
////		printf("Nu s a gasit greutatea");
////	}
////	else {
////		temp->next = aux->next;
////		free(aux);
////	}
////}
////void stergereMem(Nod** lista) {
////	Nod* current;
////	while (*lista != NULL) {
////		current = *lista;
////		*lista = current->next;
////		free(current->moneda.taraEmitenta);
////		free(current);
////	}
////}
////void main() {
////	Nod* lista = NULL;
////	inserareMonezi(&lista, initMonezi("Cent", 5, 12.3, 1996));
////	inserareMonezi(&lista, initMonezi("Ban", 5, 2.3, 1992));
////	inserareMonezi(&lista, initMonezi("Yen", 5, 14.3, 1990));
////	inserareMonezi(&lista, initMonezi("Rubla", 5, 19.1, 1994));
////	afisareLista(lista);
////	afisareMoneda(greuMax(lista));
////	stergereMon(&lista, 12.3);
////	afisareLista(lista);
////	stergereMem(&lista);
////}
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<malloc.h>
//#include<stdlib.h>
//
//typedef struct Tara Tara;
//typedef struct Nod2 Nod2;
//typedef struct ListaDubla ListaDubla;
//
//struct Tara {
//	char* nume;
//	long populatie;
//	float suprafata;
//};
//
//struct Nod2 {
//	Nod2* prev;
//	Nod2* next;
//	Tara tara;
//};
//
//struct ListaDubla {
//	Nod2* prim;
//	Nod2* ultim;
//};
//
//Tara* adaugareVector(Tara* vector, Tara tara, int *nrTari) {
//		Tara* aux = malloc(((*nrTari) + 1) * sizeof(Tara));
//		if (vector != NULL) {
//			for (int i = 0; i < *nrTari; i++) {
//				aux[i] = vector[i];
//			}
//		}
//		aux[*nrTari] = tara;
//		(*nrTari)++;
//	return aux;
//}
//
//Tara* citireFisier(const char* numefisier, int* nrTari) {
//	FILE* f = fopen(numefisier, "r");
//	Tara* tari = NULL;
//	char buffer[100];
//	char* delimitare = ",\n";
//	*nrTari = 0;
//	while (fgets(buffer, 100, f) != NULL) {
//		Tara t;
//		char* element = strtok(buffer, delimitare);
//		t.nume = malloc(strlen(element) + 1);
//		strcpy(t.nume, element);
//		element = strtok(NULL, delimitare);
//		t.populatie = atoi(element);
//		element = strtok(NULL, delimitare);
//		t.suprafata = atof(element);
//		tari=adaugareVector(tari, t, nrTari);
//	}
//	fclose(f);
//	return tari;
//}
//
//void afisareTara(Tara t) {
//	printf("%s %ld %5.2f \n", t.nume, t.populatie, t.suprafata);
//}
//
//void inserareInceput(ListaDubla* lista, Tara s) {
//		Nod2* aux = malloc(sizeof(Nod2));
//		aux->tara = s;
//		aux->prev = NULL;
//		aux->next = lista->prim;
//		if (lista->prim != NULL) {
//			lista->prim->prev = aux;
//		}
//		else {
//			lista->ultim = aux;
//		}
//		lista->prim = aux;
//	}
//Nod2* listDbl(Tara* tari, int nrTari) {
//	ListaDubla* lista = malloc(sizeof(ListaDubla));
//	for (int i = 0; i < nrTari; i++) {
//		inserareInceput(lista, tari[i]);
//	}
//	return lista->prim;
//}
//
//void afisareLista(Nod2* lista) {
//	while (lista != NULL) {
//		afisareTara(lista->tara);
//		lista = lista->next;
//	}
//}
//
//void main() {
//	Tara* tari = NULL;
//	int nrTari = 0;
//	tari = citireFisier("tari.txt", &nrTari);
//	for (int i = 0; i < 3; i++) {
//		afisareTara(tari[i]);
//	}
//	Nod2* listaDbl = listDbl(tari, nrTari);
//	afisareLista(listaDbl);
//}