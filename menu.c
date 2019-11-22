//
// Created by Bori on 11/3/2019->
//

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include <stdio.h>
#include "dataProcessing.h"


#define LOAD_DATA "Please load the data"
#define MAX_LINE_LENGTH 150

void fillMenuWithMyData(menu *myMenu) //data should be rad in from a file
{
    myMenu->foodTypeNr=3;
    myMenu->foodTypes[0]="pizza";
    myMenu->foodTypes[1]="pasta";
    myMenu->foodTypes[2]="salad";

    myMenu->specFoodNr[0]=3; //3 types of pizzas
    myMenu->specFoodNr[1]=2; //pastas
    myMenu->specFoodNr[2]=4; //salads

    myMenu->specFoods[0][0]="Pizza Carbonara";
    myMenu->specFoods[0][1]="Pizza Diavola";
    myMenu->specFoods[0][2]="Pizza Margherita";
    myMenu->specFoods[1][0]="Chicken alfredo";
    myMenu->specFoods[1][1]="Mac&cheese";
    myMenu->specFoods[2][0]="Tuna Salad";
    myMenu->specFoods[2][1]="Chicken salad";
    myMenu->specFoods[2][2]="Greek salad";
    myMenu->specFoods[2][3]="Cobb";

    myMenu->specFoodsPrice[0][0]=21;
    myMenu->specFoodsPrice[0][1]=23;
    myMenu->specFoodsPrice[0][2]=19;
    myMenu->specFoodsPrice[1][0]=23;
    myMenu->specFoodsPrice[1][1]=21;
    myMenu->specFoodsPrice[2][0]=23;
    myMenu->specFoodsPrice[2][1]=22;
    myMenu->specFoodsPrice[2][2]=19;
    myMenu->specFoodsPrice[2][3]=21;

    myMenu->drinkNr=5;
    myMenu->drinks[0]="Coca-Cola";
    myMenu->drinks[1]="Fanta";
    myMenu->drinks[2]="Lipton";
    myMenu->drinks[3]="Water";
    myMenu->drinks[4]="Nothing";

    myMenu->drinksPrice[0]=5;
    myMenu->drinksPrice[1]=5;
    myMenu->drinksPrice[2]=5;
    myMenu->drinksPrice[3]=4;
    myMenu->drinksPrice[4]=0;
}

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
    if(menuFile==stdin) printf(">");
    fgets(drinksData, MAX_LINE_LENGTH, menuFile);
    splitIntoParts(drinksData, myMenu->drinks, myMenu->drinksPrice, &myMenu->drinkNr);
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
}

