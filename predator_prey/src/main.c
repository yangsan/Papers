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
#include "simulation.h"




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
        patt->n = N/2; // half of the system are predators
        patt->m = N/2; // half of the system are prey
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
