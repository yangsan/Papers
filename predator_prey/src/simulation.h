/*
 * =====================================================================================
 *
 *       Filename:  simulation.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月06日 21时37分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <math.h>

#ifndef _simulation_h
#define _simulation_h

#define N 3200
#define B 0.1
#define D1 0.1
#define D2 0.0
#define P1 0.25
#define P2 0.05

#define random() rand()/(RAND_MAX+1.0)

// define a data structure in convinience of passing data
struct Pattern{
    int n;
    int m;
    double time;
    double (*timeIncrease)(double lambda);
};

void birthDeathProcess(struct Pattern *patt);
double gillespie_time(double lambda);
double uniform_time(double lambda);
struct Pattern *initializePatt(int flag);

#endif
