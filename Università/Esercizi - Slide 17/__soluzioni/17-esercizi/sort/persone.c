#include "persone.h"

Persona leggi_persona() {
	Persona res;

	printf("Inserire nome e cognome: ");
	scanf("%s%s", res.nome, res.cognome);
	return res;
}

void stampa_persona(Persona p) {
	printf("%s %s\n", p.nome, p.cognome);
}

int cmppersona(Persona p1, Persona p2) {
	int r = strcmp(p1.cognome, p2.cognome);
	if(r!=0) return r;
	return strcmp(p1.nome, p2.nome);
}

void scambia_persone(Persona *p1, Persona *p2) {
	Persona t;
	t=*p1;
	*p1=*p2;
	*p2=t;
} 

void ordina_persone(Persona *l, int n){
	int i, j;
	for (i=1;i<n;i++) {
		for(j=i; j>0; j--) {
			if(cmppersona(l[j-1], l[j]) > 0) {	
				scambia_persone(&l[j-1], &l[j]);
			} 
			else break;		
		}
	}
	
}
