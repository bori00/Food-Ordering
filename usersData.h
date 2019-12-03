//
// Created by Bori on 11/24/2019.
//

#ifndef FOODORDERING_USERSDATA_H
#define FOODORDERING_USERSDATA_H

#define MAX_NO_USERS 1000

#include <stdbool.h>
#include "user.h"


typedef struct usersData
{
    int nrUsers;
    struct user users[MAX_NO_USERS];

}usersData;

void readUsersDataFromFile(usersData* allUsers);
void allocateMemoryForUsersData(usersData* allUsers);
void freeMemoryForUsersData(usersData* allUsers);
int findUserName(usersData* allUsers, char name[]);
bool correctPasswordForThisUser(usersData* allUsers, char password[], int index);
void saveNewUserDataToVector(usersData* allUsers, struct user* myUser);
void userSignInOrUp(struct user * myUser, usersData *allUsers);
void userSignIn(struct user* myUser, usersData* allUsers);
void userSignUp(struct user* myUser, usersData* allUsers);

#endif //FOODORDERING_USERSDATA_H
