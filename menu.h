//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_MENU_H
#define FOODORDERING_MENU_H

struct menu
{
    int foodTypeNr; //how many types of food
    char* foodTypes[10]; //the name of the food types
    int specFoodNr[10]; //how many scpec. foods of each type
    char* specFoods[10][10];
    double specFoodsPrice[10][10];
    int drinkNr; //how many poss. drinks
    char* drinks[10];
    int drinksPrice[10];
};

void fillMenuWithMyData(struct menu *myMenu);

#endif //FOODORDERING_MENU_H
