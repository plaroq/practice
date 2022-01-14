/*
 * The following functions are to perform math operations on complex
 * numbers.
 */

#include <math.h>
#include "complex.h"

//complex addition
Complex add(const Complex a, const Complex b) {
    Complex x;
    x.re = a.re + b.re;
    x.im = a.im + b.im;
    return x;
}

//complex subtraction
Complex subtract(const Complex a, const Complex b) {
    Complex x;
    x.re = a.re - b.re;
    x.im = a.im - b.im;
    return x;
}

//complex multiplication
Complex multiply(const Complex a, const Complex b) {
    Complex x;
    x.re = (a.re * b.re)-(a.im * b.im);
    x.im = (a.re * b.im)+(a.im * b.re);
    return x;
}

//complex division
Complex divide(const Complex a, const Complex b) {
    Complex x;
    x.re = ((a.re * b.re)+(a.im * b.im)) / ((b.re * b.re)+(b.im * b.im));
    x.im = ((a.im * b.re)-(a.re * b.im)) / ((b.re * b.re)+(b.im * b.im));
    return x;
}

//complex conjugate
Complex conjugate(const Complex a) {
    Complex x;
    x.re = a.re;
    x.im = (-1)*(a.im);
    return x;
}

//complex magnitude
double magnitude(const Complex a) {
    double x;
    x = sqrt((a.re * a.re)+(a.im * a.im));
    return x;
}

//angle of a complex number
double angle(const Complex a) {
    double x;
    x = atan2(a.im, a.re);
    return x;
}