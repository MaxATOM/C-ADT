//
//  polynome.h
//  Exo_Poly_Xcode
//
//  Created by Maxime Carrillo on 03/12/2014.
//  Copyright (c) 2014 Maxime Carrillo. All rights reserved.
//

#include <stdio.h>
#include "Monomial.h"

typedef monome** polynome;

polynome construirePolynome (int unDegree, monome *pUnTab);
char *toString(polynome unPolynome);
void addition(polynome unPolynome, monome unMonome);
polynome addition(polynome unOp1, polynome unOp2);
polynome multiplication(polynome unOp1, polynome unOp2);
polynome multiplication(polynome unOp1, monome unOp2);
polynome multiplication(monome unOp2, polynome unOp1);
polynome multiplication(polynome unOp1, double unOp2);
polynome calcul(polynome unOp1, double unOp2);
double *racine(polynome unPolynome);

int arite(polynome unPolynome);

int degre(polynome unPolynome);

bool estNul(polynome unPolynome);

bool estConstant(polynome unPolynome);

monome* obtenirMonome(polynome unPolynome);