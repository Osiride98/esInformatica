#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define N 128 
#define RRANGE 2048
#define NRUNS 30
#define NSHOW 10

void print_array(int v[], int n) {
    int i;
    for(i = 0; i < n; ++i) {
        if(i > 0) printf(", ");
        /* stampo solo i primi NSHOW elementi */
        if(i < NSHOW)
            printf("%d", v[i]);
        else {
            printf("...");
            break;
        }
    }
    printf("\n");
}

void test_algorithm(char *name) {
    /* fisso il "seme" per il  generatore di numeri casuali */
    srand(42);

    /* Genero un array di partenza */
    int v[N];
    int i;
    int n = RRANGE;
    for(i = 0; i < N; ++i)
        v[i] = rand() % RRANGE;
	//v[i] = n--;
   	
    /* Ordino l'array NRUNS volte con naive sort */
    float sum  = 0;
    for(i = 0; i < NRUNS; ++i) {
        if(strcmp(name, "naive sort") == 0)
            sum += naive_sort(v, N);
        if(strcmp(name, "bubble sort") == 0)
            sum += bubble_sort(v, N);
        if(strcmp(name, "insertion sort") == 0)
            sum += insertion_sort(v, N);
        if(strcmp(name, "merge sort") == 0)
            sum += merge_sort(v, N);
        if(strcmp(name, "quick sort") == 0)
            sum += quick_sort(v, N);
    }
    printf("----------------------------------------\n");
    printf("%s:\n", name);
    printf("- ultimo array ordinato: ");
    print_array(v, N);
    printf("- numero medio di confronti: %.2f\n", sum/NRUNS);
}

int main() {
    /* stampo i valori dei parametri principali */
    printf("========================================\n");
    printf("N: %d, RRANGE: %d, RUNS: %d\n", N, RRANGE, NRUNS);

    /* Provo i vari algoriti */
    test_algorithm("naive sort");
    test_algorithm("bubble sort");
    test_algorithm("insertion sort");
    test_algorithm("merge sort");
    test_algorithm("quick sort");
}
