#include "function.h"


double sommaSpese(int codice, ComE *e, int dimE) {
    int i;
    /* tengo traccia del totale delle spese nette e del numero
     * di comunicazioni */
    double res = 0;
    int n = 0;
    /* considero tutte le spese */
    for(i = 0; i < dimE; ++i) {
        /* considero solo quelle del condominio specificato */
        if(e[i].codice == codice) {
            /* una comunicazione in più */
            n++;
            /* determino il tipo di tassazione e lo applico */
            if(e[i].valore < 5000) {
                res += 0.9 * e[i].valore;
            }
            else {
                res += 0.88 * e[i].valore;
            }
        }
    }
    /* stampo la media */
    printf("Media delle spese nette: %.3f\n", res / n);
    /* restituisco la somma */
    return res;
}

void insert(char *fileName, char type) {
    /* chiedo i dati su una comunicazione */
    ComA ta;
    ComE te;
    int ok = 1;
    int i;
    if(type == 'A') {
        /* chiedo i dati della nuova comunicazione */
        printf("Inserimento di una comunicazione di tipo A\n");
        printf("Inserire il codice del condominio: ");
        scanf("%d", &ta.codice);
        printf("Inserire il messaggio: ");
        /* consumo caratteri fino al fine linea */
        while(getchar() != '\n');
        scanf("%[^\n]", ta.msg);
    }
    else if(type == 'E') {
        /* chiedo i dati della nuova comunicazione */
        printf("Inserimento di una comunicazione di tipo E\n");
        printf("Inserire il codice del condominio: ");
        scanf("%d", &te.codice);
        printf("Inserire il valore: ");
        scanf("%d", &te.valore);
        printf("Inserire la descrizione: ");
        scanf("%s", te.desc);
        printf("Inserire la data (gg/mm/aa): ");
        scanf("%d/%d/%d", &te.giorno, &te.mese, &te.anno);

        /* leggo le comunicazioni nel file */
        int ne;
        ComE *e = readComE(fileName, &ne);

        /* verifico che non vi sia una comunicazione simile */
        for(i = 0; i < ne; ++i) {
            if(e[i].anno == te.anno &&
               e[i].mese == te.mese &&
               e[i].giorno == te.giorno &&
               strcmp(e[i].desc, te.desc) == 0) {
                /* in questo caso esiste una comunicazione simile */
                printf("Esiste già una comunicazione E simile\n");
                ok = 0;
                break;
            }
        }

        /* dealloco */
        free(e);
    }
    else {
        /* stampo un messaggio di errore */
        printf("Tipo di comunicazione non valido: %c\n", type);
        /* indico che non ci sono da fare inserimenti */
        ok = 0;
    }

    if(ok) {
        /* apro il file */
        FILE *fp = fopen(fileName, "a");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire il file %s\n", fileName);
            exit(1);
        }
        /* inserisco la nuova comunicazione */
        if(type == 'A') {
            fprintf(fp, "A %d %s\n", ta.codice, ta.msg);
        }
        else {
            fprintf(fp, "E %d %d %s %d %d %d\n", te.codice, te.valore, te.desc,
                                            te.anno, te.mese, te.giorno);
        }
        /* chiudo il file */
        fclose(fp);
    }
}
