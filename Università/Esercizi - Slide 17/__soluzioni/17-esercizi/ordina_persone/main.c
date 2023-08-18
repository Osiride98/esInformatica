#include "persone.h"

#define N 4

int main() {
    Persona p[N];
    int i;

    /* Leggo le informazioni su N persone */
    for(i = 0; i < N; ++i) {
        p[i] = leggi_persona();
    }

    /* ordino */
    ordina_persone(p, N);

    /* Stampo l'arry ordinato */
    printf("=== PERSONE\n");
    for(i = 0; i < N; ++i) {
        stampa_persona(p[i]);
    }

    return 0;
}
