#ifndef _PERSONAH_      //file di tipo header 
#define _PERSONAH_
#define MAX_CHAR 10  //SCRITTO IN SNAKE CASE (SEMPRE MAIUSCOLO)
// ALL'INTERNO DI UNA LIBRERIA VANNO DEFINITE LE FUNZIONI MA NON IMPLEMENTATE
//RICORDA DI INIZIALIZZARE IL *file*.h con #ifndef e #endif

//definisco la struttura "persona" che contiene tre variabili char (nome,cognome,sesso) e una variabile int (eta)
// il typedef è uno strumento utile per creare alias per i tipi di dato esistenti e l'utilizzo di variabili complesse nel codice
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