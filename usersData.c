//
// Created by Bori on 11/24/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include "usersData.h"

void initialiseUsersData(users* allUsers)
{
    allocateMemory(allUsers);
    readUsersDataFromFile(allUsers);
}

void allocateMemory(users* allUsers)
{
    //userNames
    allUsers->userNames = (char**) malloc(sizeof(char*)*MAX_NO_USERS);
    for(int i=0; i<MAX_NO_USERS; i++)
    {
        allUsers->userNames[i] = (char*) malloc(sizeof(char)*MAX_LENGTH_USERNAME);
    }
    //passwords
    allUsers->passwords = (char**) malloc(sizeof(char*)*MAX_NO_USERS);
    for(int i=0; i<MAX_NO_USERS; i++)
    {
        allUsers->passwords[i] = (char*) malloc(sizeof(char)*MAX_LENGTH_PASSWORD);
    }
}


void readUsersDataFromFile(users* allUsers)
{
    FILE * usersFile;
    usersFile = fopen("usersData.txt", "r+");

    int endOfFileReached=0, index=0;
    while(fscanf(usersFile, "%s", allUsers->userNames[index])!=EOF)
    {
        fscanf(usersFile, "%s", allUsers->passwords[index]);
        index++;
    }
    allUsers->nrUsers=index;
}