//
// Created by Bori on 12/18/2019.
//

#include "foodType.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataProcessing.h"

#define MAX_LINE_LENGTH 200

void createFoodType(foodType* newFoodType)
{
    newFoodType->name = (char*) malloc(sizeof(char)*MAX_FOODTYPE_LENGTH);

}

void setSpecFoodsNr(foodType* myFoodType, int nr)
{
    myFoodType->specFoodNr = nr;
    myFoodType->specFoods = (specFood*) malloc(myFoodType->specFoodNr* sizeof(specFood));
    for(int i=0; i<myFoodType->specFoodNr; i++)
    {
        createSpecFood(&myFoodType->specFoods[i]);
    }
}

void destroyFoodType(foodType* myFoodType)
{
    free(myFoodType->name);
    for(int i=0; i<myFoodType->specFoodNr; i++)
    {
        destroySpecFood(&myFoodType->specFoods[i]);
    }
}

void splitIntoPartsSpecFoodLine(foodType* myFoodType, char line[])
{
    char* c;
    char line2[MAX_LINE_LENGTH]=" "; //to make the string uniform, I append a ' ' to it at the beginning, and then I extract all the spaces with the strtok
    strcat(line2, line);
    c = strtok(line2, "(");
    int index=0;
    while ((c=strtok(NULL, ")"))!= NULL)
    {
        processingNameAndPrice(myFoodType->specFoods[index].name, &myFoodType->specFoods[index].price, c);
        c=strtok(NULL, "(");
        index++;
    }
}

void displaySpecFoodOptions(foodType myFoodType)
{
    printf("Please choose the type of %s\n", myFoodType.name);
    for (int i = 0; i <=myFoodType.specFoodNr-1; i++) {
        putchar('a' + i);
        printf(") %s %.2lf\n", myFoodType.specFoods[i].name, myFoodType.specFoods[i].price);
    }
    printf("%c) go back\n", (char)'a'+myFoodType.specFoodNr);
}

