#include <stdio.h>
#include <math.h>

#define N 4

typedef struct { float x, y; } punto;

typedef struct { punto p, q; } segmento;

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

int main() {
    punto punti[N];

    // Leggo un array di punti
    printf("PARTE 1 ====\n");
    for(int i = 0; i < N; ++i) {
        leggi_punto(&punti[i]);
    }
    printf("\nPUNTI:\n");
    for(int i = 0; i < N; ++i) {
        stampa_punto(&punti[i]);
    }
    printf("\n");

    // Creao un segmento tra i primi due punti e calcolo la distanza
    segmento s = crea_segmento(&punti[0], &punti[1]);
    stampa_con_lunghezza(&s);
    printf("\n");

    // Genero tutti i segmenti e calcolo tutte le distanze 
    segmento segmenti[N*(N-1)/2];
    crea_segmenti(segmenti, punti, N);

    printf("Distanze:\n");
    for(int i = 0; i < N*(N-1)/2; ++i) {
        stampa_con_lunghezza(&segmenti[i]);
    }
}
