#ifndef TRI_H
    #define TRI_H
     
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
    
    void evaluerTemps();

#endif