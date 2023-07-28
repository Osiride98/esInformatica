#include<stdio.h>
#include<string.h>

char carattere_minuscolo(char c){

    int newC = (int)c;      // operazione di casting per trasformare il char in int
    
    if(newC >= 65 && newC <= 90){

        newC = newC+32;
        printf("valore tabella ASCII %d\n", newC);
        printf("Lettera Minuscola -> %c\n", newC);

        }else if ( newC >= 97 && newC <= 122){
            printf("il carattere e' gia minuscolo\n");

                }else{
                    printf("il carattere non è supportato\n");
                        }
}

void stringa_minuscola(char *src, char *dst){
    int i;

    for(i = 0; src[i] != '\0'  ; i++){      // ciclo per controllare l'intera stringa fino a che non si trova il carattere \0 ( terminatore )

        int letter_min = (int)src[i];

        if(letter_min >= 65 && letter_min <=90){
            letter_min = letter_min + 32;
            dst[i] = letter_min;

                }else{
                    dst[i]= src[i];
                    }
    }
    dst[i] = '\0'; // Aggiungi il terminatore nullo alla fine della stringa
}

int main(){

// PARTE 1
printf("---PARTE 1---\n");

char c;

printf("Inserisci un carattere = \n");
scanf(" %c", &c);
         
carattere_minuscolo(c);

// PARTE 2

printf("---PARTE 2---\n");

char src[10];
char dst[10];

printf("Inserisci una parola o frase = \n");
scanf("%s", src);

stringa_minuscola(src, dst);

printf("%s\n", dst);



// PARTE 3
printf("---PARTE 3---\n");

 for(int j = 0 ; j < 3 ; j++ ){

        printf("Inserisci una parola = \n");
        scanf("%s", src);

        stringa_minuscola(src, dst);
        printf("%s\n", dst);
    }

}