//
// Created by Bori on 12/18/2019.
//

#ifndef FOODORDERING_SPECFOOD_H
#define FOODORDERING_SPECFOOD_H

#define MAX_SPECFOODNAME 20

typedef struct {
    char* name;
    double price;
}specFood;

void createSpecFood(specFood* mySpecFood);
void destroySpecFood(specFood* mySpecFood);
#endif //FOODORDERING_SPECFOOD_H
