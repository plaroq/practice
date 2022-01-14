/*
 * This program will read a text file and calculate the mean and standard
 * deviation. These values will be displayed to the user on the screen and
 * saved into a new file called Results_xxx.txt, where xxx is the name of
 * the original file. There are several error checks to ensure the files are
 * opened correctly.
 */

/* 
 * File:   statsMain.c
 * Author: Philippe Larocque
 *
 * Created on February 16, 2017, 2:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "statistics.h"

//function declaration
void printStats(FILE *dest, const int count, const double mean,
        const double ssdev);

int main(int argc, char** argv) {

    //error check if console has two arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    //declare and open the file to be read
    FILE *inFile;
    inFile = fopen(argv[1], "r");
    
    //error message if file can't be opened
    if (inFile == NULL) {
        fprintf(stderr,"Unable to open input file \"%s\"\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    //concatenating the text 'Results_' and the name of the file
    const char OUT_PREFIX[] = "Results_";
    char *outName = malloc(strlen(argv[1]) + strlen(OUT_PREFIX) + 1);
    strcpy(outName, OUT_PREFIX);
    strcat(outName, argv[1]);

    //declare and open the file to be written to
    FILE *outFile;
    outFile = fopen(outName, "w");
    
    //error message if file can't be written to
    if (outFile == NULL) {
        fprintf(stderr,"Unable to write to output file \"%s\"\n", outName);
        return EXIT_FAILURE;
    }

    //variables to be used to calculate mean and standard deviation
    double x=0, tot=0, totsq=0;
    int num=0;
    
    //while loop as long as there are more numbers to be read in the file
    //variables are incremented accordingly for each iteration
    while (fscanf(inFile, "%lf", &x) == 1) {
        num++;
        tot += x;
        totsq += x*x;
    }

    //error message if the file has less than two values
    if (num < 2) {
        fprintf(stderr,"The file contains less than two values.\n");
        return EXIT_FAILURE;
    } 
    
    //mean and standard deviation are calculated and sent to the screen
    printStats(stdout, num, mean(tot, num), ssdev(tot, totsq, num));
    
    //mean and standard deviation are calculated and sent to the output file
    printStats(outFile, num, mean(tot, num), ssdev(tot, totsq, num));
    
    //both files are closed
    fclose(inFile);
    fclose(outFile);
    
    return EXIT_SUCCESS;
}

//function will print a message containing the mean and standard deviation
//to a particular destination
void printStats(FILE *dest, const int count, const double mean,
        const double ssdev) {
    fprintf(dest, "%d Values, Mean = %.5lf, Sample Standard "
            "Deviation = %.5lf\n", count, mean, ssdev);
}