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

void createFoodType(foodType* newFoodType);
void setSpecFoodsNr(foodType* myFoodType, int nr);
void destroyFoodType(foodType* myFoodType);
void splitIntoPartsSpecFoodLine(foodType* myFoodType, char line[]);
void displaySpecFoodOptions(foodType myFoodType);

#endif //FOODORDERING_FOODTYPE_H
