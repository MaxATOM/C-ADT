#include <stdio.h>
#include <stdlib.h>

bool estTrieCroissant (double unTab[], int uneTaille);

bool estTrieDecroissant (double unTab[], int uneTaille);

int recherche (double unTab[], int uneTaille, double uneValeur);
int* rechercher (double unTab[], int uneTaille, double uneValeur);

int rechercheDico (double unTab[], int uneTaille, double uneValeur);

void triSelection (double unTab[], int uneTaille);
double* triSelectif (double unTab[], int uneTaille);

void triBulle (double unTab[], int uneTaille);
double* triBulleVar (double unTab[], int uneTaille);

double suppElemPos (double unTab[], int uneTaille, int unePosition);

double* suppElem(double unTab[],int uneTaille, double uneValeur);

double* suppTous (double unTab[], int uneTaille, double uneValeur);

double* inserElemPos (double unTab[], int uneTaille, double uneValeur, int unePosition, int unRang);

double* inserElem (double unTab[], int uneTaille, double uneValeur);

char* toString(int uneTaille, ...);
char* toString(double * unTab,int unN);

