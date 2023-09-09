Animale * leggiAnimali (char * nomefile, int * dimAnimali){

    //apro il file 
    FILE *fp = fopen(nomefile, "r");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire %s\n", nomefile);
            exit(1);
            }
    /* conto il numero di elementi da leggere */
    *dimAnimali = 0;
    
    Animale t;
    char temp[2];

    while(fscanf(fp, "%s %s %c", t.codice, t.razza, temp) == 3) (*dimAnimali)++;
    /* alloco il vettore dinamicamente */
    Animale *res = (Animale*) malloc((*dimAnimali) * sizeof(Animale));

    rewind(fp);

    for(int i = 0; i < *dimAnimali; ++i){
        fscanf(fp, "%s %s %c", res[i].codice, res[i].razza, temp);
        res[i].produzione = temp[0];
    }
    /* chiudo il file */
    fclose(fp);
    return res;
}  

void stampaAnimale (Animale a){
    FILE *fp = fopen("animali.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", "animali.txt");
        exit(1);
        }
    Animale temp;
    char prodTemp[2];

    while(fscanf(fp, "%s %s %c", temp.codice, temp.razza, prodTemp) != EOF ){
        temp.produzione = prodTemp[0];
        if (strcmp(temp.codice, a.codice) == 0){
            printf("Codice Animale -> %s\n", temp.codice);
            printf("Razza -> %s\n", temp.razza);
            printf("Produzione -> %c\n", temp.produzione);
        }
    
    }
    fclose(fp);
}

Razza * leggiRazze (char * nomefile, int * dimRazze){
    //apro il file 
    FILE *fp = fopen(nomefile, "r");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire %s\n", nomefile);
            exit(1);
            }
    /* conto il numero di elementi da leggere */
    *dimRazze = 0;

    Razza t;

    while(fscanf(fp, "%s%d%f%d", t.razza, &t.peso, &t.litri, &t.alta_qualita ) == 4) (*dimRazze)++;
    /* alloco il vettore dinamicamente */
    Razza *res = (Razza*) malloc((*dimRazze) * sizeof(Razza));
    rewind(fp);
    for(int i = 0; i < *dimRazze; ++i){
        fscanf(fp, "%s%d%f%d", res[i].razza, &res[i].peso, &res[i].litri, &res[i].alta_qualita);
    }
    /* chiudo il file */
    fclose(fp);
    return res;
}

void stampaRazza (Razza r){
    FILE *fp = fopen("razze.txt", "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", "razze.txt");
        exit(1);
        }
    Razza temp;

    while(fscanf(fp, "%s%d%f%d", temp.razza, &temp.peso, &temp.litri, &temp.alta_qualita) != EOF ){
        if (strcmp(temp.razza, r.razza) == 0){
            printf("Razza Animale -> %s\n", temp.razza);
            printf("Peso Animale -> %d\n", temp.peso);
            printf("Litri -> %.3f\n", temp.litri);
            printf("Qualita -> %d\n", temp.alta_qualita);
        }
    
    }
    fclose(fp);
}

float calcolaLitri(Animale a, Razza * r, int dimR){
    printf("%s\n", a.codice);

    float sommaLitri = 0;

    for (int i = 0; i < dimR; i++){

        if (strcmp(a.razza, r[i].razza) == 0){

            printf("Produzione a pieno regime = %.3f\n", r[i].litri);

            sommaLitri = sommaLitri + r[i].litri;

            if ((int)a.produzione == 'a'){
                sommaLitri = 0;
            }
            
            if ((int)a.produzione == 'b'){
                sommaLitri = (sommaLitri/2);
            }
        }
    }
    return sommaLitri;
}

float calcolaRicavo(Animale * a, int dimA, Razza * r, int dimR,
    float prezzo, float prezzoAQ){

        float tempRicavi = 0;
        float tempLitri = 0;
        float tempTot = 0;

        for (int i = 0; i < dimA; i++){

            if ((int)a[i].produzione == 'b' || (int)a[i].produzione == 'c'){

                for (int k = 0; k < dimR; k++){

                    if (strcmp(a[i].razza, r[k].razza) == 0){

                        if ((int)a[i].produzione == 'b'){

                            tempLitri = ((r[k].litri)/2);

                            if (r[k].alta_qualita == 1){

                                tempRicavi = tempLitri*prezzoAQ;

                                tempTot = tempTot+tempRicavi;
                        
                            }else if (r[k].alta_qualita == 0){

                                tempRicavi = tempLitri*prezzo;

                                tempTot = tempTot+tempRicavi;                       
                            }
                        }
                        if ((int)a[i].produzione == 'c'){

                            tempLitri = r[k].litri;

                            if (r[k].alta_qualita == 1){

                                tempRicavi = tempLitri*prezzoAQ;

                                tempTot = tempTot+tempRicavi;

                            }else if (r[k].alta_qualita == 0){

                                tempRicavi = tempLitri*prezzo;

                                tempTot = tempTot+tempRicavi;
                            }
                        }
                    } 
                }
            }
        }
        return tempTot;
}

void swap(Razza *a, Razza *b){
    Razza t = *a;
    *a = *b;
    *b = t;
}

int bubble_sort(Razza a[], int n){
    /* Effettuo varie "passate" */
    int i, j;
    int cnt = 0;
    int ordinato;
    for(i = n; i > 1; --i) {    
        /* all'inizio ipotizzo che l'array sia ordinato */
        ordinato = 1;
        /* Ad ogni "passata" considero le coppie adiacenti */
        for(j = 0; j < i-1; ++j) {
            /* se l'ordine è invertito, scambio */
            if(a[j].peso < a[j+1].peso) {
                swap(&a[j], &a[j+1]);
                ordinato = 0;
            }
            /* un confronto in più */
            cnt++;
        }
        /* se l'array era veramente ordinato, posso interrompere */
        if(ordinato) break;
    }
    /* restituisco il numero di confronti */
    return cnt;
}


void ordina (Razza* a, int dim){
    int scambi = bubble_sort(a, dim);
}