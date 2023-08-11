#include "segmenti.h"

segmento crea_segmento(punto *p, punto *q) {
    segmento res;
    res.p = *p;
    res.q = *q;
    return res;
}

void stampa_con_lunghezza(segmento *s) {
    float l = distanza(&s->p, &s->q);
    printf("(%.2f, %.2f)--(%.2f, %.2f): %.2f\n",
            s->p.x, s->p.y, s->q.x, s->q.y, l);
}

void crea_segmenti(segmento *ls, punto *lp, int n) {
    int k = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            ls[k] = crea_segmento(&lp[i], &lp[j]);
            k++;
        }
    }
}
