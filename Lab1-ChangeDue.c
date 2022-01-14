/*
 * This program will calculate change in canadian currencies.
 * Author: Philippe Larocque - C0445536
 * Created on January 15, 2017, 4:19 PM
 */

#include <stdio.h>

int main(void) {
    
    //Declaring variables
    double price, tendered, change, changeExact;
    int numOf20, numOf10, numOf5, numOf2, numOf1, numOfQuart, numOfDime, numOfNick;
    
    //Collecting data from the user
    printf("Enter the purchase price: ");
    scanf("%lf", &price);
    printf("Enter the amount tendered: ");
    scanf("%lf",&tendered);
    
    //Calculating change
    change = tendered - price;
    changeExact = change;

    //Calculating number of each denomination
    numOf20 = change / 20;
    change -= numOf20*20;
    numOf10 = change / 10;
    change -= numOf10*10;
    numOf5 = change / 5;
    change -= numOf5*5;
    numOf2 = change / 2;
    change -= numOf2*2;
    numOf1 = change / 1;
    change -= numOf1*1;
    numOfQuart = change / 0.25;
    change -= numOfQuart*0.25;
    numOfDime = change / 0.1;
    change -= numOfDime*0.1;
    numOfNick = change / 0.05;

    //Displaying change
    printf("Change Due is $%2.2lf\n",changeExact);
    printf("Rounded to the nearest nickel $%2.2lf\n",numOf20*20+numOf10*10
            +numOf5*5+numOf2*2+numOf1*1+numOfQuart*0.25+numOfDime*0.1
            +numOfNick*0.05);   
    
    //Displaying the number of each denomination
    printf("%d Twenties\n",numOf20);
    printf("%d Tens\n",numOf10);
    printf("%d Fives\n",numOf5);
    printf("%d Toonies\n",numOf2);
    printf("%d Loonies\n",numOf1);
    printf("%d Quarters\n",numOfQuart);
    printf("%d Dimes\n",numOfDime);
    printf("%d Nickels\n",numOfNick);
    
    return (0);
}