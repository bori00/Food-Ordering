//
// Created by Bori on 11/21/2019.
//

#include <stdlib.h>
#include <string.h>

void processingNameAndPrice(char* name, double* price, char* s)
{
    char* c = strtok(s, " ");
    strcpy(name, c);
    char* priceString = strtok(NULL, " -");
    char* ptr;
    *price = strtod(priceString, &ptr);
}