//
// Created by Bori on 11/3/2019->
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "dataProcessing.h"
#include "foodType.h"
#include "drink.h"

#define LOAD_DATA "Please load the data"
#define MAX_LINE_LENGTH 200

void allocateMemoryFodFoodTypes(menu *myMenu)
{
    myMenu->foodTypes = (foodType*) malloc(myMenu->foodTypeNr*sizeof(foodType));
    for(int i=0; i<myMenu->foodTypeNr; i++)
    {
        myMenu->foodTypes[i] = createFoodType();
    }
}

void allocateMemoryForSpecificFood(menu* myMenu, int foodTypeIndex, int nr)
{
    setSpecFoodsNr(&myMenu->foodTypes[foodTypeIndex], nr);
}

void allocateMemoryForDrinks(menu* myMenu)
{
    myMenu->drinks = (drink*) malloc(sizeof(drink)*myMenu->drinkNr);
    for(int i=0; i<myMenu->drinkNr; i++)
    {
        myMenu->drinks[i] = createDrink();
    }
}

void freeMemoryFodFoods(menu *myMenu)
{
    for(int i=0; i<myMenu->foodTypeNr; i++)
    {
        destroyFoodType(&myMenu->foodTypes[i]);
    }
    free(myMenu->foodTypes);
}

void freeMemoryFordDrinks(menu* myMenu)
{
    for(int i=0; i<myMenu->drinkNr; i++){
        destroyDrink(&myMenu->drinks[i]);
    }
    free(myMenu->drinks);
}

void freeMemoryOfMenu(menu* myMenu)
{
    freeMemoryFodFoods(myMenu);
    freeMemoryFordDrinks(myMenu);
}

void readFoodData(FILE* menuFile, menu* myMenu)
{
    printf("I started reading foods data\n");
    if(menuFile==stdin) printf(">");
    fscanf(menuFile, "%d", &myMenu->foodTypeNr);
    allocateMemoryFodFoodTypes(myMenu);
    printf("I allocated memory for types\n");
    char endl,  thisFoodTypeData[MAX_LINE_LENGTH];
    while((endl=fgetc(menuFile))!='\n' && endl!=EOF);
    for(int i=0; i<myMenu->foodTypeNr; i++) {
        if(menuFile==stdin) printf(">");
        fgets(thisFoodTypeData, MAX_LINE_LENGTH, menuFile);
        printf("the new line is%s\n", thisFoodTypeData);
        extractStringUntilChar(myMenu->foodTypes[i].name, thisFoodTypeData, ' ');
        printf("the name of the new foodtype is %s\n", myMenu->foodTypes[i].name);
        sscanf(thisFoodTypeData, "%d", &myMenu->foodTypes[i].specFoodNr);
        allocateMemoryForSpecificFood(myMenu, i, myMenu->foodTypes[i].specFoodNr);
        printf("I allocated memory for spec. food\n");
        splitIntoPartsSpecFoodLine(&myMenu->foodTypes[i], thisFoodTypeData);
    }
}

void readDrinkData(FILE* menuFile, menu* myMenu)
{
    printf("I started reading drinks data\n");
    if(menuFile==stdin) printf(">");
    fscanf(menuFile, "%d", &myMenu->drinkNr);
    allocateMemoryForDrinks(myMenu);
    if(menuFile==stdin) printf(">");
    char endl, drinksData[MAX_LINE_LENGTH];
    while((endl=fgetc(menuFile))!='\n' && endl!=EOF);
    fgets(drinksData, MAX_LINE_LENGTH, menuFile);
    splitIntoPartsDrinksLine(myMenu->drinks, drinksData);
}

void saveFoodsDataToFile(char* fileName, menu* myMenu)
{
    FILE * menuFile;
    menuFile = fopen (fileName,"w");
    fprintf(menuFile, "%d:\n", myMenu->foodTypeNr);
    for(int i=0; i<myMenu->foodTypeNr; i++)
    {
        fprintf(menuFile, "%s %lf: ", myMenu->foodTypes[i].name, myMenu->foodTypes[i].specFoodNr);
        for(int j=0; j<myMenu->foodTypes[i].specFoodNr; j++)
        {
            fprintf(menuFile, "(%s - %.2lf) ", myMenu->foodTypes[i].specFoods[j].name, myMenu->foodTypes[i].specFoods[j].price);
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
        fprintf(menuFile, "(%s - %.2lf)", myMenu->drinks[i], myMenu->drinks[i].price);
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

