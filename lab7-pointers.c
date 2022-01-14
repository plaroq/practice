/*
 * This program contains functions that will swap adjacent words
 * in an array (vector). 
 */

/* 
 * File:   Lab7-pointerSwap.c
 * Author: Philippe Larocque
 *
 * Created on February 26, 2017, 1:50 PM
 */

#include <stdio.h>
#include <stdlib.h>

typedef int WORD;
#define WORD_FORMAT "%d "

void swap(WORD *x, WORD *y);
void printVector(WORD *vec, const int N);
void printBytes(const WORD *vec, const int N);
void printVectorReverseEndian(const WORD *vec, const int N);

int main(void) {
    const int N_NUMS = 10;
    const WORD START = 1011;

    WORD potatoArray[N_NUMS];
    for (int i = 0; i < 10; i++) {
        potatoArray[i] = START + i;
    }

    WORD *potatoPointer = &potatoArray[0];

    printf("Original Vector:\n");
    printVector(potatoPointer, N_NUMS);
    swap(potatoPointer, potatoPointer + 1);
    printf("Adjacent words swapped:\n");
    printVector(potatoPointer, N_NUMS);
    swap(potatoPointer, potatoPointer + 1);
    printf("Words swapped back:\n");
    printVector(potatoPointer, N_NUMS);
    printf("Data Bytes:\n");
    printBytes(potatoPointer, N_NUMS);
    printf("Word bytes with endian reversal:\n");
    printVectorReverseEndian(potatoPointer, N_NUMS);

    return (EXIT_SUCCESS);
}

void swap(WORD *x, WORD *y) {
    for (int i = 0; i <= sizeof (x) + 1; i += 2) {
        int temp;
        temp = y[i];
        y[i] = x[i];
        x[i] = temp;
    }
}

void printVector(WORD *vec, const int N) {
    for (int i = 0; i < N; i++) {
        printf(WORD_FORMAT, vec[i]);
    }
    printf("\n");
}

void printBytes(const WORD *vec, const int N) {
    unsigned char *temp = (unsigned char*) vec;
    for (int k = 0; k < N; k++) {
        for (int m = 0; m < sizeof (WORD); m++) {
            printf(WORD_FORMAT, *temp);
            temp++;
        }
        printf(" ");
    }
    printf("\n");
}

void printVectorReverseEndian(const WORD *vec, const int N) {
    unsigned char *temp = (unsigned char*) vec;
    temp += sizeof(WORD)-1;
    for (int k = 0; k < N; k++) {
        for (int m = 0; m < sizeof (WORD); m++) {
            printf(WORD_FORMAT, *temp);
            temp--;
        }
        printf(" ");
        temp += sizeof (WORD);
    }
}