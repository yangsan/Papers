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
void multipleTimeSeries(int flag);

int main(int argc, char *argv[])
{
    if(2 == argc)
    {
        switch(argv[1][0])
        {
            // time series under Gillespie algorithm
            case '1':
                timeSeries(0);
                break;

            // time series under unifor time intervals
            case '2':
                timeSeries(1);
                break;

            // time series over 100 average under Gillespie algorithm
            case '3':
                multipleTimeSeries(0);
                break;

            default:
                goto error;
                break;
        }
    }
    else
    {
        goto error;
    }

    return 0;
error:
    printf("Invalid input. Need help? Enter:\n");
    printf("1 : Show time series in Gillespie algorithm.\n");
    printf("2 : Show time series in uniform time intervals.\n");
    printf("3 : Show time series under Gillespie algorithm over 100 average.\n");
            
    return 1;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  timeSeries
 *  Description:  Taking in a flag for different algorithm.
 *                Apply birthDeathProcess method to do the simulation and write the 
 *                result into a file.
 * =====================================================================================
 */
void timeSeries(int flag)
{
    int i;
    FILE *fp;
    char filename[100];
    Pattern *patt = NULL;

    // intialize patt to store data
    patt = initializePatt(patt, flag);
    sprintf(filename, "./data/timeseries/0.out");
    fp = fopen(filename, "w");

    // simulation for STEP time steps
    for(i=0; i<STEP; ++i)
    {
        // apply the simulation method
        birthDeathProcess(patt);
        // write result into file
        fprintf(fp, "%f %f %f\n",patt->time, patt->n/(double)N, patt->m/(double)N);
    }
    fclose(fp);

    free(patt);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  multipltTimeSeries
 *  Description:  Apply birthDeathProcess method to do the simulation for AVER times
 *                and write the results into files.
 * =====================================================================================
 */
void multipleTimeSeries(int flag)
{
    int j;
    FILE *fp;
    char filename[100];
    int uniform_time_intervel; // an integer time intervel
    Pattern *patt = NULL;

    // do the simluation for AVER times
    for(j=0; j<AVER; ++j)
    {
        // initialize patt everytime
        patt = initializePatt(patt, flag);

        // organize the filenames
        sprintf(filename, "./data/average/%d.out", j);
        fp = fopen(filename, "w");

        uniform_time_intervel = 0;
        // simulation
        while(uniform_time_intervel < 501)
        {
            birthDeathProcess(patt);
            // only print out result when time reach a integer level so sample, for the
            // convenience of averaging
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
