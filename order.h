//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_ORDER_H
#define FOODORDERING_ORDER_H

#include <stdbool.h>

struct order
{
    int foodType; //0=pizza, 1=pasta, 2-salad
    int specFood; //whick kind of pizza/pasta/salad?
    int drink; //0-cola, 1-fanta, 2-lipton, 3-water, 4-nothing
    bool cutlery;
    bool existsAdditionalInfo;
    char additionalInfo[100];

};

void displayFoodTypeOptions(struct order myOrder, struct menu myMenu);
bool hasChosenFoodType(struct order *myOrder, struct menu myMenu);
void displaySpecFoodOptions(struct order myOrder, struct menu myMenu);
bool hasChosenSpecFood(struct order *myOrder, struct menu myMenu);
void displayDrinkOptions(struct order myOrder, struct menu myMenu);
bool hasSelectedDrink(struct order *myOrder, struct menu myMenu);
void displayCutleryOptions();
bool hasDecidedAboutCutlery(struct order *myOrder, struct menu myMenu);
void getAdditionalInfo(struct order *myOrder);

#endif //FOODORDERING_ORDER_H
