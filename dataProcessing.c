//
// Created by Bori on 11/21/2019.
//

#include <stdlib.h>
#include <string.h>
#include "menu.h"

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

void splitIntoParts(char line[], char* names[], double prices[], int *nr)
{
    char* c;
    c = strtok(line, "(");
    int index=0;
    while ((c=strtok(NULL, ")"))!= NULL)
    {
        processingNameAndPrice(names[index], &prices[index], c);
        c=strtok(NULL, "(");
        index++;
    }
    *nr=index;
}


void extractStringUntilChar(char result[], char original[],  char c)
{
    char* newBeginning = strchr(original, c);
    *newBeginning='\0';
    strcpy(result, original);
    strcpy(original, newBeginning+1);
}




