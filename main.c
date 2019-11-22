#include <stdio.h>
#include "menu.h"
#include "user.h"


#define MAX_STATE 8

int main() {
    printf("Welcome to our restaurant! \n");

    int state = 1;
    struct user thisUser;
    menu thisMenu;
    loadDataToMenu(&thisMenu);

    while(state<MAX_STATE)
    {
        switch(state)
        {
            case 1: userLogin(&thisUser);
                state++;
                break;
            case 2: chooseFoodType(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 3: chooseSpecFood(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 4: chooseDrink(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 5: decideCutlery(&thisUser.hisOrder, thisMenu, &state);
                break;
            case 6: getAdditionalInfo(&thisUser.hisOrder, &state);
                    break;
            case 7: signOrder(thisUser, thisMenu, &state);
                    break;
        }

    }
    printf("Contract signed! Enjoy your meal!\n");
    return 0;
}