#include "somma_orari.h"

void leggi_orario(orario *s){

    printf("Indicare Orario (24h) hh : mm =>");
    scanf("%d : %d", &s->ore, &s->minuti);

    if (s->ore > 24 || s->ore < 0 || s->minuti > 60 || s->minuti < 0){
        printf("Orario non valido\n");
    }else{
        //printf("%d:%d\n", s->ore, s->minuti);
    }  
}

orario somma_orari(orario o1, orario o2){

    orario oSom;

    if (o1.ore == 24){
        o1.ore = 0; 
    }
    if (o2.ore == 24){
        o2.ore = 0; 
    }

    if (o1.minuti == 60){
        o1.minuti = 0; 
    }
    if (o2.minuti == 60){
        o2.minuti = 0; 
    }

    if (o1.ore + o2.ore > 23){

        if (o1.ore + o2.ore == 24){
            oSom.ore = 0;
        }else if (o1.ore >= o2.ore ){
            oSom.ore = o1.ore - o2.ore;
        }else{
            oSom.ore = o2.ore - o1.ore;
        }
         
    }else{
        oSom.ore = o1.ore + o2.ore;
    }

    if (o1.minuti + o2.minuti > 59){
        oSom.ore = oSom.ore + 1;

        if(oSom.ore == 24){
            oSom.ore = 0;
        }

        if (o1.minuti + o2.minuti == 60){
            oSom.minuti=0;
        }else if (o1.minuti >= o2.minuti ){
            oSom.minuti = o1.minuti - o2.minuti;
        }else{
            oSom.minuti = o2.minuti - o1.minuti;
        }
         
    }else{
        oSom.minuti = o1.minuti + o2.minuti;
    }

    return oSom;    
}