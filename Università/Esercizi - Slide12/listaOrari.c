#include<stdio.h>
#include<string.h>

typedef struct {
    int ore;
    int minuti;
}orario;

void leggi_orario(orario *o){
    printf("Indicare Ora hh =>");
    scanf("%d", &o->ore, &o->minuti);

    printf("Indicare minuti mm =>");
    scanf("%d", &o->minuti);
}

void stampa_orario(orario o){
    printf("Sono le %d:%d", o.ore, o.minuti);
}

int confronta_orario(orario o1, orario o2){

    if(o1.ore == o2.ore && o1.minuti == o2.minuti){             // nelle condizione degli if devo andare a leggere all'interno delle celle di memoria !!
        printf("sono gli stessi orari");

            }else if(o1.ore < o2.ore ){
                printf("o1 precede o2");

                    }else if(o1.ore > o2.ore){
                        printf("o2 precede o1");
                        }           
}



int main(){

    int n=0;

    orario o1, o2;

    int array[n];

    leggi_orario(&o1);
    leggi_orario(&o2);

    confronta_orario(o1, o2);

    if(&o1 != &o2){
        for(int j=0; )
        array[0] = &o1;
        array[0] = &o1;

    }
    //stampa_orario(o1);

}