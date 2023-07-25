#include<stdio.h>
#include<string.h>


char carattere_minuscolo(char c){


}

int main(){

// PARTE 1

char c;

printf("Inserisci un carattere = ");
scanf("%c", &c);

printf("carattere = %c", c);   //in questi due print noto la differenza che il primo avente %c mi stampa a schermo il carattere da me inserito
printf("carattere = %d", c);   //il secondo %d mi stampa il valore del carattere inserito rispetto alla tabella ascii
         
carattere_minuscolo(c);

}