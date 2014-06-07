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

int main(int argc, char *argv[])
{
    int i, j;
    int flag = 0; //signal for different simulation method, Gillespie as default
    FILE *fp;
    char filename[100];
    struct Pattern *patt = NULL;

    // check command line input
    if(2 == argc)
    {
        if(0 == strcmp(argv[1], "uniform"))
        {
            flag = 1;
        }
        else
        {
            printf("Invalid input. Please enter \"uniform\" as input.\n");
            goto error;
        }
    }

    // average of realizations
    for(j=0; j<5; j++)
    {
        // initialize the system
        patt = initializePatt(flag);
        
        sprintf(filename, "./data/%i.out", j);
        fp = fopen(filename, "w");

        // simulation
        for(i=0; i<STEP; i++)
        {
            birthDeathProcess(patt);
            fprintf(fp, "%f %d %d\n",patt->time, patt->n, patt->m);
        }
        fclose(fp);
        free(patt);
    }

    return 0;
error:
    return 1;
}

