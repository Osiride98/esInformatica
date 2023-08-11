#include "segmenti.h"

// void leggi_punto(punto *p){
//     printf("Inserire coordinata X ->");
//     scanf("%d", &p->x);
//     printf("Inserire coordinata Y ->");
//     scanf("%d", &p->y);
// }

// void stampa_punto(punto *p){
//     printf("valore di X -> %d\n", p->x);
//     printf("valore di Y -> %d\n", p->y);
// }

segmento crea_segmento(punto *p, punto *q){
    segmento s;

    s.xi = p->x;
    s.yi = p->y;
    s.xf = q->x;
    s.yf = q->y;

    return s;
}

void stampa_con_lunghezza(segmento *s){

    printf("\ninizio segmento (x %d, y %d)", s->xi, s->yi);
    printf("\nfine segmento (x %d, y %d)", s->xf,s->yf);

    float lenX, lenY;

    if (s->xi > s->xf){
      lenX = (s->xi - s->xf);
        }else{
            lenX=(s->xf - s->xi);
            }
    if (s->yi > s->yf){
      lenY = (s->yi - s->yf);
        }else{
            lenY=(s->yf - s->yi);
            }
    float lenSegm = sqrt((pow(lenX,2))+(pow(lenY,2)));

    printf("\nlunghezza segmento -> %.3f\n", lenSegm);
}

void crea_segmenti(segmento *ls, punto *lp, int n){

    segmento s1;
    int count = 0;
    for (int i = 0; i < n; i++){
        for (int k = i+1; k < n; k++){
            s1 = crea_segmento(&lp[i], &lp[k]);
            ls[k] = s1;
            count++;
            printf("Segmento %d = (x %d, y %d)-(x %d, y %d)\n", count, s1.xi,s1.yi,s1.xf,s1.yf);
        }
    }
}