//
// Created by Bori on 11/24/2019.
//

#ifndef FOODORDERING_USERSDATA_H
#define FOODORDERING_USERSDATA_H

#define MAX_NO_USERS 100
#define MAX_LENGTH_USERNAME 20
#define MAX_LENGTH_PASSWORD 20
#define MIN_LENGTH_PASSWORD 7

typedef struct users
{
    int nrUsers;
    char** userNames;
    char** passwords;

}users;

void initialiseUsersData(users* allUsers);
void allocateMemory(users *allUsers);
void readUsersDataFromFile(users* allUsers);

#endif //FOODORDERING_USERSDATA_H
