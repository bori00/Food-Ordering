//for the devCryptography
// Created by Bori on 12/3/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "crypt.h"

//I generate characters in th einterval [33, 126], the interval of the so-called "printable characters"
#define LOWER_BOUND 33
#define UPPER_BOUND 126

char* decryptPassword(char* encryptedPassword, char* key)
{
    char* password = malloc(sizeof(char)*(strlen(encryptedPassword)+1));
    int p; //the code of the current char is the decrypted password
    for(int i=0; i<strlen(encryptedPassword); i++)
    {
        p=(int)encryptedPassword[i]-LOWER_BOUND-(int)key[i%strlen(key)];
        while(p<LOWER_BOUND) p+=UPPER_BOUND-LOWER_BOUND;
        password[i]=(char)p;
        //I should'nt encrypt any character as '\0', also no char in password is '\0',  so I construct a bijective function f: [1, 255]->[1, 255]
    }
    return password;
}
char* encryptPassword(char* password, char* key)
{
    char* encryptedPassword = (char*) malloc(sizeof(char)*(strlen(password)+1));
    int code;
    for(int i=0; i<strlen(password); i++)
    {
        code=password[i]+key[i%strlen(key)];
        printf("after shifting code = %d\n", code);
        code%=(UPPER_BOUND-LOWER_BOUND);
        printf("after smodulo code = %d\n", code);
        code+=LOWER_BOUND;
        printf("after adding lower bound code = %d\n", code);
        encryptedPassword[i]=code;
        printf("saved code = %c\n", encryptedPassword[i]);
        //I should'nt encrypt any character as '\0', also no char in password is '\0',  so I construct a bijective function f: [1, 255]->[1, 255]
    }
    return encryptedPassword;
}
