//
// Created by Bori on 11/22/2019.
//

#ifndef FOODORDERING_DATAPROCESSING_H
#define FOODORDERING_DATAPROCESSING_H

void processingNameAndPrice(char* name, double* price, char* s);
void eraseSpacesFromEnd(char s[]);
void extractStringUntilChar(char result[], char original[],  char c);
void splitIntoParts(char line[], char* names[], double prices[], int *nr);

#endif //FOODORDERING_DATAPROCESSING_H
