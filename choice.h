//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_CHOICE_H
#define FOODORDERING_CHOICE_H

#include <stdbool.h>

bool correctAnswer(char choice, char min, char max);
int getChoiceIndex(int nrOfChoices);
void goToNextState(int* step, int nrForwardOptions, int optionChosen, int goBackNr);

#endif //FOODORDERING_CHOICE_H
