#include <stdio.h>
#include <math.h>

#define N 4

typedef struct { float x, y; } punto;

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

    // Calcolo la distanza tra i primi due punti
    printf("\nPARTE 2 ====\n");
    float d = distanza(&punti[0], &punti[1]);
    printf("Distanza tra i primi due punti: %.2f\n", d);
    
    // Calcolo la massima distanza tra le coppie di punti
    printf("\nPARTE 3 ====\n");
    d = max_distanza(punti, N);
    printf("Massima distanza: %.2f\n", d);
}
