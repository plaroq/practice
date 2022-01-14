/*
 * This file contains two functions, one to perform math operations on two
 * vectors and another to print a vector to the screen.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vectorMath.h"

//vectorMath function will perform math operations on a vector
Vector *vectorMath(const Vector v1, const Vector v2, Vector *result,
        const char op) {

    //if the vectors are of different length return NULL error
    if (v1.len != v2.len) {
        fprintf(stderr, "Vectors are not the same length - ");
        return NULL;
    }

    //make the result vector the same length as the input vectors
    result->len = v1.len;

    //for loop placed outside switch to save lines of code
    for (int i = 0; i <= v1.len; i++) {
        //switch loop will perform math operations on each item in the array
        switch (op) {
            case '+':
                result->item[i] = v1.item[i] + v2.item[i];
                break;
            case '-':
                result->item[i] = v1.item[i] - v2.item[i];
                break;
            case '*':
                result->item[i] = v1.item[i] * v2.item[i];
                break;
            case '/':
                result->item[i] = v1.item[i] / v2.item[i];
                break;
                //if math operator is invalid a NULL is returned and error message
            default:
                fprintf(stderr, "Not a valid operator");
                return NULL;
        }
    }

    return result;

}

//this function will print a vector to the screen
void printVector(const Vector v) {
    for (int i = 0; i < v.len; i++) {
        printf(WORD_FORMAT, v.item[i]);
    }
    printf("\n");
}