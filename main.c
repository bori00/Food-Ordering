#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include "user.h"
#include "choice.h"

#define MAX_STATE 8

int main() {
    printf("Welcome to our restaurant! \n");

    int state = 1;
    struct user thisUser;
    struct menu thisMenu;
    fillMenuWithMyData(&thisMenu);

    while(state<MAX_STATE)
    {
        switch(state)
        {
            case 1: userLogin(&thisUser);
                state++;
                break;
            case 2: hasChosenFoodType(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 3: hasChosenSpecFood(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 4: hasSelectedDrink(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 5: hasDecidedAboutCutlery(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 6: getAdditionalInfo(&thisUser.hisOrder, &state);
                    break;
            case 7: signedOrder(thisUser, thisMenu, &state);
                    break;
        }

    }
    printf("Contract signed! Enjoy your meal!\n");
    return 0;
}