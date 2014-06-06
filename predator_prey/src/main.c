/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月17日 09时59分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
};

int simulation(struct Pattern *patt);
inline double deltat(double lambda);


int main(int argc, char *argv[])
{
    struct Pattern *patt = malloc(sizeof(struct Pattern));
    int i, j;

    FILE *fp;
    char filename[100];

    // average of realizations
    for(j=0; j<5; j++)
    {
        // initialize the system
        patt->n = 1600; // half of the system are predators
        patt->m = 1600; // half of the system are prey
        patt->time = 0;

        sprintf(filename, "./data/%i.out", j);
        fp = fopen(filename, "w");

        // simulation
        for(i=0; i<300000; i++)
        {
            simulation(patt);
            fprintf(fp, "%f %d %d\n",patt->time, patt->n, patt->m);
        }
        fclose(fp);
    }

    free(patt);
    return 0;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  simulation
 *  Description:  The core of simulation, input the present value of n,m,time and output
 *  according values of next time point.
 * =====================================================================================
 */

int simulation(struct Pattern *patt)
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

    patt->time += deltat(lambda);
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

    return 0;
}


/* -----  end of function deltat  ----- */
inline double deltat(double lambda)
{
    return - log(1 - random())/lambda;
}
