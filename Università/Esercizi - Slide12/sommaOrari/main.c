#include<stdio.h>
#include<string.h>

typedef struct {
    int ore;
    int minuti;
}orario;

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

int main() {

//PARTE 1

printf("---PARTE 1---\n");

orario s;

leggi_orario(&s);

// PARTE 2

printf("---PARTE 2---\n");

orario o1, o2, oRis;

leggi_orario(&o1);
leggi_orario(&o2);

oRis = somma_orari(o1, o2);

printf("Somma Orari -> %d : %d ", oRis.ore, oRis.minuti);

// PARTE 3

printf("---PARTE 3---\n");

orario o, oRis;
orario arrayOrario[2];

oRis.ore = 0;
oRis.minuti = 0;

for (int i = 0; i <= 2; i++){

    leggi_orario(&o);
    arrayOrario[i] = o;
}

// printf("Orario Ris Fuori -> %d : %d \n", oRis.ore, oRis.minuti);

for (int j = 0; j < 2; j++){

    // printf("Orario Ris Prima -> %d : %d \n", oRis.ore, oRis.minuti);

    oRis = somma_orari(oRis, arrayOrario[j]);

    // printf("Somma Orari Dopo-> %d : %d \n", oRis.ore, oRis.minuti);
}

printf("Somma Orari -> %d : %d ", oRis.ore, oRis.minuti);

}
