#include "punti.h"

void leggi_punto(punto *p) {
    printf("Inserire le coordinate x e y: ");
    scanf("%f%f", &p->x, &p->y);
}

void stampa_punto(punto *p) {
    printf("%.2f, %.2f\n", p->x, p->y);
}

float distanza(punto *p1, punto *p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}

float max_distanza(punto *l, int n) {
    float max = -1;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            float d = distanza(&l[i], &l[j]);
            if(d > max) {
                max = d;
            }
        }
    }
    return max;
}

