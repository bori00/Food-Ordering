//
// Created by Bori on 11/24/2019.
//

#ifndef FOODORDERING_USERSDATA_H
#define FOODORDERING_USERSDATA_H

#define MAX_NO_USERS 100
#define MAX_KEY_LENGTH 100

#include <stdbool.h>
#include "user.h"


typedef struct
{
    char* crytptKey;
    int nrUsers;
    struct user users[MAX_NO_USERS];

}usersData;

void readUsersDataFromFile(usersData* allUsers);
void destroyUsersData(usersData* allUsers);
void userSignInOrUp(struct user * myUser, usersData *allUsers);

#endif //FOODORDERING_USERSDATA_H
