#include "orari.h"


// nel file .c inserisco la definizione delle mie funzioni includendo il file header

void leggi_orario(orario *o1){           // in questa funzione utilizzo "*o" puntatore perchè con lo scanf devo andare a scrivere all'interno della cella di memoria negli indirizzi
    printf("Indicare Ora hh =>");
    scanf("%d", &o1->ore);

    printf("Indicare minuti mm =>");
    scanf("%d", &o1->minuti);
}

void stampa_orario(orario o1) {
    printf("%d:%d\n", o1.ore, o1.minuti);
}

void stampa_orari(orario *l, int n) {
    printf("LISTA DEGLI ORARI:\n");
    for(int i = 0; i < n; ++i)
        stampa_orario(l[i]);
}

int confronta_orario(orario o1, orario o2){
    int res = 0;

    if(o1.ore == o2.ore && o1.minuti == o2.minuti){             // nelle condizione degli if devo andare a leggere all'interno delle celle di memoria !!
        //printf("sono gli stessi orari\n");
            return res;

            }else if(o1.ore == o2.ore && o1.minuti<o2.minuti || o1.ore < o2.ore){
                //printf("o1 precede o2\n");
                res = -1;
                return res;

                    }else if(o1.ore == o2.ore && o1.minuti > o2.minuti || o1.ore > o2.ore){
                        //printf("o2 precede o1\n");
                        res = 1;
                        return res;
                        }

}

void inserisci_orario(orario *l, int *n, orario o) {
    // Libero spazio, finché non trovo la posizione corretta
    int i;
    for(i = *n; i > 0; --i) {
        // Controllo se questa sia la posizione di inserimento;
        // per farlo confronto l'orario da inserire con quello in
        // posizione (i-1)-ma. Se l'orario in posizione (i-1)-ma è
        // _successivo_ a quello da inserire, allora libero spazio
        if (confronta_orario(l[i-1], o) > 0) {
            // In questo caso, sposto l'elemento in avanti
            l[i] = l[i-1];
        }
        else  {
            // Altrimenti, interrompo il ciclo
            break;
        }
    }
    // A questo punto, i è l'indice della posizione in cui inserire
    l[i] = o;
    // Aggiorno il numero di elementi
    *n += 1;
}
