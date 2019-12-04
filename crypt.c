//for the devCryptography
// Created by Bori on 12/3/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "crypt.h"

//the key can be any word of length MAX_KEY_LENGTH(at the moment initialised to 1000), containing any printable characters except spaces
//how does the encryption work? It is basically a circular shiftig encoding,
// but every character is shifted to the right by the code of the correspondent character in the keyword(which is taken periodically)
//I generate characters in th einterval [33, 126], the interval of the so-called "printable characters", except the space
//note that if f(c) were ' '(where f is my crypting function), for any c character form the interval [33, 126], than I didn't know in the file where does the username end and where does the password start
//but since no given password contains ' ', I can simply cunstruct a bijective function from [33, 126] -> to [33, 126]
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
    }
    password[strlen(encryptedPassword)]='\0';
    return password;
}
char* encryptPassword(char* password, char* key)
{
    char* encryptedPassword = (char*) malloc(sizeof(char)*(strlen(password)+1));
    int code;
    for(int i=0; i<strlen(password); i++)
    {
        code=password[i]+key[i%strlen(key)];
        code%=(UPPER_BOUND-LOWER_BOUND);
        code+=LOWER_BOUND;
        encryptedPassword[i]=code;
    }
    encryptedPassword[strlen(password)]='\0';
    return encryptedPassword;
}
