#include "piante.h"

int leggiProdotti (char* nomefile, Peperoncino vp[], int* dim){
    int res = 1; 

    FILE *fp = fopen(nomefile, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nomefile);
        exit(1);
        }else{
            printf("In Lettura\n");
            res = 0;
        }
    *dim = 0;
    Peperoncino temp;
    int i = 0;

    while(fscanf(fp, "%s%s%d%d%f", temp.codice, temp.nome, &temp.valore, &temp.quantita, &temp.prezzo) != EOF ){
        (*dim)++;
        vp[i] = temp;
        i++;
    }


    fclose(fp);
    return res;  
}  

void stampaProdotto (Peperoncino p){
    FILE *fp = fopen("prodotti.txt", "r");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire %s\n", "prodotti.txt");
            exit(1);
            }

    Peperoncino temp;

    while(fscanf(fp, "%s%s%d%d%f", temp.codice, temp.nome, &temp.valore, &temp.quantita, &temp.prezzo) != EOF ){
        if (strcmp(temp.nome,p.nome) == 0){
            printf("Codice Pep -> %s\n", temp.codice);
            printf("Nome Pep -> %s\n", temp.nome);
            printf("valore Pep -> %d\n", temp.valore);
            printf("quantita Pep -> %d\n", temp.quantita);
            printf("prezzo Pep -> %.3f\n", temp.prezzo);
        }
        
    }
    fclose(fp);
}

int leggiAcquisti (char* nomefile, Acquisto va[], int* dim){
        int res = 1; 

    FILE *fp = fopen(nomefile, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nomefile);
        exit(1);
        }else{
            printf("In Lettura\n");
            res = 0;
        }
    *dim = 0;
    Acquisto temp;
    int i = 0;

    while(fscanf(fp, "%s%s%d", temp.cf_cliente, temp.codice, &temp.quantita) != EOF ){
        (*dim)++;
        va[i] = temp;
        i++;
    }
    fclose(fp);
    return res;  
}

void stampaAcquisto (Acquisto a){

    FILE *fp = fopen("acquisti.txt", "r");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire %s\n", "acquisti.txt");
            exit(1);
            }

    Acquisto temp;

    while(fscanf(fp, "%s%s%d", temp.cf_cliente, temp.codice, &temp.quantita) != EOF ){
        if (strcmp(temp.codice,a.codice) == 0){
            printf("CF Cliente -> %s\n", temp.cf_cliente);
            printf("Codice Pep -> %s\n", temp.codice);
            printf("quantita Pep -> %d\n", temp.quantita);
        }
        
    }
    fclose(fp);
}

int cercaPeperoncino (Peperoncino p[], int dim, char* codice){

    int res = 0;
    int posPep = 0;
    for (int i = 0; i < dim; i++){
        if (strcmp(p[i].codice, codice) == 0){
            posPep = i+1;
        }
    }
    if (posPep != 0){
        printf("Posizione peperoncino = %d\n", posPep);
        res = 1;
    }else{
        res = -1;
    }
    return res;
}

float totaleScontrino(Acquisto a[], int dimA, Peperoncino p[], int dimP, char *cf){

    float prezzoProdotto = 0; 
    float scontrinoFinale = 0; 
    float sconto = 0.05;
    float prezzoScontato = 0;

    // for (int d = 0; d < dimA; d++){
    //     printf("%s\n", a[d].cf_cliente);
    // }

    for (int i = 0; i < dimA; i++){

        if(strcmp(a[i].cf_cliente,cf) == 0){

            for (int k = 0; k < dimP; k++){

                if (strcmp(a[i].codice,p[k].codice)==0){

                    if (p[k].valore > 100000){
                        prezzoScontato = ((p[k].prezzo*a[i].quantita)*sconto);
                        prezzoProdotto = (p[k].prezzo*a[i].quantita)-prezzoScontato;

                        scontrinoFinale = scontrinoFinale + prezzoProdotto;
                    }else{
                        prezzoProdotto = ((p[k].prezzo) * (a[i].quantita));
                        printf("prezzo Pep -> %.3f - Quantita -> %d = Importo -> %.3f\n", p[k].prezzo, a[i].quantita, prezzoProdotto);
                        scontrinoFinale = scontrinoFinale + prezzoProdotto;
                    }
                    p[k].quantita = p[k].quantita - a[i].quantita;
                }
            }
        }
    }
    return scontrinoFinale;

}