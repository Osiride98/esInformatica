#include "persona.h" // nelle librerie "personali" negli include si indicano tra apici
#include<stdio.h>   //includo la libreria in cui ho scritto la definizione di "persona"

//definisco la funzione leggi_persona che andrà a salvare il valore in input da me inserito nella cella di memoria allocata
// avente indirizzo &p-> *...*

void leggi_persona(persona *p){

    printf("inserisci nome ");
    scanf("%s", &p->nome);

    printf("Inserisci cognome ");
    scanf("%s", &p->cognome);

    printf("Inserisci eta ");
    scanf("%d", &p->eta);

    printf("Inserisci sesso ");
    scanf("%s", &p->sesso);

}

//definisco stampa_persona indicado nel print gli indirizzi delle celle di memoria (p.*...*)

void stampa_persona(persona p){
    printf("Nome = %s\n", p.nome);
    printf("Cognome = %s\n", p.cognome);
    printf("Eta = %d\n", p.eta);
    printf("sesso = %s\n", p.sesso);
}

//funzione int che mi restituisce il valore dell'età

int eta_persona(int eta){
    return eta;
}