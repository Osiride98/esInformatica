#include <stdio.h>

#define N 256
#define N2 3

char carattere_minuscolo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a');
    }
    else
        return c;
}

void stringa_minuscola(char *src, char *dst) {
    // Converto i caratteri in minuscolo
    int i;
    for(i = 0; src[i] != '\0'; ++i) {
        dst[i] = carattere_minuscolo(src[i]);
    }
    // Aggiungo il terminatore
    dst[i] = '\0';
}

int main() {
    // Preparo due "buffer"
    char t[N], s[N];
    // Leggo 3 parole
    for(int i = 0; i < N2; ++i) {
        // Leggo una parola
        printf("Inserire una parola: ");
        scanf("%s", s);
        // Converto in minuscolo
        stringa_minuscola(s, t);
        // Stampo (aggiungo uno spazio a tutte le stampe
        printf("In minuscolo: %s\n", t);
    }
}
