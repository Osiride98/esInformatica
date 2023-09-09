#include "stalla.h"
#include "stalla.c"

int main(){
//PARTE 1
printf("---PARTE 1---\n");


int dimAnimali;

Animale *arrayAnimals = leggiAnimali("animali.txt", &dimAnimali);

printf("Numero Animali = %d\n", dimAnimali);

Animale a;

printf("Scegli Animale = ");
scanf("%s", a.codice);

stampaAnimale(a);

int dimRazze;
Razza *arrayRazze = leggiRazze ("razze.txt", &dimRazze);

printf("Numero di razze = %d\n", dimRazze);

Razza r;

printf("Scegli Razza = ");
scanf("%s", r.razza);

stampaRazza(r);

//PARTE 2 
printf("---PARTE 2---\n");

float litri = calcolaLitri(arrayAnimals[6], arrayRazze, dimRazze);
printf("Quantita Litri = %.3f\n", litri);

//PARTE 3
printf("---PARTE 3---\n");

float latteSTD = 0.1;
float latteHQ = 0.15;

float ricavi = calcolaRicavo(arrayAnimals, dimAnimali, arrayRazze, dimRazze, latteSTD, latteHQ);

printf("Ricavi Giornalieri = %f\n", ricavi);

//PARTE 4
printf("---PARTE 4---\n");

ordina(arrayRazze, dimRazze);

for (int i = 0; i < dimRazze; i++){
    printf("Peso = %d - Razza = %s\n", arrayRazze[i].peso, arrayRazze[i].razza);
}


free(arrayAnimals);
free(arrayRazze);

}