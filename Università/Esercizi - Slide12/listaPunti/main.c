#include<stdio.h>
#include<string.h>
#include<math.h>

#define N 4

typedef struct {
    int x;
    int y;
}punto;

void leggi_punto(punto *p){
    printf("Inserire coordinata X ->");
    scanf("%d", &p->x);
    printf("Inserire coordinata Y ->");
    scanf("%d", &p->y);
}

void stampa_punto(punto *p){
    printf("valore di X -> %d\n", p->x);
    printf("valore di Y -> %d\n", p->y);
}

float distanza(punto *p1, punto *p2){

    float res = sqrt((pow((p2->x - p1->x),2))+(pow((p2->y - p1->y),2)));
    return res;
}

float max_distanza(punto *l, int n){
    
    float dist, maxDist= 0 ;

    for (int j = 0; j < n; j++){

        for (int k = 0; k < n; k++){

            dist = distanza(&l[j], &l[k]);
            //printf("dist per valore di j %d e k %d = %f\n", j, k, dist);

                    if (dist>=maxDist){

                    maxDist = dist;
            }
        }        
    }
    return maxDist;

}

int main(){
//PARTE 1 
printf("---Parte 1---\n");

punto arrayPunti[N];
punto p;

for (int i = 0; i < N; i++){
    leggi_punto(&p);
    arrayPunti[i] = p;
    stampa_punto(&p);
}

//PARTE 2 
printf("---Parte 2---\n");

float distEucl;

distEucl = distanza(&arrayPunti[0],&arrayPunti[1]);

printf("Distanza Euclidea = %.3f\n", distEucl);

//PARTE 3
printf("---Parte 3---\n");

float risultatoMaxDistanza;

risultatoMaxDistanza = max_distanza(arrayPunti, N);

printf("Max Dist = %f", risultatoMaxDistanza);

}
