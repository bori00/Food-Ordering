//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_ORDER_H
#define FOODORDERING_ORDER_H

#include <stdbool.h>
#include "menu.h"

struct order
{
    int foodType; //0=pizza, 1=pasta, 2-salad
    int specFood; //whick kind of pizza/pasta/salad?
    int drink; //-1 = nothing
    bool cutlery;
    bool existsAdditionalInfo;
    char additionalInfo[100];

};

void chooseFoodType(struct order *myOrder,  menu myMenu, int *step);
void chooseSpecFood(struct order *myOrder, menu myMenu, int *step);
void chooseDrink(struct order *myOrder, menu myMenu, int *step);
void decideCutlery(struct order *myOrder, menu myMenu, int *step);
void getAdditionalInfo(struct order *myOrder, int* step);

#endif //FOODORDERING_ORDER_H
