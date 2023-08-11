#include <stdio.h>

#define NP 256

int conta_vocali(char *s) {
    int cnt = 0; // contatore
    for(int i = 0; s[i] != '\0'; ++i) {
        switch(s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cnt += 1;
        }
    }
    return cnt;
}

int main() {
    char p[NP];
    printf("Inserire una parola (in minuscolo): ");
    scanf("%s", p);

    printf("Numero di vocali: %d\n", conta_vocali(p));
}
