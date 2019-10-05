#ifndef TRI_H
    #define TRI_H

// #define nbMeth 3
// #define tailleMax 1000000
// #define nbElem 1000 // Start from 1000 Elems till reaching taillMax
    /*function declaration.*/

    int* remplir(int *,int);
    void afficher(int *,int);
    void triBulle(int*,int);
    void triSelection(int*,int);
    void triInsertion(int*,int);

    void triRapide(int *t,int n,int d,int f);
    void triFusion(int*,int,int);
    int* copy(int*,int);
    void swap(int*,int*);
    float getTemps(void (*p)(int*,int),int *,int );

    void evaluerTemps(int,int,int);

#endif