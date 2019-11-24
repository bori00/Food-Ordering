//
// Created by Bori on 11/3/2019->
//

#include <string.h>
#include <stdlib.h>
#include "menu.h"
#include <stdio.h>
#include "dataProcessing.h"


#define LOAD_DATA "Please load the data"
#define MAX_LINE_LENGTH 200

void allocateMemoryForStrings(menu* myMenu)
{
    for(int i=0; i<MAX_FOODTYPES_NR; i++)
    {
        myMenu->foodTypes[i] = (char*) malloc(MAX_STRING_LENGTH* sizeof(char));
        for(int j=0; j<=MAX_SPECFOOD_NR; j++)
        {
            myMenu->specFoods[i][j]=(char*) malloc(MAX_STRING_LENGTH* sizeof(char));
        }
    }
    for(int i=0; i<MAX_DRINKS_NR; i++)
    {
        myMenu->drinks[i] = (char*) malloc(MAX_STRING_LENGTH* sizeof(char));
    }
}

void freeMemoryForStrings(menu* myMenu)
{
    for(int i=0; i<MAX_FOODTYPES_NR; i++)
    {
        myMenu->foodTypes[i] = (char*) malloc(MAX_STRING_LENGTH* sizeof(char));
        for(int j=0; j<=MAX_SPECFOOD_NR; j++)
        {
            free(myMenu->specFoods[i][j]);
        }
    }
    for(int i=0; i<MAX_DRINKS_NR; i++)
    {
        free(myMenu->drinks[i]);
    }
}

void readFoodData(FILE* menuFile, menu* myMenu)
{
    if(menuFile==stdin) printf(">");
    fscanf(menuFile, "%d", &myMenu->foodTypeNr);
    char* c, endl,  thisFoodTypeData[MAX_LINE_LENGTH];
    while((endl=fgetc(menuFile))!='\n' && endl!=EOF);
    for(int i=0; i<myMenu->foodTypeNr; i++) {
        if(menuFile==stdin) printf(">");
        fgets(thisFoodTypeData, MAX_LINE_LENGTH, menuFile);
        extractStringUntilChar(myMenu->foodTypes[i], thisFoodTypeData, ':');
        myMenu->specFoodNr[i]=0;
        splitIntoParts(thisFoodTypeData, myMenu->specFoods[i], myMenu->specFoodsPrice[i], &myMenu->specFoodNr[i]);
    }
}

void readDrinkData(FILE* menuFile, menu* myMenu)
{
    if(menuFile==stdin) printf(">");
    fscanf(menuFile, "%d", &myMenu->drinkNr);
    if(menuFile==stdin) printf(">");
    char* c, endl,  thisFoodTypeData[MAX_LINE_LENGTH];
    while((endl=fgetc(menuFile))!='\n' && endl!=EOF);
    char drinksData[MAX_LINE_LENGTH];
    fgets(drinksData, MAX_LINE_LENGTH, menuFile);
    splitIntoParts(drinksData, myMenu->drinks, myMenu->drinksPrice, &myMenu->drinkNr);
}

void saveFoodsDataToFile(char* fileName, menu* myMenu)
{
    FILE * menuFile;
    menuFile = fopen (fileName,"w");
    fprintf(menuFile, "%d:\n", myMenu->foodTypeNr);
    for(int i=0; i<myMenu->foodTypeNr; i++)
    {
        fprintf(menuFile, "%s: ", myMenu->foodTypes[i]);
        for(int j=0; j<myMenu->specFoodNr[i]; j++)
        {
            fprintf(menuFile, "(%s - %.2lf) ", myMenu->specFoods[i][j], myMenu->specFoodsPrice[i][j]);
        }
        fprintf(menuFile, "\n");
    }
}

void saveDrinksDataToFile(char* fileName, menu* myMenu)
{
    FILE * menuFile;
    menuFile = fopen (fileName,"a");
    fprintf(menuFile, "%d:\n", myMenu->drinkNr);
    for(int i=0; i<myMenu->drinkNr; i++)
    {
        fprintf(menuFile, "(%s - %.2lf)", myMenu->drinks[i], myMenu->drinksPrice[i]);
        if(i+1<myMenu->drinkNr) fprintf(menuFile, ", ");
    }
    fprintf(menuFile, "\n");
}

void loadDataToMenu(menu *myMenu)
{
    FILE * menuFile;
    menuFile = fopen ("data.txt","r");
    if(menuFile==NULL) menuFile=stdin;
    if(menuFile==stdin) printf("%s\n", LOAD_DATA);
    allocateMemoryForStrings(myMenu);
    readFoodData(menuFile, myMenu);
    readDrinkData(menuFile, myMenu);
    if(menuFile==stdin){
        saveFoodsDataToFile("data.txt", myMenu);
        saveDrinksDataToFile("data.txt", myMenu);
        menuFile = fopen ("data.txt","r");
    }
    fclose(menuFile);
}

