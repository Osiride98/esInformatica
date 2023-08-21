#include "manager.h"

#define BIGBUFFER 1024

Condominio * readcondomini(char *fileName, int *dim) {
    /* apro il file */
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", fileName);
        exit(1);
    }
    /* conto gli elementi */
    Condominio t;
    *dim = 0;
    while(fscanf(fp, "%d%d%s%d", &t.codice, &t.cap, t.via, &t.civico) == 4)
        (*dim)++;
    /* alloco un vettore */
    Condominio *v = (Condominio*) malloc((*dim) * sizeof(Condominio));
    /* riavvolgo */
    rewind(fp);
    /* riempio il vettore */
    int i = 0;
    while(fscanf(fp, "%d%d%s%d", &t.codice, &t.cap, t.via, &t.civico) == 4)
        v[i++] = t;
    /* chiudo il file */
    fclose(fp);
    /* restituisco il vettore */
    return v;
}

void stampa_condominio(Condominio c) {
    printf("%d %d %s %d\n", c.codice, c.cap, c.via, c.civico);
}

ComA * readComA(char *fileName, int *dim) {
    /* apro il file */
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", fileName);
        exit(1);
    }
    /* conto gli elementi (solo il tipo A!) */
    ComA t;
    char tipo[2];
    char buffer[BIGBUFFER];
    *dim = 0;
    while(fscanf(fp, "%s", tipo) == 1) {
        /* se la comunicazine è di tipo A, la devo contare */
        if(tipo[0] == 'A') {
            /* leggo i dati rimanenti */
            if(fscanf(fp, "%d%s", &t.codice, t.msg) == 2) {
                /* una comunicazione di tipo A in più */
                (*dim)++;
            }
        }
        /* se la comunicazione è di tipo diverso, leggo fino a fine riga */
        else {
            fscanf(fp, "%[^\n]", buffer);
        }
    }
    /* alloco un vettore */
    ComA *v = (ComA*) malloc((*dim) * sizeof(ComA));
    /* riavvolgo */
    rewind(fp);
    /* riempio il vettore */
    int i = 0;
    while(fscanf(fp, "%s", tipo) == 1) {
        /* se la comunicazine è di tipo A, la devo contare */
        if(tipo[0] == 'A') {
            /* leggo i dati rimanenti */
            if(fscanf(fp, "%d%s", &t.codice, t.msg) == 2) {
                /* inserisco la comunicazione nel vettore */
                v[i++] = t;
            }
        }
        /* se la comunicazione è di tipo diverso, leggo fino a fine riga */
        else {
            fscanf(fp, "%[^\n]", buffer);
        }
    }
    /* chiudo il file */
    fclose(fp);
    /* restituisco il vettore */
    return v;
}

void stampaComA(ComA c) {
    printf("A %d %s\n", c.codice, c.msg);
}

ComE * readComE(char *fileName, int *dim) {
    /* apro il file */
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", fileName);
        exit(1);
    }
    /* conto gli elementi (solo il tipo E!) */
    ComE t;
    char tipo[2];
    char buffer[BIGBUFFER];
    *dim = 0;
    while(fscanf(fp, "%s", tipo) == 1) {
        /* se la comunicazine è di tipo E, la devo contare */
        if(tipo[0] == 'E') {
            /* leggo i dati rimanenti */
            if(fscanf(fp, "%d%d%s%d%d%d", &t.codice, &t.valore, t.desc,
                                          &t.anno, &t.mese, &t.giorno) == 6) {
                /* una comunicazione di tipo E in più */
                (*dim)++;
            }
        }
        /* se la comunicazione è di tipo diverso, leggo fino a fine riga */
        else {
            fscanf(fp, "%[^\n]", buffer);
        }
    }
    /* alloco un vettore */
    ComE *v = (ComE*) malloc((*dim) * sizeof(ComE));
    /* riavvolgo */
    rewind(fp);
    /* riempio il vettore */
    int i = 0;
    while(fscanf(fp, "%s", tipo) == 1) {
        /* se la comunicazine è di tipo E, la devo contare */
        if(tipo[0] == 'E') {
            /* leggo i dati rimanenti */
            if(fscanf(fp, "%d%d%s%d%d%d", &t.codice, &t.valore, t.desc,
                                          &t.anno, &t.mese, &t.giorno) == 6) {
                /* inserisco la comunicazione nel vettore */
                v[i++] = t;
            }
        }
        /* se la comunicazione è di tipo diverso, leggo fino a fine riga */
        else {
            fscanf(fp, "%[^\n]", buffer);
        }
    }
    /* chiudo il file */
    fclose(fp);
    /* restituisco il vettore */
    return v;
}

void stampaComE(ComE c) {
    printf("E %d %d %s %d %d %d\n", c.codice, c.valore, c.desc,
                                    c.anno, c.mese, c.giorno);
}


void ordinaComE(ComE *e, int dimE) {
    int i, j;
    for(i = 1; i < dimE; ++i) {
        for(j = i; j > 0; --j) {
            /* controllo le i due elementi adicenti siano invertiti */
            if(372*e[j].anno + 31*e[j].mese + e[j].giorno <
               372*e[j-1].anno + 31*e[j-1].mese + e[j-1].giorno) {
                /* se sono invertiti, li scambio */
                ComE t = e[j-1];
                e[j-1] = e[j];
                e[j] = t;
            }
            else {
                /* altrimenti, l'elemento ha raggiunto la posizione corretta */
                break;
            }
        }
    }
}


ComE * stampaCondominio(Condominio *c, int dimC,
                ComA *a, int dimA, ComE *e, int dimE) {
    /* ordino le comunicazioni E */
    ordinaComE(e, dimE);

    /* chiedo all'utente un codice di condominio */
    int cod;
    printf("Inserire un codice di condominio: ");
    scanf("%d", &cod);

    /* stampo i dati generici del condominio */
    int i;
    for(i = 0; i < dimC; ++i) {
        if(c[i].codice == cod) {
            printf("Dati del condominio %d ---\n", cod);
            stampa_condominio(c[i]);
            break;
        }
    }
    /* posso controllare se il condominio sia stato trovato
     * controllando il valore dell'indice */
    if(i == dimC) {
        /* se non è stato trovato, lo segnalo e restituisco l'array
         * ordinato delle comunicazioni di tipo E */
        printf("Nessun condominio con codice %d\n", cod);
        return e;
    }

    /* stampo le comunicazioni */
    printf("Comunicazioni ---\n");
    for(i = 0; i < dimA; ++i) {
        if(a[i].codice == cod)
            stampaComA(a[i]);
    }
    for(i = 0; i < dimE; ++i) {
        if(e[i].codice == cod)
            stampaComE(e[i]);
    }

    /* restituisco l'elenco ordinato */
    return e;
}
