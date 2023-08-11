#include "punti.h"

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
