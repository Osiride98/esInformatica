#include "durate.h"

void leggi_durate(char *nome_file, Durata *l, int *n) {
    FILE *fp;
    /* Apro il file */
    if((fp = fopen(nome_file, "r")) == NULL) {
        fprintf(stderr, "Impossibile aprire \"%s\"\n", nome_file);
        exit(2);
    }
    /* leggo le durate */
    Durata t;
    while(fscanf(fp, "%d%d", &t.hh, &t.mm) == 2) {
        l[*n] = t;
        ++(*n);
    }
    /* Chiudo il file */
    fclose(fp);
}


void stampa_durate(char *nome_file, Durata *l, int n) {
    int i;
    FILE *fp;
    /* Apro il file */
    if((fp = fopen(nome_file, "w")) == NULL) {
        fprintf(stderr, "Impossibile aprire \"%s\"\n", nome_file);
        exit(2);
    }
    /* Scrivo i dati */
    for(i = 0; i < n; ++i) {
        fprintf(fp, "%d %d\n", l[i].hh,  l[i].mm);
    }
    /* Chiudo il file */
    fclose(fp);
}

