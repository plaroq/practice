/*
 * This header file defines variables to be used in the project.
 * Two functions are declared and a structure for Vector is established.
 */

/* 
 * File:   vectorMath.h
 * Author: Philippe Larocque
 *
 * Created on March 10, 2017, 6:48 PM
 */

#ifndef VECTORMATH_H
#define VECTORMATH_H

//constants WORD, WORD_FORMAT and VMAX defined here
//#ifndef WORD
typedef double WORD
//#endif

//#ifndef WORD_FORMAT
#define WORD_FORMAT "%10.4lf "
//#endif

#define VMAX 20

//structure for Vector type
typedef struct vector {
    int len;
    WORD item[VMAX];
} Vector;

//declaration for functions vectorMath and printVector
Vector *vectorMath(const Vector v1, const Vector v2, Vector *result,
        const char op);
void printVector(const Vector v);

#endif /* VECTORMATH_H */