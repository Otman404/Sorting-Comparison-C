#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tri.h"

/*function definition*/
int *remplir(int *t, int n)
{
    int i;
    srand(time(NULL));
    t = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        t[i] = rand() % (2 * n) - n;
    }

    return t;
}

void triBulle(int *t, int n)
{
    int i, j;
    //printf("\n\n--- TRI A BULLE ---\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (t[i] > t[j])
            {
                // tmp = t[i];
                // t[i] = t[j];
                // t[j] = tmp;
                swap(&t[i], &t[j]);
            }
        }
    }
    //afficher(t, n);
}
void triSelection(int *t, int n)
{
    int  i, j, pos;

    printf("\n\n--- TRI PAR SELECTION ---\n\n");

    for (i = 0; i < (n - 1); i++)
    {
        pos = i;

        for (j = i + 1; j < n; j++)
        {
            if (t[pos] > t[j])
                pos = j;
        }
        if (pos != i)
        {
            //   tmp = t[i];
            //   t[i] = t[pos];
            //   t[pos] = tmp;
            swap(&t[i], &t[pos]);
        }
    }
    afficher(t, n);
}

void triRapide(int *t, int n, int d, int f)
{
    int i, j, pivot, tmp;
    if (d < f)
    {
        pivot = d;
        i = d;
        j = f;
        while (i < j)
        {
            while (t[i] <= t[pivot] && i < f)
                i++;
            while (t[j] > t[pivot])
                j--;
            if (i < j)
            {
                // tmp=t[i];
                // t[i]=t[j];
                // t[j]=tmp;
                swap(&t[i], &t[j]);
            }
        }
        tmp = t[pivot];
        t[pivot] = t[j];
        t[j] = tmp;
        triRapide(t, n, d, j - 1);
        triRapide(t, n, j + 1, f);
    }
}


void triInsertion(int *t, int n)
{
    int i, key, j;  
    printf("\n\n--- TRI PAR INSERTION ---\n\n");

    for (i = 1; i < n; i++) 
    {  
        key = t[i];  
        j = i - 1;  

        while (j >= 0 && t[j] > key) 
        {  
            t[j + 1] = t[j];  
            j = j - 1;  
        }  
        t[j + 1] = key;  
    }  
    afficher(t,n);

}

void afficher(int *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d",t[i]);
        // printf("t[%d] = %3d\n",i,t[i]);
    }
    printf("\n");
}

int *copy(int *t, int n)
{
    int *arr, i;
    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        arr[i] = t[i];
    return arr;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}



void fusionner(int *t, int l, int m, int n) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  n - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = t[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = t[m + 1+ j]; 
  
    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            t[k] = L[i]; 
            i++; 
        } 
        else
        { 
            t[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        t[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        t[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


void triFusion(int *t, int l, int n) 
{ 

    if (l < n) 
    { 
        int m = l+(n-l)/2; 
  
        triFusion(t, l, m); 
        triFusion(t, m+1, n); 
  
        fusionner(t, l, m, n); 
    } 
} 


float getTemps(void (*p)(int*,int),int *t,int n ){
    
    clock_t start;

    start = clock();

    (*p)(t,n);

    return clock() - start;
}
