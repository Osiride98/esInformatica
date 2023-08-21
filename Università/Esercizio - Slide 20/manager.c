#include "manager.h"

Condominio* readcondomini(char* fileName, int *dim){
    //apro il file 
    FILE *fp = fopen(fileName, "r");
        if(fp == NULL) {
            fprintf(stderr, "Impossibile aprire %s\n", fileName);
            exit(1);
            }
    /* conto il numero di elementi da leggere */
    *dim = 0;
    Condominio t;
    while(fscanf(fp, "%d%d%s%d", &t.codice_condominio, &t.CAP, t.via_residenza, &t.numero_civico) == 4) (*dim)++;
    /* alloco il vettore dinamicamente */
    Condominio *res = (Condominio*) malloc((*dim) * sizeof(Condominio));
    rewind(fp);
    for(int i = 0; i < *dim; ++i){
        fscanf(fp, "%d%d%s%d", &res[i].codice_condominio, &res[i].CAP, res[i].via_residenza, &res[i].numero_civico);
    }
    /* chiudo il file */
    fclose(fp);
    return res;
}

ComA* readComA(char* fileName, int *dim){

    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", fileName);
        exit(1);
        }
    
    *dim = 0;
    ComA comunicazioneA;
    char temp;
    
    while (fscanf(fp,"%c", &temp) != EOF ){
        if ((int)temp == 'A'){
            (*dim)++;
            }
    }
    (*dim)--;       //FINIRE DI RISOLVERE PROBLEMA SU PUNTATORE DIMENSIONE
    ComA *resA = (ComA*) malloc((*dim)*sizeof(ComA));
    rewind(fp);
    int i = 0;
    
    while (fscanf(fp,"%c", &temp) != EOF ){
        if ((int)temp == 'A'){
            
            comunicazioneA.tipologia = temp;
            fscanf(fp, "%d%s", &comunicazioneA.codice_condominio, comunicazioneA.comunicazione);
            resA[i] = comunicazioneA;
            i++;
        }
        
    }
    /* chiudo il file */
    fclose(fp);
    return resA;
}

ComE* readComE(char* fileName, int *dim){

    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", fileName);
        exit(1);
        }
    
    *dim = 0;
    ComE comunicazioneE;
    char temp;
    
    while (fscanf(fp,"%c", &temp) != EOF ){
        if ((int)temp == 'E'){
            (*dim)++;
            }
    }
    ComE *resE = (ComE*) malloc((*dim)*sizeof(ComE));
    rewind(fp);
    int i = 0;
    
    while (fscanf(fp,"%c", &temp) != EOF ){
        
        if ((int)temp == 'E'){
            comunicazioneE.tipologia = temp;
            fscanf(fp, "%d%d%s%d%d%d", &comunicazioneE.codice_condominio, &comunicazioneE.importo_monetario,
                                        comunicazioneE.descrizione, &comunicazioneE.anno, &comunicazioneE.mese,
                                        &comunicazioneE.giorno);
            resE[i] = comunicazioneE;
            i++;
        }
        
    }
    /* chiudo il file */
    fclose(fp);
    return resE;

}

void swap(ComE *a, ComE *b){
    ComE t = *a;
    *a = *b;
    *b = t;
}

int bubble_sort(ComE v[], int n){
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
            if(v[j].anno > v[j+1].anno) {
                swap(&v[j], &v[j+1]);
                ordinato = 0;
            }
            if(v[j].anno == v[j+1].anno && v[j].mese > v[j+1].mese){
                swap(&v[j], &v[j+1]);
                ordinato = 0;
            }
            if(v[j].anno == v[j+1].anno && v[j].mese == v[j+1].mese && v[j].giorno > v[j+1].giorno){
                swap(&v[j], &v[j+1]);
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

ComE* stampaCondominio(Condominio *c, int dimC, ComA *a, int dimA, ComE *e, int dimE){
    Condominio appartment;
    int presenza_condomionio = 0;

    printf("Digitare codice Appartamento = ");
    scanf("%d", &appartment.codice_condominio);

    for (int i = 0; i < dimC; i++){
        if (appartment.codice_condominio == c[i].codice_condominio){
            presenza_condomionio = 1;
            printf("Cond_Codice -> %d\n", c[i].codice_condominio);
            printf("Cond_CAP-> %d\n", c[i].CAP);
            printf("Cond_Via -> %s\n", c[i].via_residenza);
            printf("Cond_CAP-> %d\n", c[i].numero_civico);
        }
    }
    if (presenza_condomionio==0){
        printf("Condominio non presente\n");
    }
    
    if (presenza_condomionio==1){
            for (int k = 0; k < dimA; k++){
                if (appartment.codice_condominio == a[k].codice_condominio ){
                    printf("Comunicazioni Generali = %s\n", a[k].comunicazione);
                }
            }
            int cambi = bubble_sort(e, dimE);
            for (int j = 0; j < dimE; j++){
                if (appartment.codice_condominio == e[j].codice_condominio){
                    printf("Att.[%d] - Costi %d - descrizione %s - Anno %d - Mese %d\n", j, e[j].importo_monetario, e[j].descrizione,
                                                                                        e[j].anno, e[j].mese);
                }
                
            }
            
    }

return e;
}
