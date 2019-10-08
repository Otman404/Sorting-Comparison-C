#ifndef TRI_H
    #define TRI_H

// #define nbMeth 3
// #define tailleMax 1000000
// #define nbElem 1000 // Start from 1000 Elems till reaching taillMax
    /*function declaration.*/

    void remplir(int *,int);
    void afficher(int *,int);
    void triBulle(int*,int);
    void triSelection(int*,int);
    void triInsertion(int*,int);

    // void triRapide(int *t,int n,int d,int f);
    void triRapide(int *t,int n);
    void triRapideHelper(int *t,int d, int f); // f = n-1
    void triFusion(int*,int);
    void triFusionHelper(int*,int,int);
    int* copy(int*,int);
    void swap(int*,int*);
    double getTemps(void (*p)(int*,int),int *,int );
    double **allocate2dArray(int l,int c);
    void print2dArray(double **t,int r,int c);
    void print2dArrayToFile(double **t,int r,int c);
    void evaluerTemps(int);

#endif