#include <stdio.h>
#include "tri.h"
 
int main()
{
    int *t,n = 10;

    t = remplir(t,n);
    afficher(t,n);
    triFusion(t,0,n-1);
    afficher(t,n);

    
 
    return 0;
}