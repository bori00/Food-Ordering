//
// Created by Bori on 11/24/2019.
//

#include <stdio.h>
#include "password.h"
#include "string.h"



void printErrorMessage(int errorCode)
{
    switch(errorCode)
    {
        case 0: printf("%s\n", ERROR_PASSWORD_LONG);
            break;
        case 1: printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
            break;
        case 2: printf("%s\n", ERROR_PASSWORD_SPECIAL_CHAR);
            break;
        case 3: printf("%s\n", ERROR_PASSWORD_DIGITS);
            break;
    }
}

bool validPasswordLength(char password[])
{
    return strlen(password)>=MIN_LENGTH_PASSWORD;
}

bool doesntContainUsername(char password[], char username[])
{
    return strstr(password, username)==NULL;
}

bool containsSpecialCharacter(char password[])
{
    return strpbrk(password, SPECIAL_CHARACTERS)!=NULL;
}

bool containsDigits(char password[])
{
    printf("the password is %s\n", password);
    char digits[10]="0123456789";
    char* ptr = strpbrk(password, digits);
    printf("it contains digit at %s\n", ptr);
    return ptr!=NULL;
}

int getPasswordErrorCode(char* password, char* username)//return -1 if no error found
{
    if(!validPasswordLength(password)) return 0;
    if(!doesntContainUsername(password, username)) return 1;
    if(!containsSpecialCharacter(password)) return 2;
    if(!containsDigits(password)) return 3;
    return -1;
}