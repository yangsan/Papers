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

void timeSeries(Pattern *patt);

int main(int argc, char *argv[])
{
    int flag = 0; //signal for different simulation method, Gillespie as default
    Pattern *patt = NULL;

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
    patt = initializePatt(flag);

    timeSeries(patt);
    
    free(patt);
        

    return 0;
error:
    return 1;
}

void timeSeries(Pattern *patt)
{
    int i;
    FILE *fp;
    char filename[100];

//    sprintf(filename, "./data/%i.out", j);
    sprintf(filename, "./data/0.out");
    fp = fopen(filename, "w");

    // simulation
    for(i=0; i<STEP; i++)
    {
        birthDeathProcess(patt);
        fprintf(fp, "%f %d %d\n",patt->time, patt->n, patt->m);
    }
    fclose(fp);
}
