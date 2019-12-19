//
// Created by Bori on 11/3/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "menu.h"
#include "choice.h"
#include "crypt.h"
#include "foodType.h"
#include "specFood.h"

struct user createUser()
{
    struct user myUser;
    myUser.name = (char*) malloc(MAX_LENGTH_USERNAME* sizeof(char));
    myUser.password = (char*) malloc(MAX_LENGTH_PASSWORD* sizeof(char));
    return myUser;
}

void destroyUser(struct user* myUser)
{
    free(myUser->name);
    free(myUser->password);
}

void getUserData(struct user* myUser)
{
    printf("---Username\n");
    scanf("%s", myUser->name);
    printf("---Password\n");
    scanf("%s", myUser->password);
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayUserData(struct user myUser)
{
    printf("Name: %s\n", myUser.name);
}

void displayOrderDetails(struct user myUser, menu myMenu)
{
    printf("Food items:\n");
    printf("---%s %.2lf\n", myMenu.foodTypes[myUser.hisOrder.foodType].specFoods[myUser.hisOrder.specFood].name, myMenu.foodTypes[myUser.hisOrder.foodType].specFoods[myUser.hisOrder.specFood].price);
    if(myUser.hisOrder.drink>=0)  printf("---%s %.2lf\n", myMenu.drinks[myUser.hisOrder.drink].name, myMenu.drinks[myUser.hisOrder.drink].price);
    printf("Cutlery: ");
    if(myUser.hisOrder.cutlery) printf("yes\n");
    else printf("No\n");
    if(myUser.hisOrder.existsAdditionalInfo) printf("Additional info: %s\n", myUser.hisOrder.additionalInfo);
    double price = myMenu.foodTypes[myUser.hisOrder.foodType].specFoods[myUser.hisOrder.specFood].price;
    if(myUser.hisOrder.drink>=0) price+=myMenu.drinks[myUser.hisOrder.drink].price;
    printf("Payment amount: %.2lf\n", price);
}

void  signOrder(struct user myUser, menu myMenu, int* state)
{
    printf("This is your order:\n-------------------\n");
    displayUserData(myUser);
    displayOrderDetails(myUser, myMenu);
    printf("-------------------\n");
    printf("a) Sign\n");
    printf("b) go back\n");
    int choiceIndex = getChoiceIndex(2);
   goToNextState(state, 1, choiceIndex, 2);
}

void saveNewUserDataToFile(struct user* myUser, char* key)
{
    FILE *usersFile;
    usersFile =fopen("usersData.txt", "a");
    char *encryptedPassword = encryptPassword(myUser->password, key);
    fprintf(usersFile, "%s %s\n", myUser->name, encryptedPassword);
    free(encryptedPassword);
    fflush(usersFile);
    fclose(usersFile);
}

