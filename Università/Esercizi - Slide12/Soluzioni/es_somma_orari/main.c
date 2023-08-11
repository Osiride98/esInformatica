#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct {int hh, mm;} orario;

orario leggi_orario() {
    // Preparo una struttura per il risultato
    orario res;
    // Leggo minuti ed ore
    printf("Inserire un orario (hh:mm): ");
    if(scanf("%d:%d", &res.hh, &res.mm) != 2) {
        printf("Errore nella lettura dell'orario\n");
        exit(1);
    }
    // Se la lettura ha successo, restituisco il risultato
    return res;
}

orario somma_orari(orario o1, orario o2) {
    // Calcolo la somma dei minuti
    int smm = o1.mm + o2.mm;
    // Calcolo il riporto
    int rhh = smm / 60; // divisione
    // Preparo una struttura per il risultato
    orario res;
    res.mm = smm % 60;
    res.hh = (o1.hh + o2.hh + rhh) % 24;
    // Restituisco il risultato
    return res;
}


int main() {
    // Preparo un accumulatore (un orario!)
    orario s;
    s.hh = 0;
    s.mm = 0;
    // Considero gli argomenti ad uno ad uno
    orario t;
    for(int i = 0; i < N; ++i) {
        // Provo a tradurre la stringa in un orario
        t = leggi_orario();
        // Sommo l'orario
        s = somma_orari(s, t);
    }
    // Stampo il risultato
    printf("Somma = %02d:%02d\n", s.hh, s.mm);   
}
