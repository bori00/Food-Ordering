//
// Created by Bori on 11/3/2019.
//

#ifndef FOODORDERING_USER_H
#define FOODORDERING_USER_H

#include <stdbool.h>
#include "order.h"
#include "menu.h"


#define MAX_LENGTH_USERNAME 100
#define MAX_LENGTH_PASSWORD 100

struct user
{
    char* name;
    char* password;
    struct order hisOrder;
};

void createUser(struct user* myUser);
void destroyUser(struct user* myUser);
void signOrder(struct user myUser,menu myMenu, int*state);
void getUserData(struct user* myUser);
void saveNewUserDataToFile(struct user* myUser, char* key);

#endif //FOODORDERING_USER_H
