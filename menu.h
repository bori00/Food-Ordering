//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_MENU_H
#define FOODORDERING_MENU_H

#define MAX_STRING_LENGTH  30
#define MAX_FOODTYPES_NR 10
#define MAX_SPECFOOD_NR 10
#define MAX_DRINKS_NR 10


typedef struct menus
{
    int foodTypeNr; //how many types of food
    char* foodTypes[MAX_FOODTYPES_NR]; //the name of the food types
    int specFoodNr[MAX_FOODTYPES_NR]; //how many scpec. foods of each type
    char* specFoods[MAX_FOODTYPES_NR][MAX_SPECFOOD_NR];
    double specFoodsPrice[MAX_FOODTYPES_NR][MAX_SPECFOOD_NR];
    int drinkNr; //how many poss. drinks
    char* drinks[MAX_DRINKS_NR];
    double drinksPrice[MAX_DRINKS_NR];
}menu;

void allocateMemoryForStrings(menu *myMenu);
void loadDataToMenu(menu *myMenu);
void fillMenuWithMyData(menu *myMenu);

#endif //FOODORDERING_MENU_H
