#include <stdio.h>
#include <string.h>

#define NSTR 256
#define N 3

typedef struct {char nome[NSTR], cognome[NSTR];} persona;

void leggi_persona(persona *p) {
    printf("Inserire nome e cognome: ");
    scanf("%s%s", p->nome, p->cognome);
}

void stampa_persone(persona *l, int n) {
    printf("LISTA PERSONE:\n");
    for(int i = 0; i < n; ++i) {
        printf("%s %s\n", l[i].nome, l[i].cognome);
    }
}

int uguali(persona *p1, persona *p2) {
    return strcmp(p1->nome, p2->nome) == 0 &&
           strcmp(p1->cognome, p2->cognome) == 0;
}

int presente(persona *lista, int n, persona p) {
    int trovato = 0;
    for(int i = 0; i < n; ++i) {
        if(uguali(&lista[i], &p)) {
            trovato = 1;
            break;
        }
    }
    return trovato;
}

void trova_unici(persona *lista, int n, persona *unici, int *nu) {
    *nu = 0;
    for(int i = 0; i < n; ++i) {
        // Controllo se la persona sia presente nella lista
        // attuale con i nominativi unici
        if (!presente(unici, *nu, lista[i])) {
            // Se non è presente, la inserisco
            unici[*nu] = lista[i];
            *nu += 1;
        }
    }
}

int main() {
    // Parte 1: leggo nomi e cognomi e li metto in un array
    printf("PARTE 1 ====\n");
    persona anagrafica[N];
    for(int i = 0; i < N; ++i)
        leggi_persona(&anagrafica[i]);
    stampa_persone(anagrafica, N);

    // Parte 2: verifico se i primi due nomi siano uguali
    printf("PARTE 2 ====\n");
    int cmp = uguali(&anagrafica[0], &anagrafica[1]);
    if (cmp) printf("Primi due nomi uguali\n");
    else printf("Primi due nomi diversi\n");

    // Parte 3: si verifichi se un nuovo nome sia presente
    printf("PARTE 3 ====\n");
    persona t;
    leggi_persona(&t);
    int prs = presente(anagrafica, N, t);
    if (prs) printf("Nominativo presente\n");
    else printf("Nominativo assente\n");

    // Parte 4: si individuino i nominativi unici
    printf("PARTE 4 ====\n");
    persona unici[N];
    int nu = 0;
    trova_unici(anagrafica, N, unici, &nu);
    stampa_persone(unici, nu);
}
