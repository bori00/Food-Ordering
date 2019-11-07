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

void hasChosenFoodType(struct order *myOrder, struct menu myMenu, int* step)
{
    displayFoodTypeOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.foodTypeNr+1);
    goToNextState(step, myMenu.foodTypeNr, choiceIndex, 1);
    if(choiceIndex<myMenu.drinkNr)
    {
        myOrder->foodType=choiceIndex;
    }
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

void hasChosenSpecFood(struct order *myOrder, struct menu myMenu, int* step)
{
    displaySpecFoodOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.specFoodNr[myOrder->foodType]+1);
    goToNextState(step, myMenu.specFoodNr[myOrder->foodType], choiceIndex, 1);
    if(choiceIndex<myMenu.specFoodNr[myOrder->foodType])
    {
        myOrder->specFood=choiceIndex;
    }
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

void hasSelectedDrink(struct order *myOrder, struct menu myMenu, int* step)
{
    displayDrinkOptions(*myOrder, myMenu);
    int choiceIndex = getChoiceIndex(myMenu.drinkNr+1);
    goToNextState(step, myMenu.drinkNr, choiceIndex, 1);
    if(choiceIndex<myMenu.drinkNr) //case has chosen a foodType
    {
        myOrder->drink=choiceIndex;
    }
}

void displayCutleryOptions()
{
    printf("Do you want cutlery?\n");
    printf("a) yes\n");
    printf("b) no\n");
    printf("c) go back\n");
}

void hasDecidedAboutCutlery(struct order *myOrder, struct menu myMenu, int* step)
{
    displayCutleryOptions();
    int choiceIndex = getChoiceIndex(3);
    goToNextState(step, 2, choiceIndex, 1);
    switch(choiceIndex)
    {
        case 0: myOrder->cutlery=true;
                break;
        case 1: myOrder->cutlery=false;
                break;
    }
}

void getAdditionalInfo(struct order *myOrder, int* step)
{
    printf("Any additional info?\n");
    gets(myOrder->additionalInfo);
    if(strcmp(myOrder->additionalInfo, "")!=0) myOrder->existsAdditionalInfo=true;
    else myOrder->existsAdditionalInfo=false;
    (*step)++;
}
