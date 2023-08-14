#include "colori.h"

void leggi_colori(char *nome_file,ColoreCSS *lcss, int *ncss,ColoreRGB *lrgb, int *nrgb){

    char formato;
    char esaColor[45];
    int k=0;
    char formatoColore;

    ColoreCSS cssForm;
    ColoreRGB rgbForm;

    FILE *fp;

    if((fp = fopen("colori.txt", "r")) == NULL) {
        fprintf(stderr, "Impossibile aprire %s\n", nome_file);
        exit(1);
        }else{
            printf("ci ste brev\n");
            }

    while(fscanf(fp, "%c", &formato) == 1) {
        if((int)formato != 10){         // operazione di cast su "formato" che se diverso da 10 (tabella ASCII)
                                        // salvo "formato" in array "esaColor[k]"
                                        // 10 (tabella ASCII) == line feed (avanzamento riga)

            esaColor[k] = formato;  // inizio lettura file leggo un numero che lo salvo in variabile "formato"
            k++;        // incremento valore di k
        }else{
            formatoColore = esaColor[0];   //se "formato" == "line feed"  "formatoColore" = esaColor[0]
            printf("%c\n", formatoColore);
            
            k=0;
        }    
    }
    //printf("%c\n", esaColor[0]);
    fclose(fp);
}