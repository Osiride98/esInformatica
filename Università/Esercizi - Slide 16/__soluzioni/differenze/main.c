#include <stdio.h>

int main() {
    FILE *fpin, *fpout;
    int x,y;
    /* apertura del primo file */
    if ((fpin = fopen("estremi.txt","r")) == NULL) {
        fprintf(stderr,"Errore nell’apertura\n");
        return 1;
    }
    /* apertura del secondo file */
    if ((fpout = fopen("diff.txt","w")) == NULL) {
        fprintf(stderr,"Errore nell’apertura\n");
        return 1;
    }
    /* input */
    while (fscanf(fpin,"%d %d",&x,&y) != EOF) {
        /* ora ho a disposizione x e y */
        fprintf(fpout,"%d\n",x-y);
    }
    fclose(fpin);
    fclose (fpout);
    return 0;
}
