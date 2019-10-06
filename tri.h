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
    void triFusion(int*,int);
    int* copy(int*,int);
    void swap(int*,int*);
    float getTemps(void (*p)(int*,int),int *,int );
    float **allocate2dArray(float **t,int l,int c);
    float** evaluerTemps(int,int,int);

#endif