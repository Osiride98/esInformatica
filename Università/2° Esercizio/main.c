#include "persona.h" //includo il file con le "" 
#include<stdio.h>
#include "persona.c" //includo il file con le "" 
#include<stdlib.h>

int main(){

    int a=0;

    persona p1,p2;      // inizializzo due variabili p1,p2 che conterrano ciascuna le informazioni nome, cognome. eta e sesso

    leggi_persona(&p1); // richiamo la funzione leggi_persona (scritta nel file persona.c) scrivendo all'indirizzo di memoria di p1 (&p1)
    stampa_persona(p1); // richiamo la function stampa_persona (scritta nel file persona.c) stampo a schermo l'intero contento di p1 (non serve il puntatore) 

    a=eta_persona(p1.eta);
    printf("eta = %d\n", a);

    FILE* fp; // fp variabile di tipo file (puo essere aperto, letto, scritto, chiuso)
    char c, nome[]="persona.txt"; 
    if((fp=fopen(nome,"r"))==NULL){  //accediamo in modalità lettura
        fprintf(stderr, "Impossibile aprire %s\n", nome);

    }
    while(fscanf(fp,"%c",&c)==1){
        printf("%c",c);
    }
    fclose(fp);

}