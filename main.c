#include <stdio.h>
#include <stdbool.h>




int main() {
    printf("Welcome to our restaurant! \n");

    /*int state = 1; //1-userdata, 2-brand, 3-model, 4-add item, 5-sign contract, 6 end

    struct user thisUser;
    struct menu thisMenu;

    fillMenuWithMyData(&thisMenu);*/

    //printf("%s", thisMenu.specFoods[2][3]);
    /*while(state<6)
    {
        switch(state)
        {
            case 1: readUserData(&thisUser);
                state++;
                break;
            case 2: if(getCarBrand(&thisCar)) state++;
                else state--;
                // printf("the adress of main car is %d", &thisCar);
                //printf("in main the brand is %d\n", thisCar.brandNr);
                break;
            case 3: if(getCarModel(&thisCar)) state++;
                else state--;
                break;
            case 4: if(chooseAdditionalItems(&thisCar)) state++;
                else state--;
                break;
            case 5: if(signContract(thisUser, thisCar)) state++;
                else state--;
                break;
        }

    }*/
    printf("Contract signed! Enjoy your new car!\n");
    return 0;
}