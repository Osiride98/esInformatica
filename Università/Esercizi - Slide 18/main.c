#include "canzoni.h"
#include "canzoni.c"

#define MAX_SONGLIST 40
#define MAX_SONREQUEST 30

int main(){
//PARTE 1 - CANZONE
printf("---PARTE 1---\n");

canzone arrayCanzoni[MAX_SONGLIST];

int numCanzoni = leggiCanzoni("canzoni.txt", arrayCanzoni);
// printf("Numero di canzoni in lista %d su %d\n", numCanzoni,MAX_SONGLIST);

// int listPoint;

// printf("Quale canzone della lista vuoi ascoltare?");
// scanf("%d", &listPoint);

// stampaCanzone(arrayCanzoni[listPoint-1]);

//PARTE 1 - RICHIESTA

richiesta arrayRichieste[MAX_SONREQUEST];

int numRichieste = leggiRichieste("richieste.txt", arrayRichieste);
// printf("Numero di Richieste : %d\n", numRichieste);

// int listRequest;

// printf("Scegliere una richiesta da mandare in onda da %d a %d -> ", 0, numRichieste);
// scanf("%d", &listRequest);

// stampaRichiesta(arrayRichieste[listRequest-1]);

//PARTE 2 
printf("---PARTE 2---\n");

char nomeAscoltatore[41];
printf("Inserire nome Ascoltatore ->");
scanf("%s", &nomeAscoltatore);

printf("nome tipo = %s\n", nomeAscoltatore);

int resRichiesta = richAscoltatore(arrayCanzoni, numCanzoni, arrayRichieste, numRichieste, nomeAscoltatore);

}