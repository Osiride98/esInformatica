#include "persone.h"

persona leggi_persona() {
    persona p;
    printf("Indicare Cognome e Nome -> ");
    scanf("%s %s", p.cognome, p.nome);
    return p;
}

void stampa_persona(persona *array, int n){
    printf("Lista Persone:\n");
    for (int i = 0; i < n; i++){
        printf("Pos[%d] %s %s\n", i+1, array[i].cognome, array[i].nome);
    }
}

void swap(persona *a, persona *b) {
    persona temp = *a;
    *a = *b;
    *b = temp;
}

int bubble_sort(persona v[], int n) {
    int i, j;
    int cnt = 0;
    int ordinato;
    for (i = n; i > 1; --i) {
        ordinato = 1;
        for (j = 0; j < i - 1; ++j) {
            if (strcmp(v[j].cognome, v[j + 1].cognome) > 0) {
                swap(&v[j], &v[j + 1]);
                ordinato = 0;
            }
            if (strcmp(v[j].cognome, v[j + 1].cognome) == 0){
                if (strcmp(v[j].nome, v[j + 1].nome) > 0){    
                    swap(&v[j], &v[j + 1]);
                    ordinato = 0;
                }
            }
            cnt++;
        }
        if (ordinato) break;
    }
    return cnt;
}
