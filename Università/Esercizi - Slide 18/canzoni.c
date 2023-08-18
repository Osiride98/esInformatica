#include "canzoni.h"

int leggiCanzoni (char* nomefile, canzone playlist[]){
    int i = 0;
    FILE *fp;

    char genereRead[2];
    canzone c;

    if((fp = fopen("canzoni.txt", "r")) == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nomefile);
        exit(1);
        }else{
            printf("Sono in lettura\n");
        }

    while (fscanf(fp,"%s%s%s%s%d%d%d", c.codice, c.titolo, c.artista, genereRead,
                                        &c.annoUscita, &c.minDurata, &c.secDurata) == 7){
        c.genere = genereRead[0];
        playlist[i] = c;
        i++;
    }
    return i;
}

void stampaCanzone(canzone c){
    printf("Hai scelto '%s' scritta da %s\n", c.titolo, c.artista);
    printf("Anno di Uscita %d, Genere %c\n", c.annoUscita, c.genere);
}

int leggiRichieste (char* nomefile, richiesta richieste[]){
    int j = 0;
    richiesta r;
    FILE *fp;

    if((fp = fopen("richieste.txt", "r")) == NULL) {
    fprintf(stderr, "Impossibile aprire %s\n", nomefile);
    exit(1);
    }else{
        printf("Sono in lettura\n");
    }
    while (fscanf(fp,"%s%s%s",r.nome_ascoltatore, r.titolo, r.dedica) == 3){
        richieste[j] = r;
        j++;
        if (j == 29){
            break;
        }
        
    }
    return j;
}

void stampaRichiesta (richiesta r){
    printf("Ascoltatore '%s'\n", r.nome_ascoltatore);
    printf("Canzone '%s' - Dedidica '%s'\n", r.titolo, r.dedica);

}

tempo sommaTempo(tempo t1, tempo t2){
    tempo tempoTot;
    
    tempoTot.minuti = t1.minuti + t2.minuti;

    if (t1.secondi + t2.secondi > 59){
        tempoTot.minuti = tempoTot.minuti + 1;

        if (t1.secondi + t2.secondi == 60){
            tempoTot.secondi = 0;
        }else if (t1.secondi >= t2.secondi ){
            tempoTot.secondi = t1.secondi - t2.secondi;
        }else{
            tempoTot.secondi = t2.secondi - t1.secondi;
        }
         
    }else{
        tempoTot.secondi = t1.secondi + t2.secondi;
    }

    return tempoTot;

}

int richAscoltatore(canzone c[], int dimC, richiesta r[], int dimR, char * ascoltatore){
    int ascRequ = 0;
    int songRequ = 0;
    int songType = 0;
    int resCondizioni = 0;
    tempo sommaCanzoni, temp;

    sommaCanzoni.minuti = 0;
    sommaCanzoni.secondi = 0;

    //condizione 1 - presenza canzoni
    //condizione 2 - somma canzoni max 15 min
    //condizione 3 - somma canzoni jazz e rock <= 5

    for (int i = 0; i <= dimR; i++){
        if (strcmp(r[i].nome_ascoltatore,ascoltatore) == 0){
            ascRequ++;
            for (int j = 0; j <= dimC; j++){
                if(strcmp(r[i].titolo, c[j].titolo) == 0){
                    songRequ++;
                    temp.minuti = c[j].minDurata;
                    temp.secondi = c[j].secDurata;
                    sommaCanzoni = sommaTempo(sommaCanzoni, temp);
                    if (c[j].genere == 'J' || c[j].genere == 'R'){
                        songType++;
                    }
                    
                }
            }
        }
    }
    if (songRequ == ascRequ && sommaCanzoni.minuti <= 15 && songType <= 5){
        resCondizioni = 1;
    }else{
        resCondizioni = 0; 
    }
    return resCondizioni;
}

void swap(canzone *a, canzone *b){
    canzone t = *a;
    *a = *b;
    *b = t;
}

int bubble_sort(canzone v[], int n){
    /* Effettuo varie "passate" */
    int i, j;
    int cnt = 0;
    int ordinato;
    for(i = n; i > 1; --i) {    
        /* all'inizio ipotizzo che l'array sia ordinato */
        ordinato = 1;
        /* Ad ogni "passata" considero le coppie adiacenti */
        for(j = 0; j < i-1; ++j) {
            /* se l'ordine è invertito, scambio */
            if(v[j].annoUscita > v[j+1].annoUscita) {
                swap(&v[j], &v[j+1]);
                ordinato = 0;
            }
            /* un confronto in più */
            cnt++;
        }
        /* se l'array era veramente ordinato, posso interrompere */
        if(ordinato) break;
    }
    /* restituisco il numero di confronti */
    return cnt;
}

void ordina (canzone playlist[], int dimC){
    int cambi = bubble_sort(playlist, dimC);
}