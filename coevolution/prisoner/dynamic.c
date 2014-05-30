/*
 * =====================================================================================
 *
 *       Filename:  dynamic.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月28日 21时27分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "dynamic.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  moran
 *  Description:  Simulation of moran process. Taking in the address of A kind number,
 *                modify it accordingly.
 * =====================================================================================
 */
void moran(int *number)
{
    int i; // number of A kind
    double ifraction; 
    double pi_a; // average payoff of A kind
    double pi_b; // same
    double fit_a; // fitness of A kind
    double fit_b; // same

    i = *number;
    ifraction = i / (double)N; // fraction of A kind in system

    pi_a = (C * (i - 1) + (B + C) * (N - i))/(double)(N - 1);
    pi_b = (B * (N - i - 1))/(double)(N - 1);
    fit_a = (1 - W + W * pi_a) * i;
    fit_b = (1 - W + W * pi_b) * (N - i);

    //chose a individul randomly according to the fittness
    if( random() * (fit_a + fit_b) < fit_a) //first one is A
    {
        if(random() > ifraction ) //second one is B
        {
            *number += 1;  // A's offspring replace B
        }
        //if the second one is also A, nothing will happen
    }
    else //first one is B
    {
        if(random() < ifraction) //second one is A
        {
            *number -= 1; // B's offspring replace A
        }
        //if the second one is also B, nothing will happen
    }

}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  local
 *  Description:  Simulation of local rule. Taking in the address of A kind number,
 *                modify it accordingly.
 * =====================================================================================
 */
void local(int *number)
{
    int i; // number of A kind
    double ifraction; // fraction of  A kind
    double pi_a; // payoff of A kind
    double pi_b; // same

    i = *number;
    ifraction = i / (double)N;

    pi_a = (C * (i - 1) + (B + C) * (N - i))/(double)(N - 1);
    pi_b = (B * (N - i - 1))/(double)(N - 1);

    //chose a individul randomly
    if(random() < ifraction) //first one is A
    {
        if(random() > ifraction ) //second one is B
        {
            if(random() < payoff(pi_b, pi_a)) // A switchs its stradegy with a probobility
            {
                *number -= 1;
            }
        }
        //if the second one is also A, nothing wll happen
    }
    else //first one is B
    {
        if(random() < ifraction) // second one is A
        {
            if(random() < payoff(pi_a, pi_b)) // B switchs its stradegy with a probobility
            {
                *number += 1;
            }
        }
        //if the second one is also B, nothing will happen
    }
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  payoff
 *  Description:  Taking in payoff of a and b, return the probability of b switching its
 *                strategy to a.
 * =====================================================================================
 */
double payoff(double a, double b)
{
    return 0.5 + 0.5 * W * (a - b) / (B + C);
}
