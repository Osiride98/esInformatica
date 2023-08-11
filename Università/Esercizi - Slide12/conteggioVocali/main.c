#include<stdio.h>
#include<string.h>

#define MAX_CHAR 10

int conta_vocali(char *s){
    int count = 0;

    for(int i = 0; s[i] != '\0'  ; i++){
        if (s[i]== 'a' || s[i]== 'e' || s[i]== 'i' || s[i]== 'o' || s[i]== 'u'){
            count++;
        }
    }
    return count;
}

int main(){

char parola[MAX_CHAR];

printf("inserisci una parola =");
scanf("%s", &parola);

int res = conta_vocali(parola);

printf("la parola -%s- contiene %d vocali", parola, res);
}