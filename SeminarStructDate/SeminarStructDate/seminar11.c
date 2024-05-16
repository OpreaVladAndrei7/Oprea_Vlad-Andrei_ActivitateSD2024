// binary search tree

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>


typedef struct Rezervare Rezervare;
typedef struct Nod Nod;

struct Rezervare {
	int id;
	char* nume_client;
	int nr_pers;
};

struct Nod {
	Rezervare info;
	Nod* fs;
	Nod* fd;
};

Rezervare r_initfromfile(FILE* f) {
	Rezervare r;
	char buffer[50];
	fscanf(f, "%d", &r.id);
	fscanf(f, "%s", &buffer);
	r.nume_client = (char*)malloc(strlen(buffer) + 1);
	strcpy(r.nume_client, buffer);
	fscanf(f, "%d", &r.nr_pers);

	return r;
}

Nod* rotireLaDreapta(Nod* rad) {
	Nod* aux = NULL;
	if (rad) {
		aux = rad->fs;
		rad->fs = aux->fd;
		aux->fd = rad;
	}
	return aux;
}

Nod* rotireLaStanga(Nod* rad) {
	Nod* aux = NULL;
	if (rad) {
		aux = rad->fd;
		rad->fd = aux->fs;
		aux->fs = rad;
	}
	return aux;
}

int gradEchilibru(Nod* rad) {
	if (rad) {
		int inaltimeStanga = inaltimeArbore(rad->fs);
		int inaltimeDreapta = inaltimeArbore(rad->fd);
		return inaltimeStanga - inaltimeDreapta;
	}
	else {
		return 0;
	}
}

Nod* a_insert(Nod* a, Rezervare r) {
	if (a) {
		if (a->info.id < r.id) {
			a->fd = a_insert(a->fd, r);
		}
		else {
			a->fs = a_insert(a->fs, r);
		}
		int grad = gradEchilibru(a);
		if (grad == 2) {
			if (gradEchilibru(a->fs)==-1) {
				a->fs = rotireLaStanga(a->fs);
			}
			a = rotireLaDreapta(a);
		}
		if (grad == -2) {
			if (gradEchilibru(a->fd) == 1) {
				a->fd = rotireLaDreapta(a->fd);
			}
				a = rotireLaStanga(a);
		}
	}
	else {
		Nod* temp = (Nod*)malloc(sizeof(Nod));
		temp->info = r;//shallow copy
		temp->fd = NULL;
		temp->fs = NULL;
		a = temp;
	}
	return a;
}

void a_readfromfile(const char* filename, Nod** a) {
	FILE* f = fopen(filename, "r");
	int nr_rez;
	fscanf(f, "%d", &nr_rez);
	for (int i = 0; i < nr_rez; i++) {

		Rezervare r = r_initfromfile(f);
		*a = a_insert(*a, r);
	}
}

void r_afisare(Rezervare r) {
	printf("Rezervarea cu ID-ul %d a fost facuta de %s pentru %d persoane.\n", r.id, r.nume_client, r.nr_pers);
}

void a_afisare_preordine(Nod* a) {
	if (a != NULL) {
		r_afisare(a->info);
		a_afisare_preordine(a->fs);
		a_afisare_preordine(a->fd);
	}
}
void a_afisare_inordine(Nod* a) {
	if (a != NULL) {
		a_afisare_inordine(a->fs);
		r_afisare(a->info);
		a_afisare_inordine(a->fd);
	}
}
void a_afisare_postordine(Nod* a) {
	if (a != NULL) {
		a_afisare_postordine(a->fs);
		a_afisare_postordine(a->fd);
		r_afisare(a->info);
	}
}

Rezervare a_findByID(Nod* a, int id) {
	if (a) {
		if (a->info.id < id) {
			return a_findByID(a->fd, id);
		}
		else {
			if (a->info.id > id) {
				return a_findByID(a->fs, id);
			}
			else {
				return a->info;
			}
		}
	}
	else {
		Rezervare r;
		r.id = -1;
		r.nume_client = NULL;
		r.nr_pers = -1;
		return r;
	}
}

int a_calculnrpers(Nod* a) {
	if (a) {
		int r_pers = a->info.nr_pers;
		int s_pers = a_calculnrpers(a->fs);
		int d_pers = a_calculnrpers(a->fd);

		return r_pers + s_pers + d_pers;
	}
	return 0;


}


int inaltimeArbore(Nod* rad) {
	if (rad) {
		int inaltimeStanga = inaltimeArbore(rad->fs);
		int inaltimeDreapta = inaltimeArbore(rad->fd);
		return 1 + (inaltimeStanga > inaltimeDreapta ? inaltimeStanga : inaltimeDreapta);
	}
	else {
		return 0;
	}
}

void stergereArbore(Nod** rad) {
	if ((*rad)) {
		stergereArbore(&(*rad)->fs);
		stergereArbore(&(*rad)->fd);
		free((*rad)->info.nume_client);
		free(*rad);
		(*rad) =NULL;
	}
}

void main() {
	Nod* arbore = NULL;
	a_readfromfile("Rezervari.txt", &arbore);

	a_afisare_preordine(arbore);
	printf("\n");
	r_afisare(a_findByID(arbore, 10));

	printf("\n");
	printf("%d persoane in total\n", a_calculnrpers(arbore));

	stergereArbore(&arbore);
	a_afisare_inordine(arbore);
}