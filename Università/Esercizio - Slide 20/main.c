#include "manager.h"
#include "manager.c"
#include "function.h"
#include "function.c"

int main(){
// PARTE 1
printf("---PARTE 1---\n");

int dimC;
Condominio *c = readcondomini("condomini.txt", &dimC);

// for (int i = 0; i < dimC; i++){
//     printf("Codice %d - %d - %s - %d\n", c[i].codice_condominio, c[i].CAP, c[i].via_residenza, c[i].numero_civico);
// }



int dimA;
ComA *a = readComA("comunicazioni.txt", &dimA);

// for(int k = 0; k < dimA; k++){
//     printf("Tipologia %c - Codice %d - Comunicazione '%s'\n", a[k].tipologia, a[k].codice_condominio, a[k].comunicazione);
//     }


int dimE;
ComE *e = readComE("comunicazioni.txt", &dimE);

// for (int j = 0; j < dimE; j++){
//     printf("Tipologia %c - Codice %d - importo %d - Descrizione %s\n",
//     e[j].tipologia, e[j].codice_condominio, e[j].importo_monetario, e[j].descrizione);
//     }

//PARTE 2
printf("---PARTE 2---\n");
// ComE *res = stampaCondominio(c,dimC,a,dimA,e,dimE);

// for (int l = 0; l < dimE; l++){
//     printf("Pos.[%d]- Cod.App. %d - Costi %d - descrizione %s - Anno %d - Mese %d - Giorno %d\n", l, res[l].codice_condominio,
//     res[l].importo_monetario, res[l].descrizione, res[l].anno, res[l].mese, res[l].giorno);
// }

//PARTE 3 
printf("---PARTE 3---\n");

int cod;

// printf("Digitare codice Appartamento = ");
// scanf("%d",&cod);

// double somma_Spese = sommaSpese(cod, e, dimE);

// printf("Somma Spese Tassate = %.3f\n", somma_Spese);

//PARTE 4
printf("---PARTE 4---\n");

char newCom;

printf("Che tipo di Comunicazione si vuole inserire ? ");
scanf("%c", &newCom);

insert("comunicazioni.txt", newCom);

free(c);
free(a);
free(e);

}