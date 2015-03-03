//
//  stack.h
//  Exo1
//
//  Created by Maxime Carrillo on 13/01/2015.
//  Copyright (c) 2015 Maxime Carrillo. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


struct Sstack{
    float* pTab;
    int top;
    int maxSize;
};

typedef struct Sstack stack;

//Fonctions standards

stack createStack(); //Constructeur par default
stack createStack(int uneTaille); //Constructeur normal
stack createStack(float* unTab, int uneTailleTab, int uneTailleStack); // Constructeur de test

void destroyStack(stack);
char* toString(stack);

//Getters

int top(stack);
int nbElements(stack);
bool isEmpty(stack);
bool isFull(stack);

//Services

void pile(stack *uneStack, float uneValeur);
stack pile(stack uneStack, float uneValeur);

float valueTop(stack uneStack);

void unstack(stack *uneStack);
stack unstack(stack uneStack);

void empty(stack);
stack clone(stack);
bool equals(stack, stack);
