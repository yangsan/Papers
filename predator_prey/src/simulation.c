/*
 * =====================================================================================
 *
 *       Filename:  simulation.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月06日 21时36分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "simulation.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  simulation
 *  Description:  The core of simulation, input the present value of n,m,time and output
 *  according values of next time point.
 * =====================================================================================
 */

struct Pattern *initializePatt(int flag)
{
    struct Pattern *patt = malloc(sizeof(struct Pattern));
    patt->n = N/2;
    patt->m = N/2;
    patt->time = 0;
    
    if(0 == flag)
    {
        patt->timeIncrease=gillespie_time;
    }
    else
    {
        patt->timeIncrease=uniform_time;
    }

    return patt;
}

void birthDeathProcess(struct Pattern *patt)
{
    double nn = N;

    double n = patt->n;
    double m = patt->m;

    double t1; // Transition rate: (n, m) -> (n-1, m) 
    double t2; // Transition rate: (n, m) -> (n, m+1) 
    double t3; // Transition rate: (n, m) -> (n, m-1) 
    double t4; // Transition rate: (n, m) -> (n+1, m-1) 

    double lambda;

    double r;

    t1 = D1 * n;
    t2 = 2 * B * m * ( N - n - m ) / nn;
    t3 = 2 * P2 * n * m / nn + D2 * m;
    t4 = 2 * P1 * n * m / nn;

    lambda = t1 + t2 + t3 + t4;

    patt->time += patt->timeIncrease(lambda);
//    patt->time += 1;

    r = random() * lambda;

    if(r<t1)
    {
        patt->n -=1;
    }
    else if(r<t1+t2)
    {
        patt->m +=1;
    }
    else if(r<t1+t2+t3)
    {
        patt->m -=1;
    }
    else
    {
        patt->n +=1;
        patt->m -=1;
    }
}


/* -----  end of function deltat  ----- */
double gillespie_time(double lambda)
{
    return - log(1 - random())/lambda;
}

double uniform_time(double lambda)
{
    return 1.0;
}
