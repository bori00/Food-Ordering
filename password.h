//
// Created by Bori on 11/24/2019.
//

#ifndef FOODORDERING_PASSWORD_H
#define FOODORDERING_PASSWORD_H

#define MAX_LENGTH_PASSWORD 20
#define MIN_LENGTH_PASSWORD 7
#define SPECIAL_CHARACTERS "._!"
#define ERROR_PASSWORD_LONG	"The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME	"The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR	"The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS	"The password must contain digits"

#include "stdbool.h"

int getPasswordErrorCode(char* password, char* username);
void printErrorMessage(int errorCode);

#endif //FOODORDERING_PASSWORD_H
