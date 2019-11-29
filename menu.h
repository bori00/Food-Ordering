//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_MENU_H
#define FOODORDERING_MENU_H

#define MAX_STRING_LENGTH  50
//#define MAX_SPECFOOD_NR 10

typedef struct menus
{
    int foodTypeNr; //how many types of food
    char** foodTypes; //the name of the food types
    int* specFoodNr; //how many scpec. foods of each type
    char*** specFoods;
    double** specFoodsPrice;
    int drinkNr; //how many poss. drinks
    char** drinks;
    double* drinksPrice;
}menu;

void allocateMemoryFodFoodTypes(menu *myMenu);
void allocateMemoryForDrinks(menu* myMenu);
void loadDataToMenu(menu *myMenu);
void saveFoodsDataToFile(char* fileName, menu* myMenu);
void saveDrinksDataToFile(char* fileName, menu* myMenu);
void freeMemoryFodFoods(menu *myMenu);
void freeMemoryFordDrinks(menu* myMenu);
void freeMemoryOfMenu(menu* myMenu);

#endif //FOODORDERING_MENU_H
