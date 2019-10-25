#ifndef TRI_H
    #define TRI_H

// #define nbMeth 3
// #define tailleMax 1000000
// #define nbElem 1000 // Start from 1000 Elems till reaching taillMax
    /*function declaration.*/

    void remplir(int *,int);
    void afficher(int *,int);
    void triBulle(int*,int);
    void triSelection(int*,int); //O(n^2)
    void triInsertion(int*,int); //O(n^2)

    // void triRapide(int *t,int n,int d,int f);
    void triRapide(int *t,int n); //O(nlogn)
    void triRapideHelper(int *t,int d, int f); // f = n-1
    void triFusion(int*,int); //O(nlogn)
    void triFusionHelper(int*,int,int);
    void shellSort(int *, int );
    void triRadix(int *t, int n);//O(kn)
    void triDenombrement(int *t,int n);//O(k+n)
    int* copy(int*,int);
    void swap(int*,int*);
    int getMax(int *, int );
    int getMin(int *t, int n);
    void plot();
    double getTemps(void (*p)(int*,int),int *,int );
    double **allocate2dArray(int l,int c);
    void print2dArray(double **t,int r,int c);
    void print2dArrayToFile(double **,int ,int ,int);
    void evaluerTemps(int);

#endif