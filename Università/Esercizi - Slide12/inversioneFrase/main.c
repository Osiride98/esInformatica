#include<stdio.h>
#include<string.h>

#define MAX_CHAR 256

void inverti(char *s){

    int count = strlen(s);

    char parInv;

    for (int i = 0; i < count/2; ++i){
        parInv = s[i];
        s[i] = s[count-1-i];
        s[count-1-i] = parInv;
    }
}

int main(){

char parola[MAX_CHAR];

printf("inserisci una parola = ");
scanf("%[^\n]", &parola);

inverti(parola);

printf("%s\n", parola);
}