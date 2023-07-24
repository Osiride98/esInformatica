#include <stdio.h>
#include <string.h>

#define NF 256

void inverti(char *s) {
    // Determino la lunghezza
    int n = strlen(s);
    // Scambio le lettere, fino a metà stringa
    char t; // Variabile di appoggio
    for(int i = 0; i < n/2; ++i) {
        t = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = t;
    }
}

int main() {
    char p[NF];
    printf("Inserire una frase: ");
    scanf("%[^\n]", p);
    inverti(p);
    printf("%s\n", p);
}
