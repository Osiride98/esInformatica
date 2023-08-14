#include "colori.h"

void leggi_colori(char *nome_file,
                  ColoreCSS *lcss, int *ncss,
                  ColoreRGB *lrgb, int *nrgb) {
    FILE *fp;
    int tipo;
    /* Apro il file */
    if((fp = fopen(nome_file, "r")) == NULL) {
        fprintf(stderr, "Impossibile aprire \"%s\"\n", nome_file);
        exit(2);
    }
    /* leggo i colori, cominciando con il tipo */
    while(fscanf(fp, "%d", &tipo) == 1) {
        /* completo la lettura */
        if(tipo == 0) {
            ColoreCSS t;
            fscanf(fp, "%s", t.codice);
            lcss[*ncss] = t;
            ++(*ncss);
        }
        else {
            ColoreRGB t;
            fscanf(fp, "%d%d%d", &t.r, &t.g, &t.b);
            lrgb[*nrgb] = t;
            ++(*nrgb);
        }
    }
    /* Chiudo il file */
    fclose(fp);
}


void stampa_colori(ColoreCSS *lcss, int ncss,
                   ColoreRGB *lrgb, int nrgb) {
    int i;
    printf("Colori CSS:\n");
    for(i = 0; i < ncss; ++i) {
        printf("%s\n", lcss[i].codice);
    }
    printf("Colori RGB:\n");
    for(i = 0; i < ncss; ++i) {
        printf("rgb(%d,%d,%d)\n", lrgb[i].r, lrgb[i].g, lrgb[i].b);
    }
}
