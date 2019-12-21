//
// Created by Bori on 12/18/2019.
//

#include "drink.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataProcessing.h"

#define MAX_LINE_LENGTH 200

void createDrink(drink* newDrink)
{
    newDrink->name = (char*) malloc(MAX_DRINKNAME* sizeof(char));
}

void destroyDrink(drink* myDrink)
{
    printf("trying to destroy drink\n");
    free(myDrink->name);
    printf("destroyed it\n");
}

void splitIntoPartsDrinksLine(drink drinks[], char line[])
{
    char* c;
    char line2[MAX_LINE_LENGTH]=" "; //to make the string uniform, I append a ' ' to it at the beginning, and then I extract all the spaces with the strtok
    strcat(line2, line);
    c = strtok(line2, "(");
    int index=0;
    while ((c=strtok(NULL, ")"))!= NULL)
    {
        processingNameAndPrice(drinks[index].name,  &drinks[index].price, c);
        c=strtok(NULL, "(");
        index++;
    }
}
