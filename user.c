//
// Created by Bori on 11/3/2019.
//

#include <stdio.h>
#include "user.h"
#include "menu.h"
#include "choice.h"

#define SIGN_IN_UP "Do you want to sign in or sign up?"
#define  SIGN_IN "sign in"
#define  SIGN_UP "sign up"

void userSignInOrUp(struct user * myUser)
{
    printf("%s\na) %s\nb) %s\n", SIGN_IN_UP, SIGN_IN, SIGN_UP);
    int choice = getChoiceIndex(2);
    //todo: write these two functions
    users allUsers;
    initialiseUsersData(&allUsers);
    /*if(choice==0) userSignIn(myUser);
    else userSignUp(myUser);*/
}

void userSignIn(struct user* myUser, users* allUsers)
{

}

void userLogin(struct user *myUser)
{
    char c;
    printf("Please sign in to continue\n");
    printf("---Username\n");
    scanf("%s", myUser->name);
    while((c=getchar()!='\n' && c!=EOF));
    printf("---Password\n");
    scanf("%s", myUser->password);
    while((c=getchar()!='\n' && c!=EOF));
    printf("Thank you!\n");
}

void displayUserData(struct user myUser)
{
    printf("Name: %s\n", myUser.name);
}

void displayOrderDetails(struct user myUser, menu myMenu)
{
    printf("Food items:\n");
    printf("---%s %.2lf\n", myMenu.specFoods[myUser.hisOrder.foodType][myUser.hisOrder.specFood], myMenu.specFoodsPrice[myUser.hisOrder.foodType][myUser.hisOrder.specFood]);
    if(myUser.hisOrder.drink>=0)  printf("---%s %.2lf\n", myMenu.drinks[myUser.hisOrder.drink], myMenu.drinksPrice[myUser.hisOrder.drink]);
    printf("Cutlery: ");
    if(myUser.hisOrder.cutlery) printf("yes\n");
    else printf("No\n");
    if(myUser.hisOrder.existsAdditionalInfo) printf("Additional info: %s\n", myUser.hisOrder.additionalInfo);
    double price = myMenu.specFoodsPrice[myUser.hisOrder.foodType][myUser.hisOrder.specFood];
    if(myUser.hisOrder.drink>=0) price+=myMenu.drinksPrice[myUser.hisOrder.drink];
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

