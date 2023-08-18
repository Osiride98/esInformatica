#include "persone.h"

#define N 4

int main() {

	Persona l[N];

	int i;
	for (i=0; i<N; i++) {
		l[i]= leggi_persona();
	}

	ordina_persone(l, N);

	for (i=0; i<N; i++) 
		stampa_persona(l[i]);
}
