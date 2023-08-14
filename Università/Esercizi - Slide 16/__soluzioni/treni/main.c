#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main()
{
    FILE* fp;
    int departingTrains=0, arrivingTrains=0;
    char departure[MAX_LENGTH+1], arrival[MAX_LENGTH+1];
    char fileName[MAX_LENGTH+1], city[MAX_LENGTH+1];

    printf("Insert the file name: ");
    scanf("%s", fileName);

    fp=fopen(fileName,"r");
    if(fp==NULL)
    {
        printf("Error opening the file!\n");
        exit(2);
    }

    printf("Insert the city: ");
    scanf("%s", city);
    while(fscanf(fp,"%s %*s %s %*s", departure, arrival) == 2)
    {    
        if(strcmp(departure, city)==0)
            departingTrains++;
        else if(strcmp(arrival, city)==0)
            arrivingTrains++;
    }
    fclose(fp);


    if(departingTrains)
       printf("%d trains depart from %s\n", departingTrains, city);
    else    
       printf("No trains depart from %s\n", city);
    if(arrivingTrains)    
       printf("%d trains arrive to %s\n", arrivingTrains, city);
    else    
       printf("No trains arrive to %s\n", city);
    return 0;
} 
