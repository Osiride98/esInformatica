#ifndef _PERSONAH_      //file di tipo header 
#define _PERSONAH_
#define MAX_CHAR 10  //SCRITTO IN SNAKE CASE (SEMPRE MAIUSCOLO)
// ALL'INTERNO DI UNA LIBRERIA VANNO DEFINITE LE FUNZIONI MA NON IMPLEMENTATE

typedef struct {
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
    int eta;
    char sesso[MAX_CHAR];
}persona;

void leggi_persona(persona *p); //p sarà una persona che contiene nome, cognome, età (uso il puntatore perchè vado nella cella di memoria e scrivo un valore)

void stampa_persona(persona p); // per stampare mi basta indicare l'indirizzo della variabile

int eta_persona(int eta);



#endif