//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_USER_H
#define FOODORDERING_USER_H

#include "order.h"
#include "menu.h"

struct user
{
    char name[25];
    char password[25];
    struct order hisOrder;
};

void userLogin(struct user *myUser);
void displayUserData(struct user myUser);
void displayHisOrderDetails(struct user myUser, struct menu myMenu);
bool signedOrder(struct user myUser, struct menu myMenu);

#endif //FOODORDERING_USER_H
