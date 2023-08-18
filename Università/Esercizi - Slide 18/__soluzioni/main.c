#include <stdio.h>
#include "radio.h"

#define MAX_CANZONI 40
#define MAX_RICHIESTE 30

int main() {
    /* preparo le strutture dati */
    Canzone playlist[MAX_CANZONI];
    Richiesta richieste[MAX_RICHIESTE];
    int i;

    /* leggo i dati dal file delle canzoni */
    int nc = leggiCanzoni("canzoni.txt", playlist);
    
    /* stampo la lista delle canzoni */
    printf("CANZONI ====\n");
    for(i = 0; i < nc; ++i)
        stampaCanzone(playlist[i]);

    /* leggo i dati dal file delle richieste */
    int nr = leggiRichieste("richieste.txt", richieste);
    
    /* stampo la lista delle richieste */
    printf("\n");
    printf("RICHIESTE ====\n");
    for(i = 0; i < nr; ++i)
        stampaRichiesta(richieste[i]);

    /* verifico le richiste di alcuni ascoltatori */
    char ascoltatore1[] = "AnnaGiubilei";
    printf("\n");
    if (richAscoltatore(playlist, nc, richieste, nr, ascoltatore1)) {
        printf("Le richieste di %s sono ok\n", ascoltatore1);
    }
    else {
        printf("Le richieste di %s NON sono ok\n", ascoltatore1);
    }
    
    char ascoltatore2[] = "TeresaLolli";
    printf("\n");
    if (richAscoltatore(playlist, nc, richieste, nr, ascoltatore2)) {
        printf("Le richieste di %s sono ok\n", ascoltatore2);
    }
    else {
        printf("Le richieste di %s NON sono ok\n", ascoltatore2);
    }

    /* ordino le richieste */
    ordina(playlist, nc);

    printf("\n");
    printf("CANZONI ORDINATE ====\n");
    for(i = 0; i < nc; ++i)
        stampaCanzone(playlist[i]);

    /* apro il file delle richieste in append */
    char nomefile[] = "richieste.txt";
    FILE *fp = fopen(nomefile, "a");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s in append\n", nomefile);
        exit(1);
    }

    /* inserisco una nuova richiesta */
    printf("\n");
    int ok = inserisciRichiesta(fp, playlist, nc, richieste, &nr);
    if(ok) printf("Richiesta inserita con successo\n");
    else printf("Richiesta non inserita\n");

    /* chiudo il file */
    fclose(fp);
}
