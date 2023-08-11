#include<stdio.h>
#include<string.h>

#define MAX_CHAR 255
#define N 3

typedef struct {
    char nome[MAX_CHAR];
    char cognome[MAX_CHAR];
}persona;

void leggi_persona(persona *p){

    printf("Inserisci Nome e Cognome =");
    scanf("%s %s", &p->nome, &p->cognome);

}

void stampa_persone(persona *l, int n){

    for(int i = 0; i < n ; i++ ){
        printf("Nome e Cognome -> %s %s\n", l[i].nome, l[i].cognome);
    }

}

int uguali(persona *p1, persona *p2){
    int res = 0;

    if(strcmp(p1->nome, p2->nome) == 0 && strcmp(p1->cognome, p2->cognome) == 0 ){
        res  = 1;
        return res;
        }else{
            res = -1;
            return res;
    }
}

int presente(persona *lista, int n, persona *p){

    int resPres = 0;

    for(int k = 0; k < n ; k++){

        if (strcmp(p->nome, lista[k].nome) == 0 && strcmp(p->cognome, lista[k].cognome) == 0 ){
           resPres = 1;
           break; 
        }else{
            resPres = -1;
        }
    }

    return resPres;

}

void trova_unici(persona *lista, int n, persona *unici, int *nu){

    int resUnici = 0;

    for(int k = 0; k < n ; k++){
        
        int count = 0;
        int ugualiPre = 0;
        int ugualiPost = 0;

        printf("valore di count rispetto a k=%d -> count=%d", k,count);

        if(k == 0){
            int a = 1;
            while ( a < n){
                if(strcmp(lista[k].nome, lista[a].nome) == 0 && strcmp(lista[k].cognome, lista[a].cognome) == 0 ){
                resUnici = 0;
                a++;
                break;
                }else{
                    resUnici= 1; 
                    a++;
                    }
            
                        }
                printf("valore di resUnici 1 = %d\n", resUnici);
                if (resUnici == 1){
                    unici[k]=lista[k];
                    //printf("Nome e Cognome -> %s %s", unici[k].nome, unici[k].cognome);
                }
                
                }
        if (k > 0 ){
            while (count < k ){
                if(strcmp(lista[k].nome, lista[count].nome) == 0 && strcmp(lista[k].cognome, lista[count].cognome) == 0 ){
                    resUnici = 0;
                    ugualiPre = 1;
                    count ++;
                    break; 
                    }else{
                        resUnici = 1;
                        ugualiPre = 0; 
                        count++; 
                        }
                            }
            count = k+1;
            while (count < n ){
                if(strcmp(lista[k].nome, lista[count].nome) == 0 && strcmp(lista[k].cognome, lista[count].cognome) == 0 ){
                    resUnici = 0;
                    ugualiPost = 1;
                    count ++;
                    break;
                    }else{
                        resUnici = 1;
                        ugualiPost = 0;
                        count++; 
                        }
                            }
                printf("valore di resUnici 2 = %d\n", resUnici);
                if (resUnici == 1 && ugualiPre == 0 && ugualiPost == 0){
                    unici[k]=lista[k];
                }
        }
    }
}

    
 

int main(){

// PARTE 1 
printf("----- PARTE 1 -----\n");

persona arrayPersone[N];

for(int j=0 ; j < N ; j++){

    persona p[j];
    leggi_persona(&p[j]);
    arrayPersone[j] = p[j];  
}

stampa_persone(arrayPersone, N);

printf("la seconda e la terza persona sono uguali?\n");

int res = uguali(&arrayPersone[1], &arrayPersone[2]);

if (res == 1){
    printf("vero\n");
        }else{
            printf("falso\n");
            }

// PARTE 2

printf("----- PARTE 2 -----\n");

persona p4;

leggi_persona(&p4);

int resPres = presente(arrayPersone, N, &p4);

printf("Sono presenti Omonimie nella lista ?\n");

if (resPres == 1){
    printf("vero\n");
        }else{
            printf("falso\n");
            }

// PARTE 3

printf("----- PARTE 3 -----\n");

int nu = N-1;

persona unici[N];

trova_unici(arrayPersone, N, unici, &nu);

stampa_persone(unici, N);

}