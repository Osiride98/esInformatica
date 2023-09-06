#include "gestioneTratte.h"

Tratta *leggiCollegamenti(char fileName[], int *dim)
{
	int count, i;
	FILE *fp;
	Tratta *result;
	Tratta temp;

	// Apro il file
	if ((fp = fopen(fileName, "r")) == NULL)
		exit(1);
	count = 0;

	// Conto le righe nel file
	while (fscanf(fp, "%s %s %s %d %f",
				  temp.codiceTreno, temp.cittaPartenza, temp.cittaDestinazione,
				  &(temp.durata), &(temp.prezzo)) == 5)
		count++;

	// Alloco memoria dinamicamente
	result = (Tratta *)malloc((size_t)count * sizeof(Tratta));

	// Leggo i dati
	rewind(fp);
	for (i = 0; i < count; i++)
		fscanf(fp, "%s %s %s %d %f",
			   result[i].codiceTreno, result[i].cittaPartenza, result[i].cittaDestinazione,
			   &(result[i].durata), &(result[i].prezzo));

	// Chiudo il file
	fclose(fp);

	*dim = count;
	return result;
}

void stampaTratta(Tratta t)
{
	printf("\nTratta - Codice Treno: %s\t Citta Partenza: %s\t Citta Arrivo: %s\t Durata: %d\t Prezzo: %f", t.codiceTreno, t.cittaPartenza, t.cittaDestinazione, t.durata, t.prezzo);
}

Prenotazione *leggiPrenotazioni(char fileName[], int *dim)
{
	int count, i;
	FILE *fp;
	Prenotazione *result;
	Prenotazione temp;

	// Apro il file
	if ((fp = fopen(fileName, "r")) == NULL)
		exit(1);

	// Conto le righe nel file
	count = 0;
	while (fscanf(fp, "%d %d %d %d %d %d %s %s %c %d %f",
				  &temp.dataAcquisto.giorno, &temp.dataAcquisto.mese, &temp.dataAcquisto.anno,
				  &temp.dataViaggio.giorno, &temp.dataViaggio.mese, &temp.dataViaggio.anno,
				  temp.codiceTreno, temp.nomeCliente, &(temp.AR),
				  &(temp.quantita), &(temp.totale)) == 11)
		count++;

	// Alloco memoria dinamicamente
	result = (Prenotazione *)malloc((size_t)count * sizeof(Prenotazione));

	// Leggo i dati
	rewind(fp);
	for (i = 0; i < count; i++)
		fscanf(fp, "%d %d %d %d %d %d %s %s %c %d %f",
			   &result[i].dataAcquisto.giorno, &result[i].dataAcquisto.mese, &result[i].dataAcquisto.anno,
			   &result[i].dataViaggio.giorno, &result[i].dataViaggio.mese, &result[i].dataViaggio.anno,
			   result[i].codiceTreno, result[i].nomeCliente, &(result[i].AR),
			   &(result[i].quantita), &(result[i].totale));

	// Chiudo il file
	fclose(fp);

	*dim = count;
	return result;
}

void stampaPrenotazione(Prenotazione p)
{
	printf("\nPrenotazione - Data acquisto: %d.%d.%d\t Data viaggio: %d.%d.%d\t Codice Treno: %s\n	\
		Nome Cliente: %s\t Tipo: %c\t Numero Biglietti: %d\t Costo Totale: %.2f",
		   p.dataAcquisto.giorno, p.dataAcquisto.mese, p.dataAcquisto.anno,
		   p.dataViaggio.giorno, p.dataViaggio.mese, p.dataViaggio.anno,
		   p.codiceTreno, p.nomeCliente, p.AR, p.quantita, p.totale);
}

int calcolaAnticipo(data odierna, data viaggio)
{
	int ao = odierna.anno, av = viaggio.anno;
	int mo = odierna.mese, mv = viaggio.mese;
	int go = odierna.giorno, gv = viaggio.giorno;

	int dg = gv - go;
	int dm = mv - mo;
	int da = av - ao;

	// Differenza totale in giorni
	int dgt = dg + dm * 30 + da * 360;
	//  Differenza totale in mesi
	int dmt = dgt / 30;

	return dmt;
}

