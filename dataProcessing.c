//
// Created by Bori on 11/21/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataProcessing.h"
#include "specFood.h"

#define MAX_LINE_LENGTH 1000

void eraseSpacesFromEnd(char s[])
{
    while(s[strlen(s)-1]==' ') s[strlen(s)-1]='\0';
}

void processingNameAndPrice(char* name, double* price, char* s)
{
    char* priceString = strrchr(s, '-');
    char* ptr;
    *price = strtod(priceString+1, &ptr);
    *priceString='\0';
    strcpy(name, s);
    eraseSpacesFromEnd(name);
}

void extractStringUntilChar(char result[], char original[],  char c)
{
    char* newBeginning = strchr(original, c);
    *newBeginning='\0';
    strcpy(result, original);
    strcpy(original, newBeginning+1);
}




