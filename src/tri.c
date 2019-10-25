#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#include "tri.h"

#define MaxElem 1000000
#define MinElem 1000
#define NbrMeth 4

/*function definition*/
void remplir(int *t, int n)
{
    int i;
    // srand(time(NULL));
    // t = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        t[i] = rand() % (2 * n) - n;
    }

    // return t;
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
    int i, j, pos;

    // printf("\n\n--- TRI PAR SELECTION ---\n\n");

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
    // afficher(t, n);
}

void triRapideHelper(int *t, int d, int f) // f = n-1
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
        triRapideHelper(t, d, j - 1);
        triRapideHelper(t, j + 1, f);
    }
}

void triRapide(int *t, int n)
{
    triRapideHelper(t, 0, n - 1);
}
void triInsertion(int *t, int n)
{
    int i, key, j;
    // printf("\n\n--- TRI PAR INSERTION ---\n\n");

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
    // afficher(t,n);
}

void afficher(int *t, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d", t[i]);
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
    int n2 = n - m;

    int *L, *R;
    L = (int *)malloc(n1 * sizeof(int));
    R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = t[l + i];
    for (j = 0; j < n2; j++)
        R[j] = t[m + 1 + j];

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

void triFusionHelper(int *t, int l, int n)
{
    if (l < n)
    {
        int m = l + (n - l) / 2;

        triFusionHelper(t, l, m);
        triFusionHelper(t, m + 1, n);

        fusionner(t, l, m, n);
    }
}

void triFusion(int *t, int n)
{
    triFusionHelper(t, 0, n - 1);
}

void shellSort(int *t, int n)
{
    int i, j, k, tmp;
    for (i = n / 2; i > 0; i = i / 2)
    {
        for (j = i; j < n; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (t[k + i] >= t[k])
                    break;
                else
                {
                    tmp = t[k];
                    t[k] = t[k + i];
                    t[k + i] = tmp;
                }
            }
        }
    }
}



void triDenombrement(int *t,int n){
    int min=getMin(t,n);
    int max=getMax(t,n);
    int range=max-min+1;
    int *count,*output;
    int i;
    count=(int *)malloc(range*sizeof(int));
    output=(int *)malloc(n*sizeof(int));
    
    for(i=0;i<range;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[t[i]-min]++;
    }
    for(i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    for(i=n-1;i>=0;i--){
        output[count[t[i]-min]-1]=t[i];
        count[t[i]-min]--;
    }
    for(i=0;i<n;i++){
        t[i]=output[i];
    }
}
double getTemps(void (*p)(int *, int), int *t, int n)
{

    struct timeval stop, start;
    double secs = 0;

    gettimeofday(&start, NULL);

    (*p)(t, n);

    gettimeofday(&stop, NULL);

    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);

    return secs;
}

// nbrElem & tailleMax are defined variables, steps we can give it 10 for example
void evaluerTemps(int steps)
{
    int tempsLignes = ((MaxElem - MinElem) / steps) + 1;
    int *t, *tc, i, j, m;
    double **temps = NULL;
    temps = allocate2dArray(tempsLignes, NbrMeth);

    // void (*p[])(int *,int)={triSelection};
    void (*p[])(int *, int) = {triSelection,triFusion, triRapide,triDenombrement};

    // s = (int*)maloc(nbrElm*sizeof(int));

    //fill steps array
    for (j = 0, i = MinElem; i <= MaxElem; i = i + steps, j++)
    {
        printf("Nbr of Elements: %d\n", i);
        t = (int *)malloc(i * sizeof(int));
        tc = (int *)malloc(i * sizeof(int));
        remplir(t, i);
        printf("%d\t",i);
        for (m = 0; m < NbrMeth; m++)
        {
            memcpy(tc, t, i * sizeof(int));
            temps[j][m] = getTemps(p[m], tc, i);
            printf("%f\t",temps[j][m]);
        }
        printf("\n");
        free(t);
        free(tc);
    }
    // print2dArray(temps,(int) (sizeof (temps) / sizeof (temps)[0]),(int) (sizeof (temps) / sizeof (temps)[0]));
    print2dArrayToFile(temps, tempsLignes, NbrMeth, steps);
    // plot();
    // return temps;
}

// Better to prepare times array then use it in evaluterTemps

double **allocate2dArray(int l, int c)
{

    double **t;
    int i;
    t = (double **)malloc(l * sizeof(double *));

    for (i = 0; i < l; i++)
    {
        t[i] = (double *)malloc(c * sizeof(double));
    }

    return t;
}

void print2dArray(double **t, int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%f\t", t[i][j]);
        }
        printf("\n");
    }
}

void print2dArrayToFile(double **t, int r, int c, int steps)
{

    FILE *fp;
    int i, j;
    // nbrElems = (int*)malloc(r*sizeof(int));

    // for (k=0,s = MinElem; s <= MaxElem ; s+=steps,k++){
    //     nbrElems[k] = s;
    // }

    fp = fopen("matrix.dat", "w");
    for (i = 0; i < r; i++)
    {
        fprintf(fp, "%d\t", i * steps + steps);
        for (j = 0; j < c; j++)
        {
            fprintf(fp, "%f\t", t[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int getMax(int *t, int n)
{
    int max = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] > max)
            max = t[i];
    return max;
}

int getMin(int *t, int n)
{
    int min = t[0];
    for (int i = 1; i < n; i++)
        if (t[i] < min)
            min = t[i];
    return min;
}

void plot()
{
    system("gnuplot -persist gp.plt");
}