//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_USER_H
#define FOODORDERING_USER_H

#include "order.h"
#include "menu.h"
#include "usersData.h"

struct user
{
    char name[25];
    char password[25];
    struct order hisOrder;
};

void userSignInOrUp(struct user *myUser);
void userLogin(struct user *myUser);
void displayUserData(struct user myUser);
void displayOrderDetails(struct user myUser,  menu myMenu);
void signOrder(struct user myUser,menu myMenu, int*state);

#endif //FOODORDERING_USER_H
