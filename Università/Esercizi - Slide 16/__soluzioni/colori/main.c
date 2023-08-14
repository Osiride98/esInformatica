#include "colori.h"

#define N 10

int main() {
    ColoreCSS c1[N];
    ColoreRGB c2[N];
    int n1 = 0, n2 = 0;
    /* leggo le informazioni sui colori */
    leggi_colori("colori.txt", c1, &n1, c2, &n2);
    stampa_colori(c1, n1, c2, n2);

    return 0;
}
