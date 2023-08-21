#include "manager.h"
#include "function.h"

int main() {
    int i;
    /* leggo i dati sui condomini */
    int ncd;
    Condominio *cd = readcondomini("condomini.txt", &ncd);

    printf("CONDOMINI ====\n");
    for(i = 0; i < ncd; ++i)
        stampa_condominio(cd[i]);

    /* leggo i dati sulle comunicazioni */
    int nca;
    ComA *ca = readComA("comunicazioni.txt", &nca);

    printf("\n");
    printf("COMUNICAZIONI ====\n");
    for(i = 0; i < nca; ++i)
        stampaComA(ca[i]);

    int nce;
    ComE *ce = readComE("comunicazioni.txt", &nce);

    for(i = 0; i < nce; ++i)
        stampaComE(ce[i]);

    /* stampa ed ordinamento */
    printf("\n");
    printf("INFORMAZIONI SU UN CONDOMINIO ====\n");
    stampaCondominio(cd, ncd, ca, nca, ce, nce);


    /* spese di un condominio */
    printf("\n");
    printf("SPESE SU UN CONDOMINIO ====\n");
    int cod;
    printf("Inserire un codice di condominio: ");
    scanf("%d", &cod);
    double sum = sommaSpese(cod, ce, nce);
    printf("Somma delle spese nette: %.3f\n", sum);

    /* spese di un condominio */
    printf("\n");
    printf("INSERIMENTO DI UNA NUOVA COMUNICAZIONE A ====\n");
    insert("comunicazioni.txt", 'A');

    printf("\n");
    printf("INSERIMENTO DI UNA NUOVA COMUNICAZIONE E ====\n");
    insert("comunicazioni.txt", 'E');

    /* libero la memoria */
    free(cd);
    free(ca);
    free(ce);
}
