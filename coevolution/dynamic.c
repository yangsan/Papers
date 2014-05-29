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

void moran(int *number)
{
    int i;
    double nn;
    double pi_a;
    double pi_b;
    double fit_a;
    double fit_b;

    i = *number;
    nn = i / (double)N;

    pi_a = (C * (i - 1) + (B + C) * (N - i))/(double)(N - 1);
    pi_b = (B * (N - i - 1))/(double)(N - 1);
    fit_a = (1 - W + W * pi_a) * i;
    fit_b = (1 - W + W * pi_b) * (N - i);

    //chose a individul randomly according to the fittness
    if( random() * (fit_a + fit_b) < fit_a) //first one is A
    {
        if(random() > nn ) //second one is B
        {
            *number += 1; 
        }
        //if the second one is also A, nothing happens
    }
    else //first one is B
    {
        if(random() < nn) //second one is A
        {
            *number -= 1;
        }
        //if the second one is also B, nothing happens
    }

}

void local(int *number)
{
    int i;
    double nn;
    double pi_a;
    double pi_b;

    i = *number;
    nn = i / (double)N;

    pi_a = (C * (i - 1) + (B + C) * (N - i))/(double)(N - 1);
    pi_b = (B * (N - i - 1))/(double)(N - 1);

    //chose a individul randomly according to the fittness
    if(random() < nn) //first one is A
    {
        if(random() > nn ) //second one is B
        {
            if(random() < payoff(pi_b, pi_a))
            {
                *number -= 1;
            }
        }
        //if the second one is also A, nothing happens
    }
    else //first one is B
    {
        if(random() < nn)
        {
            if(random() < payoff(pi_a, pi_b)) //second one is A
            {
                *number += 1;
            }
        }
        //if the second one is also B, nothing happens
    }
}

double payoff(double a, double b)
{
    return 0.5 + 0.5 * W * (a - b) / (B + C);
}
