/* 
 * This program will calculate force.
 * 
 * Author: Philippe Larocque - C0445536
 * Created on January 26, 2017, 7:33 PM
 */

#include <stdio.h>
#include <stdlib.h>

#define RHO 1.2754
#define G 9.80667

int main(void) {

    //declaring variables
    double height, mass, drag, area, timeStep;
    double forceG = G, forceD = 0, forceNet = 0, velocity = 0, accel = G;

    //collect data from user
    printf("Enter the height in metres: ");
    scanf("%lf", &height);
    printf("Enter the mass in kg: ");
    scanf("%lf", &mass);
    printf("Enter the drag coefficient: ");
    scanf("%lf", &drag);
    printf("Enter the cross-sectional area: ");
    scanf("%lf", &area);
    printf("Enter the time step size: ");
    scanf("%lf", &timeStep);

    //Force of gravity acting on the mass will be the same throughout
    forceG = mass*G;

    printf("   Time   Height   Velocity\n");
    //calculate
    for (double i = 0; height > 0 && i < 1000000; i += timeStep) {
        
        forceD = (0.5) * drag * RHO * area * velocity * velocity;
        forceNet = forceG - forceD;
        accel = forceNet / mass;

        printf("%8.2lf%8.1lf%8.1lf\n", i, height, velocity);

        //these are calculated after the printf so the first iteration is zero
        velocity += timeStep * accel;
        height -= timeStep * velocity;
    }

    printf("Theoretical terminal velocity is %.1lf m/s", velocity);


    return (EXIT_SUCCESS);
}