#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DIM_CODICE_TRENO 6
#define DIM_NOME 21
#define DIM_CODICE_CITTA 4

typedef struct
{
	char codiceTreno[DIM_CODICE_TRENO];
	char cittaPartenza[DIM_CODICE_CITTA];
	char cittaDestinazione[DIM_CODICE_CITTA];
	int durata;
	float prezzo;
} Tratta;

typedef struct
{
	int giorno;
	int mese;
	int anno;
} data;

typedef struct
{
	data dataAcquisto;
	data dataViaggio;
	char codiceTreno[DIM_CODICE_TRENO];
	char nomeCliente[DIM_NOME];
	char AR;
	int quantita;
	float totale;
} Prenotazione;

Tratta *leggiCollegamenti(char fileName[], int *dim);
void stampaTratta(Tratta t);
Prenotazione *leggiPrenotazioni(char fileName[], int *dim);
void stampaPrenotazione(Prenotazione p);
int nuovaPrenotazione(FILE *fp, Tratta *t, int dimT);
Tratta *trovaCollegamento(char *citta, Tratta *t, int dimT, int *dimResult);
