//
// Created by Bori on 11/24/2019.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "usersData.h"
#include "choice.h"
#include "password.h"
#include "password.c"

#define SIGN_IN_UP "Do you want to sign in or sign up?"
#define SIGN_IN "sign in"
#define SIGN_UP "sign up"
#define SIGNING_IN	"Signing in!"
#define SIGNING_UP	"Signing up!"
#define USER_NOT_FOUND	"Username doesn't exist"
#define DUPLICATE_USER	"Please choose another username!"
#define INCORRECT_PASSWORD	"Incorrect password"



void readUsersDataFromFile(usersData* allUsers)
{
    FILE * usersFile;
    usersFile = fopen("usersData.txt", "r+");

    allocateMemoryForUsersData(allUsers);
    int endOfFileReached=0, index=0;
    while(fscanf(usersFile, "%s", allUsers->users[index].name)!=EOF)
    {
        fscanf(usersFile, "%s", allUsers->users[index].password);
        index++;
    }
    allUsers->nrUsers=index;
}

void allocateMemoryForUsersData(usersData* allUsers)
{
    for(int i=0; i<MAX_NO_USERS; i++)
    {
        allUsers->users[i].name = (char*) malloc(MAX_LENGTH_USERNAME* sizeof(char));
        allUsers->users[i].password = (char*) malloc(MAX_LENGTH_PASSWORD* sizeof(char));
    }
}

void freeMemoryForUsersData(usersData* allUsers)
{
    for(int i=0; i<MAX_NO_USERS; i++)
    {
        free(allUsers->users[i].name);
        free(allUsers->users[i].password);
    }
}

int findUserName(usersData* allUsers, char name[])
{
    //returns -1 if not found, otherwise returns the index at which the username was found in the data of all users
    for(int i=0; i<allUsers->nrUsers; i++)
    {
        if(strcmp(allUsers->users[i].name, name)==0) return i;
    }
    return -1;
}

bool correctPasswordForThisUser(usersData* allUsers, char password[], int index)
{
    if(strcmp(allUsers->users[index].password, password)==0) return true;
    return false;
}

void userSignInOrUp(struct user * myUser)
{
    printf("%s\na) %s\nb) %s\n", SIGN_IN_UP, SIGN_IN, SIGN_UP);
    int choice = getChoiceIndex(2);
    usersData allUsers;
    readUsersDataFromFile(&allUsers);
    if(choice==0) userSignIn(myUser, &allUsers);
    else userSignUp(myUser, &allUsers);
}


void userSignIn(struct user* myUser, usersData* allUsers){
    printf("%s\n", SIGNING_IN);
    getUserData(myUser);
    int userIndex=findUserName(allUsers, myUser->name); //-1 --> he doesn't exist
    if(userIndex==-1){
        printf("%s\n", USER_NOT_FOUND);
        userSignInOrUp(myUser);
    }
    else{
        if(!correctPasswordForThisUser(allUsers, myUser->password, userIndex)){
            printf("%s\n", INCORRECT_PASSWORD);
            userSignIn(myUser, allUsers);
        }//else process is finished, it continues to choosing the foods
    }
}

void userSignUp(struct user* myUser, usersData* allUsers){
    printf("%s\n", SIGNING_UP);
    getUserData(myUser);
    int userIndex=findUserName(allUsers, myUser->name); //-1 --> he doesn't exist
    if(userIndex!=-1){
        printf("%s\n", DUPLICATE_USER);
        userSignUp(myUser, allUsers);
    }
    else{
        int errorCode = getPasswordErrorCode(myUser->password, myUser->name);
        if(errorCode==-1){
            saveNewUserDataToFile(myUser);
            freeMemoryForUsersData(allUsers);
        }
        else{
            printErrorMessage(errorCode);
            userSignUp(myUser, allUsers);
        }
    }
}