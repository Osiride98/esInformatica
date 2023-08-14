#include "durate.h"
#include "durate.c"

#define N 5

int main(){

// PARTE 1
printf("---PARTE 1---\n");

durata arrayDurate[N];
int n = N;
int *dimArray = &n;


char nome_file[] = "nome_file.txt";

leggi_durate(nome_file, arrayDurate, dimArray);

// for (int i = 0; i < N; i++){
//     printf("Durata %d - hh %d : mm %d\n", i+1, arrayDurate[i].ore, arrayDurate[i].minuti);
// }

// PARTE 2 
printf("---Parte 2---\n");

stampa_durate(nome_file, arrayDurate, N);

}