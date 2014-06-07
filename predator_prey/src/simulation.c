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
 *         Name:  initializePatt
 *  Description:  A method to initialize a patt.
 *                Taking in a pointer to struct Pattern, if the pointer is NULL, allocate
 *                the memory then initialize it; if not, only initialize it.
 *                Choosing different time intervals according to the flag.
 * =====================================================================================
 */

Pattern *initializePatt(Pattern *patt, int flag)
{
    // if the pointer is NULL, allocate the memory
    if(NULL == patt)
    {
        patt = malloc(sizeof(Pattern));
    }
    // then initialize it
    patt->n = N/2;
    patt->m = N/2;
    patt->time = 0;
    
    // choose the time interal method accordingly
    if(NULL == patt->timeIncrease)
    {
        if(0 == flag)
        {
            patt->timeIncrease=gillespieTime;
        }
        else
        {
            patt->timeIncrease=uniformTime;
        }
    }

    return patt;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  birthDeathProcess
 *  Description:  The core of simulation. Taking in a patt, apply the changes according
 *                to algorithm.
 * =====================================================================================
 */

void birthDeathProcess(Pattern *patt)
{
    double nn = N; // cast N to double

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

    // calculate lambda according to Gillespie algorithm
    lambda = t1 + t2 + t3 + t4;

    // increase time
    patt->time += patt->timeIncrease(lambda);

    // choose a event randomly
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gillespieTime
 *  Description:  Return time interval accoring to Gillespie algorithm.
 * =====================================================================================
 */

double gillespieTime(double lambda)
{
    return - log(1 - random())/lambda;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  uniformTime
 *  Description:  Return uniform time interval.
 * =====================================================================================
 */

double uniformTime(double lambda)
{
    return 1.0;
}
