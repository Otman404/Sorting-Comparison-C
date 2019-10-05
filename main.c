#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "tri.h"
 
int main()
{
    int *t,n = 100000,duration;
    //t = remplir(t,n);
    //afficher(t,n);
    //triFusion(t,0,n-1);

    void (*p)(int *,int );
    // void (*t[])(int *,int) = {triBulle,triSelection,triInsertion};
    
    
    //duration = getTemps(triBulle,t,n);

    struct timeval stop, start;
    double secs = 0;

    gettimeofday(&start, NULL);

    sleep(5);

    gettimeofday(&stop, NULL);

    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    printf("time taken %f\n",secs);


    return 0;
}