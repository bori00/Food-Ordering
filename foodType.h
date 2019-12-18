//
// Created by Bori on 12/18/2019.
//
#include "specFood.h"

#ifndef FOODORDERING_FOODTYPE_H
#define FOODORDERING_FOODTYPE_H

#define MAX_FOODTYPE_LENGTH 20

typedef struct {
    char* name;
    int specFoodNr;
    specFood* specFoods;
}foodType;

foodType createFoodType();
void setSpecFoodsNr(foodType* myFoodType, int nr);
void destroyFoodType(foodType* myFoodType);
void splitIntoPartsSpecFoodLine(foodType* myFoodType, char line[]);

#endif //FOODORDERING_FOODTYPE_H
