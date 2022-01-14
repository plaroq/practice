/* 
 * This program will convert temperatures between Celsius, Fahrenheit and Kelvin.
 * 
 * Author: Philippe Larocque
 * Created on January 21, 2017, 11:16 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    //declaring variables
    double inputTemp, cel, far, kel;
    char line[0];

    //loop the program until the temperature type is X to exit
    while (line[0] != 'X') {

        //user enters the temperature here
        printf("\nEnter a temp followed by C,F, OR K (X to exit):");
        scanf("%lf%10s", &inputTemp, line);
        while (getchar() != '\n') {
        }

        //calculating all the temperatures depending on type entered
        //invalid temperature type will display error message and repeat while loop
        if (line[0] == 'C') {
            cel = inputTemp;
            kel = inputTemp + 273.15;
            far = inputTemp * 9 / 5 + 32;
            printf("%.3lfK = %.3lfC = %.3lfF\n", kel, cel, far);
        } else if (line[0] == 'F') {
            cel = (inputTemp - 32)*5 / 9;
            kel = cel + 273.15;
            far = inputTemp;
            printf("%.3lfK = %.3lfC = %.3lfF\n", kel, cel, far);
        } else if (line[0] == 'K') {
            cel = inputTemp - 273.15;
            kel = inputTemp;
            far = cel * 9 / 5 + 32;
            printf("%.3lfK = %.3lfC = %.3lfF\n", kel, cel, far);
        } else {
            printf("Invalid temperature type %s\n", &line[0]); //error message
        }
    }
    return (0);
}