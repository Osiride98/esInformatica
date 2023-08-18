#include "radio.h"

int leggiCanzoni(char* nomefile, Canzone playlist[]) {

	FILE* fp;
	fp = fopen(nomefile, "r");
	if (fp==NULL) {
		fprintf(stderr, "impossibile aprire il file %s\n", nomefile);
		exit(1);
	}

	char s_genere[2];
	Canzone t;
	int i=0;

	while(fscanf(fp, "%s%s%s%s%d%d%d", t.codice, t.titolo, t.artista, s_genere, &t.anno, &t.minuti, &t.secondi)==7) {
		t.genere = s_genere[0];
		playlist[i] = t;
		i++;
	}
	fclose(fp);
	return i;

}

void stampaCanzone(Canzone c) {
	printf("%s %s %s %c %d %d %d\n", c.codice, c.titolo, c.artista, c.genere, c.anno, c.minuti, c.secondi);	
}

int leggiRichieste(char* nomefile, Richiesta richieste[]){

	FILE* fp;
        fp = fopen(nomefile, "r");
        if (fp==NULL) {
                  fprintf(stderr, "impossibile aprire il file %s\n", nomefile);
                  exit(1);
        }
	Richiesta t;
	int i=0;
	while(fscanf(fp, "%s%s%s", t.nome_asc, t.titolo, t.dedica) == 3) {
		richieste[i++]=t;
	}
	fclose(fp);
	return i;
}

int trovaCanzone(Canzone c[], int dimC, char *titolo) {
	int i;
	for (i=0; i<dimC; i++) {
		if(strcmp(c[i].titolo, titolo) == 0) 
			return i;
	}
	return -1;

}

int richAscoltatore(Canzone c[], int dimC, Richiesta r[], int dimR, char* ascoltatore) {
	int i, j;
	int tot_sec=0;	
	int tot_jr=0;

	for(i=0; i<dimR; i++) {
		if(strcmp(ascoltatore, r[i].nome_asc) == 0) {
			j = trovaCanzone(c, dimC, r[i].titolo);
			if(j<0) 
				return 0;
			tot_sec += 60*c[j].minuti + c[j].secondi;
			if(tot_sec>15*60)
				return 0;
			if(c[j].genere == 'J' || c[j].genere == 'R') {
				tot_jr++;
				if(tot_jr >5) 
					return 0;	
			}
			
		}
	}

	return 1;
}

void ordina(Canzone playlist[], int dimC) {
	int i, j;
	Canzone t;
	
	for(i=1; i<dimC; i++) {
		for(j=i; (playlist[j-1].anno > playlist[j].anno) && j>0 ; j--) {
			t = playlist[j-1];
			playlist[j-1]=playlist[j];
			playlist[j] = t;
		}
	}
}

int inserisciRichiesta(FILE *fp, Canzone c[], int dimC, Richiesta r[], int dimR) {

	Richiesta rc;
	int trovata;

	scanf("%s", rc.nome_asc);
	scanf("%s", rc.titolo);
	scanf("%s", rc.dedica);

	trovata = trovaCanzone(c, dimC, rc.titolo);
	if(trovata <0) {
		return 0;	
	}

	r[dimR] = rc;
	dimR++;

	if(richAscoltatore(c, dimC, r, dimR, rc.nome_asc)) {
		fprintf(fp, "%s %s %s\n" rc.nome_asc, rc.titolo, rc.dedica);
		return 1;	
	} 	
	else return 0;
}

