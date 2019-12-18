//
// Created by Bori on 11/3/2019.
//

#include "foodType.h"
#include "drink.h"

#ifndef FOODORDERING_MENU_H
#define FOODORDERING_MENU_H

#define MAX_STRING_LENGTH  50
//#define MAX_SPECFOOD_NR 10

typedef struct
{
    int foodTypeNr; //how many types of food
    foodType* foodTypes;
    int drinkNr; //how many poss. drinks
    drink* drinks;
}menu;


void loadDataToMenu(menu *myMenu);
void freeMemoryOfMenu(menu* myMenu);

#endif //FOODORDERING_MENU_H
