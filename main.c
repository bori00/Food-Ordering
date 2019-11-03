#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include "user.h"
#include "choice.h"


int main() {
    printf("Welcome to our restaurant! \n");

    int state = 1; //1-userdata, 2-brand, 3-model, 4-add item, 5-sign contract, 6 end

    struct user thisUser;
    struct menu thisMenu;

    fillMenuWithMyData(&thisMenu);

    //printf("%s", thisMenu.specFoods[2][3]);
    while(state<8)
    {
        switch(state)
        {
            case 1: userLogin(&thisUser);
                state++;
                //printf("Your password is %s", thisUser.password);
                break;
            case 2: if(hasChosenFoodType(&thisUser.hisOrder, thisMenu)) state++;
                else state--;
                // printf("the adress of main car is %d", &thisCar);
                //printf("in main the brand is %d\n", thisCar.brandNr);
                break;
            case 3: if(hasChosenSpecFood(&thisUser.hisOrder, thisMenu)) state++;
                else state--;
                break;
            case 4: if(hasSelectedDrink(&thisUser.hisOrder, thisMenu)) state++;
                else state--;
                break;
            case 5: if(hasDecidedAboutCutlery(&thisUser.hisOrder, thisMenu)) state++;
                else state--;
                break;
            case 6: getAdditionalInfo(&thisUser.hisOrder);
                    state++;
                    break;
            case 7: if(signedOrder(thisUser, thisMenu)) state++;
                    else state-=2;
                    break;
        }

    }
    printf("Contract signed! Enjoy your meal!\n");
    return 0;
}