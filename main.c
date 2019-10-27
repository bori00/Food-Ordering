#include <stdio.h>
#include <stdbool.h>

struct menu
{
    int foodTypeNr; //how many types of food
    char* foodTypes[10]; //the name of the food types
    int specFoodNr[10]; //how many scpec. foods of each type
    char* specFoods[10][10];
    double specFoodsPrice[10][10];
    int drinkNr; //how many poss. drinks
    char* drinks[10];
    int drinksPrice[10];
};

void fillMenuWithMyData(struct menu *myMenu)
{
    myMenu->foodTypeNr=3;
    myMenu->foodTypes[0]="pizza";
    myMenu->foodTypes[1]="pasta";
    myMenu->foodTypes[2]="salad";

    myMenu->specFoodNr[0]=3; //3 types of pizzas
    myMenu->specFoodNr[1]=2; //pastas
    myMenu->specFoodNr[2]=4; //salads

    myMenu->specFoods[0][0]="Pizza Carbonara";
    myMenu->specFoods[0][1]="Pizza Diavola";
    myMenu->specFoods[0][2]="Pizza Margherita";
    myMenu->specFoods[1][0]="Chicken alfredo";
    myMenu->specFoods[1][1]="Mac&cheese";
    myMenu->specFoods[2][0]="Tuna Salad";
    myMenu->specFoods[2][1]="Chicken salad";
    myMenu->specFoods[2][2]="Greek salad";
    myMenu->specFoods[2][3]="Cobb";

    myMenu->specFoodsPrice[0][0]=21;
    myMenu->specFoodsPrice[0][1]=23;
    myMenu->specFoodsPrice[0][2]=19;
    myMenu->specFoodsPrice[1][0]=23;
    myMenu->specFoodsPrice[1][1]=21;
    myMenu->specFoodsPrice[2][0]=23;
    myMenu->specFoodsPrice[2][1]=22;
    myMenu->specFoodsPrice[2][2]=19;
    myMenu->specFoodsPrice[2][3]=21;

    myMenu->drinkNr=5;
    myMenu->drinks[0]="Coca-Cola";
    myMenu->drinks[1]="Fanta";
    myMenu->drinks[2]="Lipton";
    myMenu->drinks[3]="Water";
    myMenu->drinks[4]="Nothing";

    myMenu->drinksPrice[0]=5;
    myMenu->drinksPrice[1]=5;
    myMenu->drinksPrice[2]=5;
    myMenu->drinksPrice[3]=4;
}

struct order
{
    int foodType; //0=pizza, 1=pasta, 2-salad
    int specFood; //whick kind of pizza/pasta/salad?
    int drink; //0-cola, 1-fanta, 2-lipton, 3-water, 4-nothing
    bool cutlery;
    char additionalInfo[100];

};

struct user
{
    char name[25];
    char password[25];
};

void userLogin(struct user *myUser)
{
    char c;
    printf("Please sign in to continue\n");
    printf("---Username\n");
    scanf("%s", myUser->name);
    while((c=getchar()!='\n' && c!=EOF));
    printf("---Password\n");
    scanf("%s", myUser->password);
    while((c=getchar()!='\n' && c!=EOF));
    printf("Thank you!\n");
}



int main() {
    printf("Welcome to our restaurant! \n");

    int state = 1; //1-userdata, 2-brand, 3-model, 4-add item, 5-sign contract, 6 end

    struct user thisUser;
    struct menu thisMenu;

    fillMenuWithMyData(&thisMenu);

    //printf("%s", thisMenu.specFoods[2][3]);
    while(state<2)
    {
        switch(state)
        {
            case 1: userLogin(&thisUser);
                state++;
                //printf("Your password is %s", thisUser.password);
                break;
            /*case 2: if(getCarBrand(&thisCar)) state++;
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
                break;*/
        }

    }
    //printf("Contract signed! Enjoy your new car!\n");
    return 0;
}