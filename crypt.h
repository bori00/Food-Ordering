//to devCryptography
// Created by Bori on 12/3/2019.
//

#ifndef FOODORDERING_CRYPT_H
#define FOODORDERING_CRYPT_H

#define MAX_LENGTH_PASSWORD 20 //the same as in user.h

char* decryptPassword(char* encryptedPassword, char* key);
char* encryptPassword(char* password, char* key);

#endif //FOODORDERING_CRYPT_H
