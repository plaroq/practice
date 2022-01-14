/* 
 * File:   main.c
 * Author: Philippe Larocque - C0445536
 *
 * Created on February 4, 2017, 10:18 AM
 */

#include <stdio.h>
#include <stdlib.h>

double changeItem(double change, const double itemValue,
        const char *singleName, const char *pluralName);

int main(void) {
    double price = 0, tendered = 0, changeDue = 0;
    int changeRound;

    while (price != 6.66) {


        printf("\nEnter the amount of the purchase: ");
        scanf("%lf", &price);
        printf("Enter the amount tendered: ");
        scanf("%lf", &tendered);
        changeDue = tendered - price;

        if (price < 0 || tendered < 0) {
            printf("The amounts must be positive\n");
        } else if (changeDue < 0) {
            printf("Please give me at least $%.2lf more cash\n", fabs(changeDue));
        }

        printf("Change Due is $%.2lf\n", changeDue);
        changeRound = changeDue * 100 / 5;
        changeDue = changeRound * 5 / 100;
        printf("Rounded to the nearest nickel $%.2lf\n\n", changeDue);

        changeDue = changeItem(changeDue, 20, "Twenty", "Twenties");
        changeDue = changeItem(changeDue, 10, "Ten", "Tens");
        changeDue = changeItem(changeDue, 5, "Five", "Fives");
        changeDue = changeItem(changeDue, 2, "Toonie", "Toonies");
        changeDue = changeItem(changeDue, 1, "Loonie", "Loonies");
        changeDue = changeItem(changeDue, 0.25, "Quarter", "Quarters");
        changeDue = changeItem(changeDue, 0.1, "Dime", "Dimes");
        changeDue = changeItem(changeDue, 0.05, "Nickel", "Nickels");
        changeDue = changeItem(changeDue, 0.01, "Penny", "Pennies");
    }

    return (EXIT_SUCCESS);
}

double changeItem(double change, const double itemValue,
        const char *singleName, const char *pluralName) {
    int numItem;
    numItem = change / itemValue;

    if (numItem >= 0) {
        printf("%d %s\n", numItem, pluralName);
        change -= numItem*itemValue;
    }
    return (change);
}