/*
 * This program will create Vectors containing numbers and print and
 * manipulate them in various ways. NULL returns indicate an error.
 */

/* 
 * File:   main.c
 * Author: Philippe Larocque - C0445536
 *
 * Created on March 10, 2017, 6:41 PM
 */

//custom header file vectorMath.h included
#include <stdio.h>
#include <stdlib.h>
#include "vectorMath.h"

int main(int argc, char** argv) {

    //two vectors are initialized here and answer vector for results
    Vector potato = {5,
        { 1, 4, -7.2, -6.66, 1.23}};
    Vector tomato = {5,
        {-5.2, 11.1, 0.1, 9.9, 7.123}};
    Vector answer;

    //both vectors are printed to the screen
    printf("Vector #1\t");
    printVector(potato);
    printf("Vector #2\t");
    printVector(tomato);

    //addition is performed here with an error check
    if (vectorMath(potato, tomato, &answer, '+') != NULL) {
        printf("Sum\t\t");
        printVector(answer);
    } else {
        fprintf(stderr, "Sum failed\n");
    }

    //subtraction is performed here with an error check
    if (vectorMath(potato, tomato, &answer, '-') != NULL) {
        printf("Difference\t");
        printVector(answer);
    } else {
        fprintf(stderr, "Difference failed\n");
    }

    //multiplication is performed here with an error check
    if (vectorMath(potato, tomato, &answer, '*') != NULL) {
        printf("Prouct\t\t");
        printVector(answer);
    } else {
        fprintf(stderr, "Product failed\n");
    }

    //division is performed here with an error check
    if (vectorMath(potato, tomato, &answer, '/') != NULL) {
        printf("Quotient\t");
        printVector(answer);
    } else {
        fprintf(stderr, "Quotient failed\n");
    }

    //invalid operator is sent to the function to test the error check
    vectorMath(potato, tomato, &answer, 'X');

    return (EXIT_SUCCESS);
}