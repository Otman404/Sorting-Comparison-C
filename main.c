#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "tri.h"
 
int main()
{
    int *t,n = 50000000;
    struct timeval stop, start;
    double secs = 0;
    t = remplir(t,n);
    // afficher(t,n);
    //triFusion(t,0,n-1);

    // void (*p)(int *,int );

    // void (*t[])(int *,int) = {triBulle,triSelection,triInsertion};
    
    
    // printf("\n%f secs",getTemps(triRapide,t,n));



    

    return 0;
}