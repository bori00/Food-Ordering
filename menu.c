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

void allocateMemoryFodFoods(menu *myMenu)
{
    myMenu->foodTypes = (char**) malloc(sizeof(char*)*myMenu->foodTypeNr);
    myMenu->specFoodNr = (int*) malloc(sizeof(int)*myMenu->foodTypeNr);
    myMenu->specFoods = (char***) malloc(sizeof(char**)*myMenu->foodTypeNr);
    myMenu->specFoodsPrice = (double**) malloc(sizeof(double*)*myMenu->foodTypeNr);
    for(int i=0; i<myMenu->foodTypeNr; i++){
        myMenu->foodTypes[i] = (char*) malloc(sizeof(char)*MAX_STRING_LENGTH);
        myMenu->specFoods[i] = (char**) malloc(sizeof(char*)*MAX_SPECFOOD_NR);
        myMenu->specFoodsPrice[i] = (double*) malloc(sizeof(double)*MAX_SPECFOOD_NR);
        for(int j=0; j<MAX_SPECFOOD_NR; j++){
            myMenu->specFoods[i][j] = (char*) malloc(sizeof(char)*MAX_STRING_LENGTH);
        }
    }
}

void allocateMemoryForDrinks(menu* myMenu)
{
    myMenu->drinks = (char**) malloc(sizeof(char*)*myMenu->drinkNr);
    myMenu->drinksPrice = (double*) malloc(sizeof(double)*myMenu->drinkNr);
    for(int i=0; i<myMenu->drinkNr; i++){
        myMenu->drinks[i] = (char*) malloc(sizeof(char)*MAX_STRING_LENGTH);
    }
}

void freeMemoryFodFoods(menu *myMenu)
{
    for(int i=0; i<myMenu->foodTypeNr; i++){
        for(int j=0; j<MAX_SPECFOOD_NR; j++){
            free(myMenu->specFoods[i][j]);
        }
        free(myMenu->foodTypes[i]);
        free(myMenu->specFoods[i]);
        free(myMenu->specFoodsPrice[i]);
    }
    free(myMenu->foodTypes);
    free(myMenu->specFoodNr);
    free(myMenu->specFoods);
    free(myMenu->specFoodsPrice);
}

void freeMemoryFordDrinks(menu* myMenu)
{
    for(int i=0; i<myMenu->drinkNr; i++){
        free(myMenu->drinks[i]);
    }
    free(myMenu->drinks);
    free(myMenu->drinksPrice);
}

void freeMemoryOfMenu(menu* myMenu)
{
    freeMemoryFodFoods(myMenu);
    freeMemoryFordDrinks(myMenu);
}

void readFoodData(FILE* menuFile, menu* myMenu)
{
    if(menuFile==stdin) printf(">");
    fscanf(menuFile, "%d", &myMenu->foodTypeNr);
    allocateMemoryFodFoods(myMenu);
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
    allocateMemoryForDrinks(myMenu);
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
    readFoodData(menuFile, myMenu);
    readDrinkData(menuFile, myMenu);
    if(menuFile==stdin){
        saveFoodsDataToFile("data.txt", myMenu);
        saveDrinksDataToFile("data.txt", myMenu);
        menuFile = fopen ("data.txt","r");
    }
    fclose(menuFile);
}

