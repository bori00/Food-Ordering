//
// Created by Bori on 11/3/2019.
//

#include <stdio.h>
#include "user.h"
#include "menu.h"
#include "choice.h"

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

void displayOrderDetails(struct user myUser, struct menu myMenu)
{
    printf("Food items:\n");
    printf("---%s\n", myMenu.specFoods[myUser.hisOrder.foodType][myUser.hisOrder.specFood]);
    printf("---%s\n", myMenu.drinks[myUser.hisOrder.drink]);
    printf("Cutlery: ");
    if(myUser.hisOrder.cutlery) printf("yes\n");
    else printf("No\n");
    if(myUser.hisOrder.existsAdditionalInfo) printf("Additional info: %s\n", myUser.hisOrder.additionalInfo);
    printf("Payment amount: %lf\n", myMenu.specFoodsPrice[myUser.hisOrder.foodType][myUser.hisOrder.specFood]+myMenu.drinksPrice[myUser.hisOrder.drink]);
}

bool signedOrder(struct user myUser, struct menu myMenu)
{
    printf("This is your order:\n-------------------\n");
    displayUserData(myUser);
    displayOrderDetails(myUser, myMenu);
    printf("-------------------\n");
    printf("a) Sign\n");
    printf("b) go back\n");
    int choiceIndex = getChoiceIndex(2);
    switch(choiceIndex)
    {
        case 0: return 1;
            break;
        case 1: return 0;
    }
}

