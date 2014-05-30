/*
 * =====================================================================================
 *
 *       Filename:  dynamic.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年05月28日 21时07分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _dynamic_h
#define _dynamic_h

#include <stdlib.h>
#define N 200
#define B 1.0
#define C 0.5
#define W 0.9
#define FRACTION 0.1

#define random() rand()/(RAND_MAX+0.0)

void moran(int *number);
void local(int *number);
double payoff(double a, double b);

#endif
