#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Monomial.h"

using namespace std;

monome construireMonome (double unCoefficient, int unExposant){
monome leMonome;

    leMonome.coefficient=unCoefficient;
    leMonome.exposant=unExposant;
    return leMonome;
}

monome addition (monome unOp1,monome unOp2){
monome leResultat;

    if (unOp1.exposant!=unOp2.exposant) throw -3.0;
    leResultat.coefficient=unOp1.coefficient+unOp2.coefficient;
    leResultat.exposant=unOp1.exposant;
    return leResultat;
}

monome multiplication(monome unOp1,monome unOp2){
monome leResultat;

    leResultat.coefficient=unOp1.coefficient*unOp2.coefficient;
    leResultat.exposant=unOp1.exposant+unOp2.exposant;
    return leResultat;
}

monome derivee (monome unMonome){
monome leResultat;

    if(unMonome.exposant==0){
        leResultat.coefficient=0.;
        leResultat.exposant=0;
        return leResultat;
    }
    leResultat.coefficient=unMonome.coefficient*(double)unMonome.exposant; //(double) -> cast double: pour pouvoir multiplier différent type
    leResultat.exposant=unMonome.exposant-1;
    return leResultat;
}

monome primitive(monome unMonome, double uneConstante){
monome leResultat;

    if(unMonome.coefficient==0){
        leResultat.coefficient=uneConstante;
        leResultat.exposant=0;
    return leResultat;
    }
    if(uneConstante !=0.) throw -3.1;
    leResultat.coefficient=unMonome.coefficient/(unMonome.exposant+1);
    leResultat.exposant=unMonome.exposant+1;
    return leResultat;
}

void afficherMonome(monome unMonome,char unSymbole){
    if(unMonome.exposant==0){
        printf("%lf",unMonome.coefficient);
        return;
    }
    if(unMonome.exposant==1){
        printf("%lf%c",unMonome.coefficient,unSymbole);
        return;
    }
    if (unMonome.coefficient==1 && unMonome.exposant==1){
        printf("%lf%c%d",unMonome.coefficient,unSymbole,unMonome.exposant);
        return;
    }
    if(unMonome.coefficient==0.){
        printf("0");
        return;
    }
    if(unMonome.coefficient==1){
        printf("%c%d",unSymbole,unMonome.exposant);
        return;
    }

    else
        printf("%s\n",toString(unMonome,unSymbole));
}

double valeurMonome(monome unMonome,int uneValeur){
double leResultat;

    leResultat=unMonome.coefficient* pow(uneValeur,unMonome.exposant);
    return leResultat;
}

char* toString(monome unMonome,char unSymbole){
char* pBuffer;

    pBuffer=(char*) malloc(sizeof(char)*40);
    if (pBuffer==NULL) return NULL;
    sprintf(pBuffer, "%lf%c%d",unMonome.coefficient,unSymbole,unMonome.exposant);

    if (unMonome.coefficient == 0.) sprintf(pBuffer, "0");

    return pBuffer;
}

double coefficient(monome unMonome) {
    
    return unMonome.coefficient;
}

int degre(monome unMonome) {
    
    return unMonome.exposant;
}

double coefficient(monome* unMonome) {
    
    return unMonome->coefficient;
}

int degre(monome* unMonome) {
    
    return unMonome->exposant;
}

bool estNul(monome unMonome) {
    
    return (coefficient(unMonome) == 0.);
}

bool estConstant(monome unMonome) {
    
    return (degre(unMonome) == 0);
    
}
