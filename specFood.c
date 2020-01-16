//
// Created by Bori on 12/18/2019.
//

#include "specFood.h"
#include <stdlib.h>

void createSpecFood(specFood* newSpecFood)
{
    newSpecFood->name = (char*) malloc(MAX_SPECFOODNAME*sizeof(char));
}

void destroySpecFood(specFood* mySpecFood)
{
    free(mySpecFood->name);
}