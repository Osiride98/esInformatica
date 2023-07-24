#include "compagnia_navi.h"

nave* leggi_navi(char *nomefile, int *num_n){
    int count, i;
    FILE *fp;
    nave *res, temp;

    if ((fp = fopen(nomefile, "r")) == NULL){
        printf("Impossibile aprire il file partenze.txt");
        exit(1);
    }
    count = 0;
    while (fscanf(fp, "%s %c", temp.codice_nave, &(temp.tipo)) == 2)
        count++;
    rewind(fp);
    res = (nave*)malloc((size_t)count * sizeof(nave));
    for (i = 0; i < count; i++)
        fscanf(fp, "%s %c", res[i].codice_nave, &(res[i].tipo));

    fclose(fp);
    *num_n= count;
    return res;
}

void stampa_nave(nave n){
    printf("Nave: codice %s\t Tipo: %c\n", n.codice_nave, n.tipo);

}

partenza* leggi_partenze(char *nomefile, int *num_p){
    int count, i;
    FILE *fp;
    partenza *res, temp;

    if ((fp = fopen(nomefile, "r")) == NULL){
        printf("Impossibile aprire il file partenze.txt");
        exit(1);
    }
    count = 0;
    while (fscanf(fp, "%d %s %s %s %d %d",
                  &(temp.id_viaggio), temp.partenza, temp.arrivo,
                  temp.codice_nave, &(temp.orario), &(temp.ritardo)) == 6)
        count++;
    rewind(fp);
    res = (partenza*)malloc((size_t)count * sizeof(partenza));
    for (i = 0; i < count; i++)
        fscanf(fp, "%d %s %s %s %d %d",
                &(res[i].id_viaggio), res[i].partenza, res[i].arrivo,
                res[i].codice_nave, &(res[i].orario), &(res[i].ritardo));

    fclose(fp);
    *num_p = count;
    return res;
}

void stampa_partenza(partenza p){
    printf("Tratta: id %d\t Partenza %s\t Arrivo %s\t Nave %s\t Orario %d\t Ritardo %d\t\n",
            p.id_viaggio, p.partenza, p.arrivo, p.codice_nave, p.orario, p.ritardo);
}

int trova_nave(char *codice, nave* n, int num_n){
    int i;
    for(i = 0; i <  num_n; i++)
        if(!strcmp(codice, n[i].codice_nave))
            return 1;
    return 0;
}

int nuova_partenza(FILE *fp, nave *n, int num_n){
    int res, nave_ok;
    partenza p;

    printf("Inserimento nuova tratta\n");
    printf("Id viaggio?\t");
    scanf("%d", &(p.id_viaggio));
    printf("Partenza?\t");
    scanf("%s", p.partenza);
    printf("Arrivo?\t");
    scanf("%s", p.arrivo);
    printf("Codice nave?\t");
    scanf("%s", p.codice_nave);
    printf("Orario?\t");
    scanf("%d", &(p.orario));
    printf("Ritardo?\t");
    scanf("%d", &(p.ritardo));

    nave_ok = trova_nave(p.codice_nave, n, num_n);
    if(!nave_ok)
        return -1;

    res = fprintf(fp, "%d %s %s %s %d %d", p.id_viaggio, p.partenza, p.arrivo, 
            p.codice_nave, p.orario, p.ritardo);
    if(res > 0)
        return 1;
    else
        return 0;
}

void scambia(partenza *a, partenza *b)
{
    partenza temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void ordina_partenze(partenza * p,int num_p)
{
    // bubble sort
    int i;
    int ordinato = 0;
    while (num_p > 1 && ordinato == 0)
    {
        ordinato = 1;
        for (i = 0; i < num_p - 1; i++)
        {
            if ((p[i].orario + p[i].ritardo) > (p[i+1].orario + p[i+1].ritardo))
            {
                scambia(&p[i], &p[i+1]);
                ordinato = 0;
            }
        }
        num_p--;
    }
}
