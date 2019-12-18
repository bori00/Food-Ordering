//
// Created by Bori on 12/18/2019.
//

#ifndef FOODORDERING_DRINK_H
#define FOODORDERING_DRINK_H


#define MAX_DRINKNAME 20

typedef struct
{
    char* name;
    double price;
}drink;

drink createDrink();
void destroyDrink(drink* myDrink);
void splitIntoPartsDrinksLine(drink drinks[], char line[]);

#endif //FOODORDERING_DRINK_H
