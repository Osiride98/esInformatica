#include "radio.h"

int leggiCanzoni(char* nomefile, Canzone playlist[]) {
    /* apro il file */
    FILE *fp = fopen(nomefile, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nomefile);
        exit(1);
    }

    /* leggo i dati sulle canzoni */
    char genere[2];
    Canzone t; //struttura dati di appoggio
    int i = 0;
    while(fscanf(fp, "%s%s%s%s%d%d%d", t.codice,
                                       t.titolo,
                                       t.artista,
                                       genere,
                                       &t.anno,
                                       &t.minuti,
                                       &t.secondi) == 7) {
        /* recupero il primo carattere della stringa "genere" */
        t.genere = genere[0];
        /* copio i dati */
        playlist[i++]  = t;
    }

    /* chiudo il file */
    fclose(fp);

    /* restituisco la dimensione logica */
    return i;
}

void stampaCanzone(Canzone c) {
    printf("%s %s %s %c %d %d %d\n", c.codice,
                                     c.titolo,
                                     c.artista,
                                     c.genere,
                                     c.anno,
                                     c.minuti,
                                     c.secondi);
}


int leggiRichieste(char* nomefile, Richiesta richieste[]) {
    /* apro il file */
    FILE *fp = fopen(nomefile, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nomefile);
        exit(1);
    }

    /* leggo i dati sulle richieste */
    Richiesta t; //struttura di approggio
    int i = 0;
    while(fscanf(fp, "%s%s%s", t.nome_ascoltatore,
                               t.titolo,
                               t.dedica) == 3) {
        /* copio i dati */
        richieste[i++]  = t;
    }

    /* chiudo il file */
    fclose(fp);

    /* restituisco la dimensione logica */
    return i;
}

void stampaRichiesta(Richiesta r) {
    printf("%s %s %s\n", r.nome_ascoltatore,
                       r.titolo,
                       r.dedica);
}


int trovaCanzone(Canzone c[], int dimC, char *titolo) {
    int i;
    /* cerco la richiesta */
    for(i = 0; i < dimC; ++i) {
        if(strcmp(c[i].titolo, titolo) == 0)
            return i; //indice della canzone richiesta nella playlist
    }
    return -1;
}

int richAscoltatore(Canzone c[], int dimC,
                    Richiesta r[], int dimR,
                    char *ascoltatore) {
    int i, j;
    int tot_sec = 0;
    int tot_jr = 0;
    /* considero tutte le richieste */
    for(i = 0; i < dimR; ++i) {
        /* verifico se l'ascoltatore corrisponda */
        if(strcmp(ascoltatore, r[i].nome_ascoltatore) == 0) {
            /* verifico se la canzone sia presente */
            j = trovaCanzone(c, dimC, r[i].titolo);
            /* se non è presente, restituisco 0 */
            if (j < 0)
                return 0;
            /* altrimenti, aggiorno il tempo totale */
            tot_sec += 60*c[j].minuti + c[j].secondi;
            /* se il tempo è eccessivo, restituisco 0 */
            if(tot_sec > 15*60)
                return 0;
            /* aggiorno il tempo delle canzoni Jazz e Rock */
            if(c[j].genere == 'J' || c[j].genere == 'R') {
                tot_jr++;
                if (tot_jr > 5)
                    return 0;
            }
        }
    }
    /* se siamo arrivati qui, tutte le richieste sono ok */
    return 1;
}

void ordina(Canzone playlist[], int dimC) {
    /* uso insertion sort */
    int i, j;
    Canzone t; //variabile temporanea per lo scambio
    for(i = 1; i < dimC; ++i) {
        /* se necessario, scorro verso sx */
        for(j = i; (playlist[j-1].anno > playlist[j].anno) && j>0; --j) {
            /* fintanto che l'ordine è invertito, scambio */
            t = playlist[j-1];
            playlist[j-1] = playlist[j];
            playlist[j] = t;
        }
	//oppure
	//	for(j = i; j>0; --j) {
	//             /* fintanto che l'ordine è invertito, scambio */
	//             if(playlist[j-1].anno > playlist[j].anno) {
	//			t = playlist[j-1];
	//             		playlist[j-1] = playlist[j];
	//             		playlist[j] = t;
	//	       }
	//	       else break;
	//      }	
    }
}

int inserisciRichiesta(FILE *fp,
                       Canzone c[], int dimC,
                       Richiesta r[], int *dimR) {
    Richiesta rc;
    /* leggo i dati di una nuova richiesta */
    printf("Inserimento di una nuova richiesta\n");
    printf("nome ascoltatore: ");
    scanf("%s", rc.nome_ascoltatore);
    printf("titolo: ");
    scanf("%s", rc.titolo);
    printf("dedica: ");
    scanf("%s", rc.dedica);

    /* innanzitutto verifico che la canzone sia presente */
    int ok = trovaCanzone(c, dimC, rc.titolo);
    if(ok < 0) {
        /* se non è presente, restituisco 0 */
        return 0;
    }

    /* inizio inserendo la richiesta nel vettore */
    r[*dimR] = rc;
    (*dimR)++;	
    /* a questo punto, posso usare la funzione richAscoltatore */
    if(richAscoltatore(c, dimC, r, *dimR, rc.nome_ascoltatore)) {
        /* se la richiesta era soddisfacibile, scrivo nel file */
        fprintf(fp, "%s %s %s\n", rc.nome_ascoltatore,
                                  rc.titolo,
                                  rc.dedica);
        /* restituisco 1 */
        return 1;
    }
    else {
        /* se la richiesta non era inseribile, restituisco 0 */
        return 0;
    }
}
