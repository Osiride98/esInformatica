#include "persone.h"

Persona leggi_persona() {
    Persona res;
    printf("Nome e cognome: ");
    scanf("%s%s", res.nome, res.cognome);
    return res;
}

void stampa_persona(Persona p) {
    printf("%s %s\n", p.nome, p.cognome);
}

int cmppersona(Persona *p1, Persona *p2) {
    int r = strcmp(p1->cognome, p2->cognome);
    if(r != 0) return r;
    return strcmp(p1->nome, p2->nome);
}

void ordina_persone(Persona *p, int n) {
    /* Considero tutte le posizioni dell'array */
    int i, j;
    for(i = 1; i < n; ++i) {
        /* Inserisco l'elemento attualmente in posizione
         * i-ma nella sua posizione corretta nella metà 
         * sx dell'array */
        for(j = i; j > 0; --j) {
            /* se l'ordine è invertito, scambio */
            if(cmppersona(&p[j-1], &p[j]) > 0) {
                Persona t;
                t = p[j-1];
                p[j-1] = p[j];
                p[j] = t;
            }
            /* altrimenti interrompo il processo */
            else
                break;
        }
    }
}


