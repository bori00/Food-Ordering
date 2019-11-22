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
    printf("the third foodType is 1%s\n", thisMenu.foodTypes[0]);
    printf("the second foodType is 2%s\n", thisMenu.foodTypes[1]);

    while(state<MAX_STATE)
    {
        printf("the first foodType is 3%s\n", thisMenu.foodTypes[0]);
        switch(state)
        {
            case 1: printf("the first foodType is 4%s\n", thisMenu.foodTypes[0]);
                userLogin(&thisUser);
                state++;
                break;
            case 2: printf("the first foodType is %s\n", thisMenu.foodTypes[0]);
                chooseFoodType(&thisUser.hisOrder, thisMenu, &state);
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