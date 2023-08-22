#include "function.h"

double sommaSpese(int codice,  ComE *e, int dimE){
    float tax_min = 0.1;
    float tax_max = 0.12;
    int importo_lordo = 0;
    int count = 0;
    double media;
    double res;

    for (int i = 0; i < dimE; i++){
        if (codice == e[i].codice_condominio){
            importo_lordo = importo_lordo + e[i].importo_monetario;
            count++;
        }
    }
    if (importo_lordo < 5000){
        res = (importo_lordo - (importo_lordo*tax_min));
    }
    if (importo_lordo >= 5000){
        res = (importo_lordo - (importo_lordo*tax_max));
    }
    media = (res/count);
    printf("Spese Medie Nette = %.3f\n", media);

    return res;
}

void insert(char* fileName, char type){

    if (type == 'A'){
        ComA newA;
        printf("Codice Condominio = ");
        scanf("%d", &newA.codice_condominio);

        printf("Descrizione comunicazione = ");
        scanf("%s", &newA.comunicazione);

        newA.tipologia = type;

        FILE *fp = fopen(fileName, "a");
            if(fp == NULL){
                fprintf(stderr, "Impossibile aprire %s\n", fileName);
                exit(1);
            }
        
        fprintf(fp,"%c %d %s\n", newA.tipologia, newA.codice_condominio, newA.comunicazione);
        fclose(fp);
    }
    
    if (type == 'E'){

        ComE newE, tempE;
        char tempChar;

        int sameData = 0, sameDescription = 0;

        printf("Codice Condominio = ");
        scanf("%d", &newE.codice_condominio);

        printf("Descrizione comunicazione = ");
        scanf("%s", &newE.descrizione);

        printf("Inserisci Importo = ");
        scanf("%d", &newE.importo_monetario);

        printf("Inserisci Data = ");
        scanf("%d/%d/%d", &newE.giorno, &newE.mese, &newE.anno);

        FILE *fp = fopen(fileName, "r");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire %s\n", fileName);
            exit(1);
            }

        //printf("sono in lettura\n");
        
        int dim = 0;
        
        while (fscanf(fp,"%c", &tempChar) != EOF ){
            if ((int)tempChar == 'E'){
                dim++;
                //printf("%d\n", dim);
                }
        }
        ComE *resE = (ComE*) malloc((dim)*sizeof(ComE));
        rewind(fp);
        int i = 0;
        
        while (fscanf(fp,"%c", &tempChar) != EOF ){
            
            if ((int)tempChar == 'E'){
                tempE.tipologia = tempChar;
                fscanf(fp, "%d%d%s%d%d%d", &tempE.codice_condominio, &tempE.importo_monetario,
                                            tempE.descrizione, &tempE.anno, &tempE.mese,
                                            &tempE.giorno);
                resE[i] = tempE;
                i++;
                //printf("%d\n", i);
            }
            
        }
        /* chiudo il file */
        fclose(fp);
        //printf("sto arrivando\n");

        for (int k = 0; k < dim; k++){
            if (resE[k].anno == newE.anno && resE[k].mese == newE.mese && resE[k].giorno == newE.giorno){
                sameData = 1;
            }
            if (strcmp(resE[k].descrizione,newE.descrizione)==0){
                sameDescription = 1;
            }
        }
        
        if (sameData == 1 || sameDescription == 1){

            printf("impossibile inserire comunicazione\n");

        }else if(sameData == 0 && sameDescription == 0){

            FILE *fp1 = fopen(fileName, "a");
            if(fp == NULL){
            fprintf(stderr, "Impossibile aprire %s\n", fileName);
            exit(1);
            }

        newE.tipologia = type;

        fprintf(fp1, "%c %d %d %s %d %d %d\n", newE.tipologia, newE.codice_condominio, newE.importo_monetario,
                                            newE.descrizione, newE.anno, newE.mese, newE.giorno);
        fclose(fp1);
        }
    }

    if (type != 'A' && type != 'E'){
        printf("Comunicazione non accettata");
    }

}
