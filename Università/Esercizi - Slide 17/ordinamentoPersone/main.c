#include "persone.h"
#include "persone.c"

#define N 10

int main (){
//PARTE 1
printf("---PARTE 1---\n");

persona arrayPersone[N];

for(int i = 0; i < N; i++){
    arrayPersone[i] = leggi_persona();
}

stampa_persona(arrayPersone, N);

//PARTE 2
printf("---PARTE 1 ---\n");

int confronti = bubble_sort(arrayPersone, N);

stampa_persona(arrayPersone, N);

printf("Numero Confronti -> %d", confronti);

}