#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "tri.h"

int j;
int main()
{

    // int *t,n=100000;
    // t = (int*)malloc(n*sizeof(int));
    // remplir(t,n);
    // afficher(t,n);
// struct timeval stop, start;
//     double secs = 0;

//     gettimeofday(&start, NULL);
//     triDenombrement(t,n);
//         gettimeofday(&stop, NULL);

//         secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
//     printf("\n\n%f\n\n",secs);
    // afficher(t,n);

    evaluerTemps(1000);

    plot();

    return 0;
}