int nuovaPrenotazione(FILE *fp, Tratta *t, int dimT)
{
	char trattaDaInserire[DIM_CODICE_TRENO], nomeCliente[DIM_NOME];
	char cittaDestinazione[DIM_CODICE_CITTA];
	char cittaPartenza[DIM_CODICE_CITTA];
	char tipo;
	int i, trattaEsiste = 0, numero, caratteriScritti;
	float prezzoBase, costoTotale;
	data odierna, viaggio;

	printf("\nInserimento nuova prenotazione");
	printf("\n\nNome Cliente?\t");
	scanf("%s", nomeCliente);
	printf("%s", nomeCliente);

	printf("\n\nDATA ODIERNA\t");
	printf("\ngiorno\t");
	scanf("%d", &odierna.giorno);
	printf("\nmese\t");
	scanf("%d", &odierna.mese);
	printf("\nanno\t");
	scanf("%d", &odierna.anno);

	printf("\n\nDATA VIAGGIO\t");
	printf("\ngiorno\t");
	scanf("%d", &viaggio.giorno);
	printf("\nmese\t");
	scanf("%ds", &viaggio.mese);
	printf("\nanno\t");
	scanf("%d", &viaggio.anno);

	printf("\n\nCitta partenza?\t");
	scanf("%s", cittaPartenza);

	printf("\n\nCitta destinazione?\t");
	scanf("%s", cittaDestinazione);

	printf("\n\nTipo biglietto?\t");
	scanf("%*c"); // IMPORTANTE: consuma caratteri spuri rimasti nel buffer di inserimento
	scanf("%c", &tipo);

	printf("\n\nNumero biglietti?\t");
	scanf("%d", &numero);

	// Possibile errore: tipo di biglietto non valido
	if (tipo != 'A' && tipo != 'R')
	{
		printf("Tipo biglietto non valido");
		return -1;
	}

	// Cerco la tratta
	for (i = 0; i < dimT; i++)
	{
		if ((!strcmp(cittaPartenza, t[i].cittaPartenza) && !strcmp(cittaDestinazione, t[i].cittaDestinazione)) ||
			(!strcmp(cittaDestinazione, t[i].cittaPartenza) && !strcmp(cittaPartenza, t[i].cittaDestinazione)))
		{
			trattaEsiste = 1;
			prezzoBase = t[i].prezzo;
			strcpy(trattaDaInserire, t[i].codiceTreno);
			break;
		}
	}

	// Possibile errore: non ci sono tratte
	if (!trattaEsiste)
	{
		printf("\n\nERRORE: La tratta richiesta non è disponibile.\n\n");
		return -1;
	}

	// Aggiunstamento del prezzo per A o R
	if (tipo == 'A')
		costoTotale = (float)numero * prezzoBase;
	else
		costoTotale = (float)numero * (prezzoBase + prezzoBase * 1.7f);

	// Aggiunstamento del prezzo in base alla data
	if (calcolaAnticipo(odierna, viaggio) > 12)
		costoTotale -= costoTotale * 0.5f;
	else if (calcolaAnticipo(odierna, viaggio) > 6)
		costoTotale -= costoTotale * 0.2f;

	// Scrittura su file
	caratteriScritti = fprintf(fp, "%d %d %d %d %d %d %s %s %c %d %f\n",
							   odierna.giorno, odierna.mese, odierna.anno,
							   viaggio.giorno, viaggio.mese, viaggio.anno,
							   trattaDaInserire, nomeCliente, tipo, numero, costoTotale);
	// Possibile errore: non sono riuscito a scrivere su file
	if (caratteriScritti <= 0)
		return -1;

	// Giunti a questo punto, l'inserimento è andato a buon fine
	printf("\nPrenotazione inserita - Data acquisto: %d.%d.%d\t Data viaggio: %d.%d.%d\t Codice Treno: %s\n	\
		Nome Cliente: %s\t Tipo: %c\t Numero Biglietti: %d\t Costo Totale: %.2f",
		   odierna.giorno, odierna.mese, odierna.anno,
		   viaggio.giorno, viaggio.mese, viaggio.anno,
		   trattaDaInserire, nomeCliente, tipo, numero, costoTotale);

	return 0;
}

Tratta *trovaCollegamento(char *citta, Tratta *t, int dimT, int *dimResult)
{
	int i, j, k;
	Tratta *collegamentiTrovati;

	// Conto i collegamenti disponibili per la città
	for (i = 0; i < dimT; i++)
		if (!strcmp(citta, t[i].cittaDestinazione) || !strcmp(citta, t[i].cittaPartenza))
			(*dimResult)++;

	// Alloco lo spazio necessario
	collegamentiTrovati = (Tratta *)malloc((size_t)(*dimResult) * sizeof(Tratta));

	// Inserisco i collegamenti utilizzando un algoritmo di insert sort
	// ALTERNATIVA: li inserisco in ordine di apparizione della lista e dopo li ordino con un qualsiasi algoritmo
	j = 0;
	for (i = 0; i < dimT; i++)
	{
		if (!strcmp(citta, t[i].cittaDestinazione) || !strcmp(citta, t[i].cittaPartenza))
		{
			k = j - 1;
			while (k >= 0 && t[i].prezzo < collegamentiTrovati[k].prezzo)
			{
				collegamentiTrovati[k + 1] = collegamentiTrovati[k];
				k--;
			}
			collegamentiTrovati[k + 1] = t[i];
			j++;
		}
	}

	return collegamentiTrovati;
}
