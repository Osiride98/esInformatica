#include "gestioneTratte.h"

int main(void)
{
	FILE *fp;
	Prenotazione *p;
	Tratta *t;
	Tratta *tratteCercate;
	int i, dimP, dimT, res, dimC;

	// test esercizio 1
	p = leggiPrenotazioni("prenotazioni.txt", &dimP);
	for (i = 0; i < dimP; i++)
		stampaPrenotazione(p[i]);
	t = leggiCollegamenti("collegamenti.txt", &dimT);
	for (i = 0; i < dimT; i++)
		stampaTratta(t[i]);

	// test esercizio 2
	if ((fp = fopen("prenotazioni.txt", "a")) == NULL)
		exit(1);
	res = nuovaPrenotazione(fp, t, dimT);
	printf("\nRisultato inserimento: %d", res);
	fclose(fp);

	// test esercizio 3
	tratteCercate = trovaCollegamento("BOL", t, dimT, &dimC);
	printf("\nTreni che fanno scalo a Bologna");
	for (i = 0; i < dimC; i++)
		stampaTratta(tratteCercate[i]);

	printf("\n");

	free(p);
	free(t);
	free(tratteCercate);
	
	return 0;
}
