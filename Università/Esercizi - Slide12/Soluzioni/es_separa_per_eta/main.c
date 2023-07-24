#include <stdio.h>

#define N_NOME 256
#define N 4

typedef struct {
    char nome[N_NOME];
    int eta;
} Persona;


Persona leggi_persona() {
    Persona res;
    printf("Nome: ");
    scanf("%s", res.nome);
    printf("Età: ");
    scanf("%d", &res.eta);
    return res;
}

void stampa_persone(Persona *lista, int n) {
    int i;
    for(i = 0; i < n; ++i) {
        printf("%s %d\n", lista[i].nome, lista[i].eta);
    }
}

int separa_per_eta(Persona *out, Persona *lista, int n, int soglia_eta) {
    int k = 0, i;
    for(i = 0; i < n; ++i) {
        if(lista[i].eta <= soglia_eta) {
            out[k++] = lista[i];
        }
    }
    return k;
}

int main() {
    Persona lista[N], giovani[N];
    int n, i;

    for(i = 0; i < N; ++i) {
        printf("=== Persona %d\n", i);
        lista[i] = leggi_persona();
    }
    printf("=== Persone\n");

    n = separa_per_eta(giovani, lista, N, 30);

    printf("\n=== Lista giovani\n");
    stampa_persone(giovani, n);

    return 0;
}

