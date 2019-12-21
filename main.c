#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "user.h"
#include "usersData.h"

#define MAX_STATE 8

int main() {
    struct user thisUser;
    createUser(&thisUser);
    menu thisMenu;
    loadDataToMenu(&thisMenu);
    usersData allUsers;
    readUsersDataFromFile(&allUsers);

    printf("Welcome to our restaurant!\n");

    enum shopStates  {A, SIGN_IN_UP, CHOOSE_FOOD_TYPE, CHOOSE_SPEC_FOOD, CHOOSE_DRINK, DECIDE_CUTLERY, GET_ADDTTIONAL_INFO, SIGN_ORDER};
    int state = SIGN_IN_UP;

    while(state<MAX_STATE)
    {
        switch(state)
        {
            case SIGN_IN_UP: userSignInOrUp(&thisUser, &allUsers);
                state++;
                break;
            case CHOOSE_FOOD_TYPE: chooseFoodType(&thisUser.hisOrder, thisMenu, &state);
                break;
            case CHOOSE_SPEC_FOOD: chooseSpecFood(&thisUser.hisOrder, thisMenu, &state);
                break;
            case CHOOSE_DRINK: chooseDrink(&thisUser.hisOrder, thisMenu, &state);
                break;
            case DECIDE_CUTLERY: decideCutlery(&thisUser.hisOrder, thisMenu, &state);
                break;
            case GET_ADDTTIONAL_INFO: getAdditionalInfo(&thisUser.hisOrder, &state);
                    break;
            case SIGN_ORDER: signOrder(thisUser, thisMenu, &state);
                    break;
        }
    }
    destroyMenu(&thisMenu);
    destroyUser(&thisUser);
    destroyUsersData(&allUsers);
    printf("Contract signed! Enjoy your meal!\n");
    return 0;
}