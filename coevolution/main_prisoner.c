/*
 * =====================================================================================
 *
 *       Filename:  main_prisoner.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月28日 21时04分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "main_prisoner.h"
#include "dynamic.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main (int argc, char *argv[])
{
    int defectors; //numbers of defectors in system
    double nn;
    int i;
    FILE *fp;
    char filename[100];

    nn = N;

    //initialize the system
    defectors = (int)(FRACTION * N);

    sprintf(filename, "./data/prisoner.out");
    fp = fopen(filename, "w");
    //do the simulation
    for(i=0; i < STEP; i++)
    {
        moran(&defectors);
//        printf("%d\n", defectors);
        if(defectors == N) break;
        fprintf(fp, "%f\n", defectors/nn);
    }
    fclose(fp);


    return 0;
}				
/* ----------  end of function main  ---------- */
