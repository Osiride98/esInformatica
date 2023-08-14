#include "colori.h"

void leggi_colori(char *nome_file,ColoreCSS *lcss, int *ncss,ColoreRGB *lrgb, int *nrgb){
    int i = 0;
    int k = 0;
    char formatoColore;

    int cssCount = 0;
    int rgbCount = 0;
    FILE *fp;

    if((fp = fopen("colori.txt", "r")) == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nome_file);
        exit(1);
        }else{
            printf("ci ste brev\n");
        }

    while (fscanf(fp,"%c", &formatoColore) != EOF){

        if((int)formatoColore == 48){
            lcss[i].formato = 0;
            fgets(lcss[i].cssColour, 10, fp);
            i++;
            cssCount++;
        }
        if((int)formatoColore == 49){
            lrgb[k].formato = 1;
            fgets(lrgb[k].rgbColor, 13, fp);
            k++;
            rgbCount++;
        }
    }
    
    fclose(fp);
    *ncss = cssCount;
    *nrgb = rgbCount;
}

void stampa_colori(ColoreCSS *lcss, int ncss, ColoreRGB *lrgb, int nrgb){
    for (int i = 0; i < ncss; i++){
        printf("Colore %d : formato %d - colore %s", i, lcss[i].formato, lcss[i].cssColour);
    }
    printf("dimensione logica nCSS -> %d\n", ncss);

    for (int j = 0; j < nrgb; j++){
        printf("Colore %d : formato %d - colore %s\n", j, lrgb[j].formato, lrgb[j].rgbColor);
    }
    printf("dimensione logica nRGB -> %d\n", nrgb);
    
}