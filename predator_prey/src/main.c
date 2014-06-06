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

#define N 3200
#define B 0.1
#define D1 0.1
#define D2 0.0
#define P1 0.25
#define P2 0.05


#define random() rand()/(RAND_MAX+1.0)


int result(int *margin, int *number);
int ran(double randomnumber, double dn, double dm);

int main(int argc, char *argv[])
{
    int n; // number of predators
    int m; // number of prey
    int e; // number of empty space
    int i, j, k, ii;
    double nn;
    int margin[3] = {0, 0, 0}; // store change of n,m
    int number[2] = {0, 0}; // store n,m,e for convenience of passing variables

    FILE *fp;
    char filename[100];

    nn = N;

    // average of 1000 realization
    for(ii=0; ii<2; ii++)
    {
        // initialize the system
        n = 1600; // half of the system are predators
        m = 1600; // half of the system are prey
        e = N - m - n;

        sprintf(filename, "./data/%i.out", ii);
        fp = fopen(filename, "w");

        // 50000 time steps
        for(i=0; i<50000; i++)
        {
            number[0] = n;
            number[1] = m;

            // making small increcments of time
            for(j=0; j<20; j++)
            {
                for(k=0; k<3; k++)
                {
                    margin[k] = 0;
                }

                result(margin, number); // do the simulation

                // apply the change of n,m,e
                n += margin[0];
                m += margin[1];
                e += margin[2];
            }
            fprintf(fp, "%f %f %f\n",n/nn,m/nn,e/nn);
        }
        fclose(fp);

    }

    return 0;
}

/*
 * ===FUNCTION
===================================================================
*          Name:    result
*   Description:    The core of simulation.Take n,m,e in apply the rule of 
*                   birth-death process and return the change in n,m,e.
===================================================================
*/

int result(int *margin, int *number)
{
    double f1;
    double f2;
    double nn;
    int a,b;
    double r;

    nn = N;

    f1 = number[0] / nn; // the percentage of n in system
    f2 = number[1] / nn; // the percentage of m in system
    a = ran(random(), f1, f2); // choose a agent randomly
    b = ran(random(), f1, f2); // choose another agent randomly

    if(a==0)
    {
        //predator die
        if(random()<D1)
        {
            margin[0] -= 1;
            margin[2] += 1;
        }
    }
    else if(a==1)
    {
        //prey die
        if(random()<D2)
        {
            margin[1] -= 1;
            margin[2] += 1;
            printf("Hello");
        }
    }

    // a+b == 1 with AB, predate proccess
    if(a+b == 1)
    {
        r = random();
        if(r<P1)
        {
            margin[1] -= 1;
            margin[0] += 1;
        }
        else if(r>P1 && r<P1+P2)
        {
            margin[1] -= 1;
            margin[2] += 1;
        }
    }
    // a+b == 3 with BE, prey birth proccess
    else if(a+b == 3)
    {
        if(random() < B)
        {
            margin[2] -= 1;
            margin[1] += 1;
        }
    }

    return 0;
}


/*
 * ===FUNCTION
===================================================================
*          Name:    ran
*   Description:    Randomly choose an agent from system.
*                   A = 0
*                   B = 1
*                   E = 2
===================================================================
*/
int ran(double randomnumber, double dn, double dm)
{
    // if a is A return 0
    if(randomnumber<dn)
    {
        return 0;
    }
    // if a is B return 1
    else if(randomnumber>dn && randomnumber<(dn + dm))
    {
        return 1;
    }
    // if a is E return 2
    else
    {
        return 2;
    }
}
