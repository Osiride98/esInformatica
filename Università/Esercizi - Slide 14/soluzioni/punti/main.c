#include "punti.h"
#include "segmenti.h"

#define N 4

int main() {
    punto punti[N];

    // Leggo un array di punti
    printf("PARTE 1 ====\n");
    for(int i = 0; i < N; ++i) {
        leggi_punto(&punti[i]);
    }
    printf("\nPUNTI:\n");
    for(int i = 0; i < N; ++i) {
        stampa_punto(&punti[i]);
    }
    printf("\n");

    // Creao un segmento tra i primi due punti e calcolo la distanza
    segmento s = crea_segmento(&punti[0], &punti[1]);
    stampa_con_lunghezza(&s);
    printf("\n");

    // Genero tutti i segmenti e calcolo tutte le distanze 
    segmento segmenti[N*(N-1)/2];
    crea_segmenti(segmenti, punti, N);

    printf("Distanze:\n");
    for(int i = 0; i < N*(N-1)/2; ++i) {
        stampa_con_lunghezza(&segmenti[i]);
    }
}
