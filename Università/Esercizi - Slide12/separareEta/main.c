#include<stdio.h>
#include<string.h>

#define MAX_CHAR 255
#define N 4
#define SOGLIA_ETA 40

typedef struct {
    char nome [MAX_CHAR];
    int eta;
}Persona;

void leggi_persona(Persona *p){
    printf("Inserisci Nome ed Eta =>");
    scanf("%s %d", &p->nome, &p->eta);
}

void stampa_persone(Persona *lista, int n){
    for (int j = 0; j < n; j++){
        printf("Nome %s - Eta %d\n", lista[j].nome, lista[j].eta);
    }
}

int separa_per_eta(Persona *out, Persona *lista, int n, int soglia_eta){

    int count = 0;
    int t=0;

    for (int i = 0; i < n; i++){
        if(lista[i].eta <= soglia_eta){
            out[t]=lista[i];
            t++;
            count ++;
        }
    }
    return count;
}

int main(){
// PARTE 1
printf("---PARTE 1---\n");

Persona arrayPersone[N];

for (int i = 0; i < N; i++){
    Persona p[i];
    leggi_persona(&p[i]);
    arrayPersone[i] = p[i];
}

stampa_persone(arrayPersone, N);

// PARTE 2;
printf("---PARTE 2---\n");

Persona arrayOut[N];

int res = separa_per_eta(arrayOut, arrayPersone,N,SOGLIA_ETA);

printf("dimensione logica out -> %d\n", res);

stampa_persone(arrayOut, res);

}




