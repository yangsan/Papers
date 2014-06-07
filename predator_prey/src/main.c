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
#include <stdio.h>
#include <string.h>
#include "simulation.h"

#define STEP 300000
#define AVER 1000

void timeSeries(int flag);
void averageTimeSeries(int flag);

int main(int argc, char *argv[])
{
    int flag = 0; //signal for different simulation method, Gillespie as default

    // check command line input
    if(2 == argc)
    {
        if(0 == strcmp(argv[1], "uniform"))
        {
            flag = 1;
        }
        else
        {
            printf("Invalid input. Please enter \"uniform\" as input if you want uniform time series.\n");
            goto error;
        }
    }

//    timeSeries(flag);
    averageTimeSeries(flag);

    return 0;
error:
    return 1;
}

void timeSeries(int flag)
{
    int i;
    FILE *fp;
    char filename[100];
    Pattern *patt = NULL;

    patt = initializePatt(patt, flag);
    sprintf(filename, "./data/timeseries/0.out");
    fp = fopen(filename, "w");

    // simulation
    for(i=0; i<STEP; ++i)
    {
        birthDeathProcess(patt);
        fprintf(fp, "%f %d %d\n",patt->time, patt->n, patt->m);
    }
    fclose(fp);

    free(patt);
}

void averageTimeSeries(int flag)
{
    int j;
    FILE *fp;
    char filename[100];
    int uniform_time_intervel;
    Pattern *patt = NULL;

    for(j=0; j<AVER; ++j)
    {
//        printf("%d\n", j);
        patt = initializePatt(patt, flag);

        sprintf(filename, "./data/average/%d.out", j);
        fp = fopen(filename, "w");

        uniform_time_intervel = 0;
        // simulation
        while(uniform_time_intervel < 501)
        {
            birthDeathProcess(patt);
            if(patt->time > uniform_time_intervel)
            {
                fprintf(fp, "%d %d %d\n",uniform_time_intervel, patt->n, patt->m);
                uniform_time_intervel += 1;
            }
        }
        fclose(fp);
    }

    free(patt);
}
