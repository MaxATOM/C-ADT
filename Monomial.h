#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Smonome{
double coefficient;
int exposant;
};

typedef struct Smonome monome;

monome construireMonome(double unCoefficient, int unExposant);

monome addition(monome unOp1,monome unOp2);

monome multiplication(monome unOp1,monome unOp2);

monome derivee(monome unMonome);

monome primitive(monome unMonome, double uneConstante);

double coefficient(monome unMonome);

int degre(monome unMonome);

double coefficient(monome* unMonome);

int degre(monome* unMonome);

void afficherMonome(monome unMonome,char unSymbole);

double valeurMonome(monome unMonome,int uneValeur);

char* toString(monome unMonome,char unSymbole);

bool estNul(monome unMonome);

bool estConstant(monome unMonome);