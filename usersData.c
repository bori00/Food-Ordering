//
// Created by Bori on 11/24/2019.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "usersData.h"
#include "choice.h"
#include "password.h"
#include "crypt.h"

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
    //todo factorize
    //todo add admin
    FILE * usersFile;
    usersFile = fopen("usersData.txt", "r");
    allocateMemoryForUsersData(allUsers);
    fscanf(usersFile, "%s", allUsers->crytptKey);
    fscanf(usersFile, "%d", &allUsers->nrUsers);
    char* encryptedPassword = (char*) malloc(sizeof(char)*MAX_LENGTH_PASSWORD);
    char* decryptedPassword;
    for(int i=0; i<allUsers->nrUsers; i++)
    {
        fscanf(usersFile, "%s", allUsers->users[i].name);
        fscanf(usersFile, "%s", encryptedPassword);
        decryptedPassword = decryptPassword(encryptedPassword, allUsers->crytptKey);
        strcpy(allUsers->users[i].password, decryptedPassword);
        //todo delete print
        printf("the password %d is %s", i, allUsers->users[i].password);
        free(decryptedPassword);
    }
    free(encryptedPassword);
    fclose(usersFile);
}

void allocateMemoryForUsersData(usersData* allUsers)
{
    for(int i=0; i<MAX_NO_USERS; i++)
    {
        allocateMemoryForUser(&allUsers->users[i]);
    }
    allUsers->crytptKey= (char*) malloc(sizeof(char)*MAX_KEY_LENGTH);
}

void freeMemoryForUsersData(usersData* allUsers)
{
    for(int i=0; i<MAX_NO_USERS; i++)
    {
        freeMemoryForUser(&allUsers->users[i]);
    }
    free(allUsers->crytptKey);
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
    if(strlen(password)==strlen(allUsers->users[index].password) && strcmp(allUsers->users[index].password, password)==0)
    {
        return true;
    }
    return false;
}

void saveNewUserDataToVector(usersData* allUsers, struct user* myUser)
{
    (allUsers->nrUsers)++;
   //note: memory is already allocated
    strcpy(allUsers->users[allUsers->nrUsers-1].name, myUser->name);
    strcpy(allUsers->users[allUsers->nrUsers-1].password, myUser->password);
}

void setNewUsersNrInFile(usersData allUsers)
{
    FILE * usersFile;
    usersFile = fopen("usersData.txt", "r+");
    char s[MAX_KEY_LENGTH]; //to read the
    fgets(s, MAX_KEY_LENGTH, usersFile);
    char c;
    fpos_t position;
    fgetpos(usersFile, &position);
    fsetpos(usersFile, &position);
    fprintf(usersFile, "%10d", allUsers.nrUsers);
    fflush(usersFile);
    fclose(usersFile);
}

void userSignInOrUp(struct user * myUser, usersData *allUsers) {
    printf("%s\na) %s\nb) %s\n", SIGN_IN_UP, SIGN_IN, SIGN_UP);
    int choice = getChoiceIndex(2);
    if (choice == 0) userSignIn(myUser, allUsers);
    else userSignUp(myUser, allUsers);
}

void userSignIn(struct user* myUser, usersData* allUsers){
    printf("%s\n", SIGNING_IN);
    getUserData(myUser);
    int userIndex=findUserName(allUsers, myUser->name); //-1 --> he doesn't exist
    if(userIndex==-1){
        printf("%s\n", USER_NOT_FOUND);
        userSignInOrUp(myUser, allUsers);
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
    int userIndex=findUserName(allUsers, myUser->name); //-1 --> the user doesn't exist
    if(userIndex!=-1){
        printf("%s\n", DUPLICATE_USER);
        userSignUp(myUser, allUsers);
    } else {
        int errorCode = getPasswordErrorCode(myUser->password, myUser->name);
        if(errorCode==-1){
            saveNewUserDataToVector(allUsers, myUser);
            saveNewUserDataToFile(myUser, allUsers->crytptKey);
            setNewUsersNrInFile(*allUsers);
        } else {
            printErrorMessage(errorCode);
            userSignUp(myUser, allUsers);
        }
    }
}