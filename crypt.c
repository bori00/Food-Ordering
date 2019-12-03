//for the devCryptography
// Created by Bori on 12/3/2019.
//

#include <stdlib.h>
#include <string.h>
#include "crypt.h"

char* decryptPassword(char* encryptedPassword, char* key)
{
    char* password = malloc(sizeof(char)*(strlen(encryptedPassword)+1));
    int p; //the code of the current char is the decrypted password
    for(int i=0; i<strlen(password); i++)
    {
        p=encryptedPassword[i]-1-key[strlen(key)%i];
        if(p<1) p+=255;
        password[i]=(char)p;
        //I should'nt encrypt any character as '\0', also no char in password is '\0',  so I construct a bijective function f: [1, 255]->[1, 255]
    }
    return password;
}
char* encryptPassword(char* password, char* key)
{
    char* encryptedPassword = (char*) malloc(sizeof(char)*(strlen(password)+1));
    for(int i=0; i<strlen(password); i++)
    {
        encryptedPassword[i]=(password[i]+key[strlen(key)%i])%255+1;
        //I should'nt encrypt any character as '\0', also no char in password is '\0',  so I construct a bijective function f: [1, 255]->[1, 255]
    }
    return encryptedPassword;
}
