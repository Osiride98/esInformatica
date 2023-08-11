#include <stdio.h>

// Dato un numero n 
// si calcoli la somma degli interi a 1 a n
// si calcoli poi il risultato della formula di gauss:
// [n(n+1)]/2
// verificare a video che i due valori coincidano 

int main() {

    int n;
    
    printf("Inserisci Valore =");
    scanf("%d", &n);

    int s = 0;      // Variabile "accumulatore"
    while (n > 0) {
    s += n;
    n--;
    }

    int b=0;
    if(n>0) {
        b = (n*(n+1))/2;
        }
    else {
        printf("operazione non possibile");
        }

    printf("Risultato Sommatoria = %d\n", s);
    printf("Risultato Gauss = %d\n", b);

}
