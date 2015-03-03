//
//  polynome.cpp
//  Exo_Poly_Xcode
//
//  Created by Maxime Carrillo on 03/12/2014.
//  Copyright (c) 2014 Maxime Carrillo. All rights reserved.
//

#include "Polynomial.h"

polynome construirePolynome () {
    
    monome** lepResultat;
    
    lepResultat = (monome **)malloc(sizeof(monome*)*2);
    if (lepResultat == NULL) throw -1.0;
    
    monome* lepMonome;
    *lepMonome = construireMonome(0., 0);
    lepResultat[0] = lepMonome;
    lepResultat[1] = NULL;
    return lepResultat;
}

int arite(polynome unPolynome) {
int i;
    
    i=0;
    while (unPolynome[i++] != NULL);
    return i;
}

int degre(polynome unPolynome) {
    
    return degre(unPolynome[0]);
}

bool estNul(polynome unPolynome) {
    
    return (estNul(*unPolynome[0]));
}


bool estConstant(polynome unPolynome) {
    
    return (arite(unPolynome) == 1 && estConstant(*unPolynome[0]));
}
void addition(polynome unPolynome, monome unMonome) {
    
    if (unPolynome == NULL) throw -2.1;
    
    // Cas particulier : même exposant, donc addition des coeff
    
    unPolynome = (monome **)malloc(sizeof(arite(unPolynome))+2);
    monome *leDernierMonome;
    *leDernierMonome = *unPolynome[arite(unPolynome)];
    if (unMonome.exposant >  (int)leDernierMonome->exposant) {
        unPolynome[arite(unPolynome)] = &unMonome;
        unPolynome[arite(unPolynome)+1]= NULL;
    }
    
    
}

monome* obtenirMonome(polynome unPolynome) {
    
    static int i = -1;
    return unPolynome[i++%arite(unPolynome)];
    

}

char* toString(polynome unPolynome,char unSymbole){
    char* pBuffer;

    pBuffer=(char*) malloc(sizeof(char)*4*arite(unPolynome));
    if (pBuffer==NULL) throw -1.0;
    sprintf(pBuffer, "%s", toString(*unPolynome[0], 'X'));
    for (int i=1; i<arite(unPolynome);i++) {
//        sprintf(pBuffer, "%s%s%lf%c%d",pBuffer,(coefficient(unPolynome[i])>=0.) ? "+" : "",coefficient(unPolynome[i]),unSymbole,degre(unPolynome[i]));
        strcat(pBuffer, " + ");
        strcat(pBuffer, toString(*unPolynome[i], 'X'));
    }
    
    return pBuffer;
}


