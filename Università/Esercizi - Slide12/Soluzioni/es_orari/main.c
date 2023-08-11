#include <stdio.h>

#define N 5

typedef struct {int hh, mm; } orario;

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

int main() {
    // PARTE 1: lettura di un singolo orario
    orario o;
    printf("PARTE 1 ====\n");
    leggi_orario(&o);
    stampa_orario(o);

    // PARTE 2: lettura di un secondo orario e confronto
    orario o2;
    printf("PARTE 2 ====\n");
    leggi_orario(&o2);
    int cmp = confronto_orario(o, o2);
    printf("Risultato del confronto: %d\n", cmp);

    // PARTE 3: inserimento manuale in array
    orario l[N];
    int n = 2; // in ogni caso inseriremo due orari
    printf("PARTE 3 ====\n");
    if (cmp <= 0) {
        l[0] = o;
        l[1] = o2;
    }
    else {
        l[0] = o2;
        l[1] = o;
    }
    stampa_orari(l, n);

    // PARTE 4: Inserisco 3 orari
    printf("PARTE 4 ====\n");
    orario t;
    for(int i = 0; i < 3; ++i) {
        leggi_orario(&t);
        inserisci_orario(l, &n, t);
    }
    stampa_orari(l, n);
}
