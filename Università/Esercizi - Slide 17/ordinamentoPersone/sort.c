#include "sort.h"

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int naive_sort(int v[], int n) {
    /* preparo un contatore per i confronti */
    int cnt = 0;
    /* Scorro l'intero array */
    int i, j, minidx;
    for(i = 0; i < n-1; ++i) {
        /* Determino il più piccolo degli elementi */
        minidx = i;
        for(j = i+1; j < n; ++j) {
            if(v[minidx] > v[j])
                minidx = j;
            /* un confronto in più */
            cnt++;
        }
        /* Scambio con l'elemento corrente */
        swap(&v[i], &v[minidx]);
	//int t;
	//t=v[i];
	//v[i]=v[minidx];
	//v[minidx]=t;
    }
    /* restituisco il numero di confronti */
    return cnt;
}


int bubble_sort(int v[], int n) {
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
            if(v[j] > v[j+1]) {
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


int insertion_sort(int v[], int n) {
    /* Considero tutte le posizioni dell'array */
    int i, j;
    int cnt = 0;
    for(i = 1; i < n; ++i) {
        /* Inserisco l'elemento attualmente in posizione
         * i-ma nella sua posizione corretta nella metà 
         * sx dell'array */
        for(j = i; j > 0; --j) {
            /* in ogni caso, facciamo un confronto in più */
            cnt++;
            /* se l'ordine è invertito, scambio */
            if(v[j-1] > v[j])
                swap(&v[j-1], &v[j]);
            /* altrimenti interrompo il processo */
            else
                break;
        }
    }
    /* restituisco il numero di confronti */
    return cnt;
}


/* Parametri:
 * - s1: inizio della prima sequenza
 * - s2: fine della prima sequenza ed inizio della seconda
 * - e2: fine della seconda sequenza */
int merge_sequences(int v[], int s1, int s2, int end) {
    int i;
    /* contatore dei confronti */
    int cnt = 0;
    /* proseguo finché almeno una delle sequenze non è esaurita  */
    while(s1 < s2 && s2 < end) {
        /* confronto i due elementi */
        cnt++;
        if(v[s1] < v[s2]) {
            /* in questo caso il primo elemento è già a posto */
            /* Adesso:
             * 1) La prima sequenza inizia una posizione più avanti
             * 2) La seconda sequenza è inalterata */
            s1++;
        }
        else {
            /* in questo caso l'elemento in s2 va messo in posizione
             * s1. Per farlo:
             * 1) Salvo il valore attualmente in v[s2] */
            int val = v[s2];
            /* 2) Faccio spazio in posizione s1 spostando tutta la
             *    prima sequenza in avanti */
            for(i = s2; i > s1; --i)
                v[i] = v[i-1];
            /* Ora posso inserire il valore salvato in posizione s1 */
            v[s1] = val;
            /* Adesso:
             * 1) La prima sequenza inizia una posizione più avanti
             * 2) ...e così anche la seconda sequenza */
            s1++;
            s2++;
        }
    }
    /* restituisco il numero di confroni effettuati */
    return cnt;
}

int merge_sort(int v[], int n) {
    /* contatore dei confronti */
    int cnt = 0;
    /* un vettore con un singolo elemento è sempre ordinato */
    if(n <= 1) return 0;
    /* altrimenti divido il vettore e riapplico l'algoritmo;
     * sfrutto il fatto che in C un array sia rappresentato
     * mediante un puntatore alla sua prima cella. Questo mi
     * permette di passare &v[mid], i.e. l'indirizzo della
     * cella in  mezzo */
    int mid = n/2;
    cnt += merge_sort(v, mid);
    cnt+= merge_sort(&v[mid], n-mid);
    /* fondo i risultati */
    cnt+= merge_sequences(v, 0, mid, n);
    /* restituisco il numero di confronti */
    return cnt;
}


int quick_sort(int v[], int n)  {
    /* contatore dei confronti */
    int cnt = 0;
    /* se l'array contiene 0 o 1 elementi, è già ordinato */
    if(n <= 1) return cnt;
    /* valore pivot */
    int pivot = v[n/2];
    /* Partiziono l'array in una sequenza "bassa" (i.e. < pivot) ed
     * "alta", i.e. > pivot.
     * Per farlo inizio dagli estremi e procedo verso il mezzo,
     * fino a trovare due elementi che si trovano entrambi nella
     * sequenza sbagliata: a questo punto gli elementi vengono
     * scambiati e si ripete il processo finché gli indici non si
     * incontrano */
    int s = 0, e = n-1;
    while(s < e) {
        /* sposto "s" in avanti finché non trovo un elemento
         * nella partizione sbagliata */
        while(v[s] < pivot) {
            s++;
            cnt++;
        }
        /* sposto "e" in indietro finché non trovo un elemento
         * nella partizione sbagliata */
        while(v[e] > pivot) {
            e--;
            cnt++;
        }
        /* Se i due indici non coincidono, uno scambio è necessario */
        if(s < e) {
            swap(&v[s], &v[e]);
            /* i due elementi sono a posto, quindi aggiorno s e e */
            s++;
            e--;
        }
    }
    /* "a" questo punto, "s" indica l'inizio della seconda sequenza e
     * la fine della prima sequenza. Posso invocare l'algoritmo sulle
     * due metà. */
    cnt += quick_sort(v, s);
    cnt += quick_sort(&v[s], n-s);
    /* restituisco il numero dei confronti */
    return cnt;
}
