//
// Created by Bori on 11/3/2019.
//

#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include "menu.h"
#include "order.h"
#include "choice.h"

void displayFoodTypeOptions(struct order myOrder, struct menu myMenu)
{
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i <=myMenu.foodTypeNr-1; i++) {
        putchar('a' + i);
        printf(") %s\n", myMenu.foodTypes[i]);
    }
    printf("%c) go back\n", (char)'a'+myMenu.foodTypeNr);
}

bool hasChosenFoodType(struct order *myOrder, struct menu myMenu)
{
    displayFoodTypeOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.foodTypeNr+1);
    if(choiceIndex<myMenu.foodTypeNr) //case has chosen a foodType
    {
        myOrder->foodType=choiceIndex;
        return 1;
    }
    return 0; //case go back
}

void displaySpecFoodOptions(struct order myOrder, struct menu myMenu)
{
    printf("Please choose the type of %s\n", myMenu.foodTypes[myOrder.foodType]);
    for (int i = 0; i <=myMenu.specFoodNr[myOrder.foodType]-1; i++) {
        putchar('a' + i);
        printf(") %s %.2lf\n", myMenu.specFoods[myOrder.foodType][i], myMenu.specFoodsPrice[myOrder.foodType][i]);
    }
    printf("%c) go back\n", (char)'a'+myMenu.specFoodNr[myOrder.foodType]);
}

bool hasChosenSpecFood(struct order *myOrder, struct menu myMenu)
{
    displaySpecFoodOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.specFoodNr[myOrder->foodType]+1);
    if(choiceIndex<myMenu.specFoodNr[myOrder->foodType]) //case has chosen a foodType
    {
        myOrder->specFood=choiceIndex;
        return 1;
    }
    return 0; //case go back
}

void displayDrinkOptions(struct order myOrder, struct menu myMenu)
{
    printf("Please choose a drink to go with your %s\n",  myMenu.foodTypes[myOrder.foodType]);
    for (int i = 0; i <=myMenu.drinkNr-1; i++) {
        putchar('a' + i);
        printf(") %s %d\n", myMenu.drinks[i], myMenu.drinksPrice[i]);
    }
    printf("%c) go back\n", (char)'a'+myMenu.drinkNr);
}

bool hasSelectedDrink(struct order *myOrder, struct menu myMenu)
{
    displayDrinkOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.drinkNr+1);
    if(choiceIndex<myMenu.drinkNr) //case has chosen a foodType
    {
        myOrder->drink=choiceIndex;
        return 1;
    }
    return 0; //case go back
}

void displayCutleryOptions()
{
    printf("Do you want cutlery?\n");
    printf("a) yes\n");
    printf("b) no\n");
    printf("c) go back\n");
}

bool hasDecidedAboutCutlery(struct order *myOrder, struct menu myMenu)
{
    displayCutleryOptions();
    int choiceIndex = getChoiceIndex(3);
    switch(choiceIndex)
    {
        case 0: myOrder->cutlery=true;
            return 1;
        case 1: myOrder->cutlery=false;
            return 1;
        case 2: return 0;
    }
}

void getAdditionalInfo(struct order *myOrder)
{
    printf("Any additional info?\n");
    char c;
    gets(myOrder->additionalInfo);
    if(strcmp(myOrder->additionalInfo, "")!=0) myOrder->existsAdditionalInfo=true;
    else myOrder->existsAdditionalInfo=false;
}
