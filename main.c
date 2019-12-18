#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "user.h"
#include "usersData.h"

#define MAX_STATE 8

int main() {

    int state = 1;
    struct user thisUser;
    allocateMemoryForUser(&thisUser);
    menu thisMenu;
    printf("I am before loading data to menu\n");
    loadDataToMenu(&thisMenu);
    printf("I loaded data to menu\n");
    usersData allUsers;
    readUsersDataFromFile(&allUsers);


    printf("Welcome to our restaurant! \n");

    enum shopStates  {A, SIGN_IN_UP, CHOOSE_FOOD_TYPE, CHOOSE_SPEC_FOOD, CHOOSE_DRINK, DECIDE_CUTLERY, GET_ADDTTIONAL_INFO, SIGN_ORDER};
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
    freeMemoryOfMenu(&thisMenu);
    freeMemoryForUser(&thisUser);
    freeMemoryForUsersData(&allUsers);
    printf("Contract signed! Enjoy your meal!\n");
    return 0;
}