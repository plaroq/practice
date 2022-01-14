/*
 * Header file declaring mean and ssdev functions
 * that can be found in statistics.c
 */

/* 
 * File:   statistics.h
 * Author: Philippe Larocque
 *
 * Created on February 16, 2017, 2:24 PM
 */

#ifndef STATISTICS_H
#define STATISTICS_H

double mean (const double sum, const int count);
double ssdev (const double sum, const double sumsq, const int count);

#endif /* STATISTICS_H */

