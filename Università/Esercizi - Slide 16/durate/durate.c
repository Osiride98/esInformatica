#include "durate.h"

void leggi_durate(char *nome_file, durata *l, int *n){

    int i;
    FILE *fp;
    durata x;

    if((fp = fopen("nome_file.txt", "r")) == NULL) {
    fprintf(stderr, "Impossibile aprire %s\n", nome_file);
    exit(1);
    }else{
        printf("ci ste brev\n");
    }

    // leggo le durate nel file e le salvo nella i-esima parte dell'array

    i = 0;
    while(fscanf(fp, "%d %d", &x.ore, &x.minuti) == 2) {
    l[i++] = x;
    }
    fclose(fp);
}

void stampa_durate(char *nome_file, durata *l, int n){

    int i;
    for (int i = 0; i < n; i++){
    printf("Durata %d - hh %d : mm %d\n", i+1, l[i].ore, l[i].minuti);
}

}