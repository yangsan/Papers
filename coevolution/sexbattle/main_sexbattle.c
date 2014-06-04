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
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define W 0.3
#define AVERAGE 10000000

#define random() rand()/(RAND_MAX+0.0)

typedef struct Pattern{
    int n; // number of males of females
    int x; // number of A kind in males
    int y; // number of B kind in females
} Pattern;

void moran(Pattern *patt);
double local(Pattern *patt);
double payoff(double a, double b);
double halm (Pattern *patt);



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
    int n; // system size
    int i;
    double halmiton = 0;
    double halmiton1 = 0;
    double sum_moran = 0;
    double sum_local = 0;
    FILE *fp;
    char filename[100];
    srand(time(NULL));

    Pattern *patt = malloc(sizeof(struct Pattern));
    sprintf(filename, "timeseries.out");

    // initialize the system


    fp = fopen(filename, "w");

    for(n = 10; n<501; n += 10)
    {
        printf("%d\n", n);
        patt->n = n;

        //moran process
        sum_moran = 0;
        for(i=0; i<AVERAGE; i++)
        {
            patt->x = rand() % n;
            patt->y = rand() % n;

            halmiton = halm(patt);

            moran(patt);

            halmiton1 = halm(patt);
            sum_moran += halmiton1 - halmiton;
        }

        //loal process
        sum_local = 0;
        for(i=0; i<AVERAGE; i++)
        {
            patt->x = rand() % n;
            patt->y = rand() % n;

            halmiton = halm(patt);

            local(patt);

            halmiton1 = halm(patt);
            sum_local += halmiton1 - halmiton;
        }
        fprintf(fp, "%d %f %f\n", n, sum_moran/(double)AVERAGE * n, sum_local/(double)AVERAGE * n);
    }
    fclose(fp);
    free(patt);
    return 0;
}				
/* ----------  end of function main  ---------- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  moran
 *  Description:  Simulation of moran process. Taking in the address of A kind number,
 *                modify it accordingly.
 * =====================================================================================
 */
void moran(Pattern *patt)
{
    double x;
    double y;
    double pi_ma;
    double pi_mb;
    double pi_fa;
    double pi_fb;
    double fit_ma;
    double fit_mb;
    double fit_fa;
    double fit_fb;

    x = (double)patt->x / (double)patt->n;
    y = (double)patt->y / (double)patt->n;

    pi_ma = 1 - 2 * y;
    pi_mb = 2 * y - 1;
    pi_fa = 1 - 2 * x;
    pi_fb = 2 * x - 1;

    fit_ma = (1 - W + W * pi_ma) * patt->x;
    fit_mb = (1 - W + W * pi_mb) * (patt->n - patt->x);
    fit_fa = (1 - W + W * pi_fa) * (patt->n - patt->y);
    fit_fb = (1 - W + W * pi_fb) * patt->y;

    //male evolution
    //chose a male individul randomly according to the fitness
    if( random() * (fit_ma + fit_mb) < fit_ma) //first one is A
    {
        if(random() > x ) //second one is B
        {
            patt->x += 1;  // A's offspring replace B
        }
        //if the second one is also A, nothing will happen
    }
    else //first one is B
    {
        if(random() < x) //second one is A
        {
            patt->x -= 1; // B's offspring replace A
        }
        //if the second one is also B, nothing will happen
    }

    //female evolution
    //choose a female individul randomly according to the fitness
    if( random() * (fit_fa + fit_fb) < fit_fb) //first one is B
    {
        if(random() > y ) //second one is A
        {
            patt->y += 1; // B's offspring replace A
        }
    }
    else //first one is A
    {
        if(random() < y) //second one is B
        {
            patt->y -= 1; // A's offspring replace B
        }
    }

//    return halm(x, y);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  local
 *  Description:  Simulation of local rule. Taking in the address of A kind number,
 *                modify it accordingly.
 * =====================================================================================
 */
double local(Pattern *patt)
{
    double x;
    double y;
    double pi_ma;
    double pi_mb;
    double pi_fa;
    double pi_fb;

    x = (double)patt->x / (double)patt->n;
    y = (double)patt->y / (double)patt->n;

    pi_ma = 1 - 2 * y;
    pi_mb = 2 * y - 1;
    pi_fa = 1 - 2 * x;
    pi_fb = 2 * x - 1;

    //male evolution
    //chose an male individul randomly
    if(random() < x) //first one is A
    {
        if(random() > x) //second one is B
        {
            if(random() < payoff(pi_mb, pi_ma)) // A switchs its stradegy with a probobility
            {
                patt->x -= 1;
            }
        }
        //if the second one is also A, nothing wll happen
    }
    else //first male is B
    {
        if(random() < x) // second one is A
        {
            if(random() < payoff(pi_ma, pi_mb)) // B switchs its stradegy with a probobility
            {
                patt->x += 1;
            }
        }
        //if the second one is also B, nothing will happen
    }

    //female evolution
    //chose an female individul randomly
    if(random() < y) //first female is B
    {
        if(random() > y) //second female is A
        {
            if(random() < payoff(pi_fa, pi_fb)) // B switchs its stradegy with a probobility
            {
                patt->y -= 1;
            }
        }
        //if the second one is also A, nothing wll happen
    }
    else //first female is A
    {
        if(random() < y) // second one is B
        {
            if(random() < payoff(pi_fb, pi_fa)) // A switchs its stradegy with a probobility
            {
                patt->y += 1;
            }
        }
        //if the second one is also B, nothing will happen
    }

    return halm(patt);
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
    return 0.5 + 0.5 * W * (a - b) / 2.;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  halm
 *  Description:  
 * =====================================================================================
 */
double halm (Pattern *patt)
{
    double x,y;

    x = (double)patt->x / (double)patt->n;
    y = (double)patt->y / (double)patt->n;

    return - x * (1 - x) * y * (1 - y);
}		
/* -----  end of function halm  ----- */
