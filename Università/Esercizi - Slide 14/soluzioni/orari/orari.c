#include "orari.h"

void leggi_orario(orario *o) {
    printf("Inserire l'orario (hh:mm) ");
    scanf("%d:%d", &o->hh, &o->mm);
}

void stampa_orario(orario o) {
    printf("%d:%d\n", o.hh, o.mm);
}

int confronto_orario(orario o1, orario o2) {
    // Confronto le ore (basta una sottrazione)
    int cmp_hh = o1.hh - o2.hh;
    // Se la differenza è 0, le due ore sono uguali
    if (cmp_hh == 0) {
        // In questo caso confronto i minuti
        int cmp_mm = o1.mm - o2.mm;
        return cmp_mm;
    }
    return cmp_hh;
}

void stampa_orari(orario *l, int n) {
    printf("LISTA DEGLI ORARI:\n");
    for(int i = 0; i < n; ++i)
        stampa_orario(l[i]);
}

void inserisci_orario(orario *l, int *n, orario o) {
    // Libero spazio, finché non trovo la posizione corretta
    int i;
    for(i = *n; i > 0; --i) {
        // Controllo se questa sia la posizione di inserimento;
        // per farlo confronto l'orario da inserire con quello in
        // posizione (i-1)-ma. Se l'orario in posizione (i-1)-ma è
        // _successivo_ a quello da inserire, allora libero spazio
        if (confronto_orario(l[i-1], o) > 0) {
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

