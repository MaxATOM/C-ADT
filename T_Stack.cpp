//
//  main.cpp
//  Exo1
//
//  Created by Maxime Carrillo on 13/01/2015.
//  Copyright (c) 2015 Maxime Carrillo. All rights reserved.
//

#include <iostream>
#include "Stack.h"

int evalNPI(char* uneExpression, int desValeurs[]) {
float unOp1, unOp2;
    stack aStack = construirePile((int)strlen((uneExpression)));
    
    
    for (int i=0; i<strlen(uneExpression); i++) 
        if (isalpha(uneExpression[i]))
            aStack = empiler(aStack, (float)desValeurs[uneExpression[i]-'a']);
        
        else {
            
            unOp2 = valeurSommet(aStack);
            aStack=depiler(aStack);
            unOp1 = valeurSommet(aStack);
            aStack=depiler(aStack);

        switch (uneExpression[i]) {
            case '+':
                aStack=empiler(aStack, unOp1+unOp2);
                break;
            case '-':
                aStack=empiler(aStack, unOp1-unOp2);
                break;
            case '*':
                aStack=empiler(aStack, unOp1*unOp2);
                break;
            case '/':
                aStack=empiler(aStack, unOp1/unOp2);
                break;
            default:
                break;
        }
            
        }
        
    
    
    return valeurSommet(aStack);
}


int evalInfixe(char* uneExpression, int desValeurs[]) {
    float unOp1, unOp2;
    char *uneExpr = (char*)malloc(sizeof(char)*strlen(uneExpression));
    
    
    for (int i=0; i<strlen(uneExpression); i++) {
        
        if (uneExpression[i] == '(') {
            
            strcat(uneExpr, &uneExpression[i+1]);
            strcat(uneExpr, &uneExpression[i+3]);
            strcat(uneExpr, &uneExpression[i+2]);
            printf("%s", uneExpr);

            
        }
    }
    
    return 0;
}



int main(int argc, const char * argv[]) {

    stack aStack = createStack();
    pile(&aStack, 1.);
    pile(&aStack, 2.);
    pile(&aStack, 3.);

    stack aStack2 = createStack();
    aStack2 = pile(aStack2, 1.);
    aStack2 = pile(aStack2, 2.);
    aStack2 = pile(aStack2, 3.);
    
    stack aStack3= unstack(aStack2);
    stack aStack4=aStack2;
    
    unstack(&aStack4);

    printf("%s\n", toString(aStack));
    printf("%s\n", toString(aStack2));
    printf("%s\n", toString(aStack3));
    printf("%s\n", toString(aStack4));
    
    float leTab[5]= {0.f,1.f,2.f,3.f,4.f};
    stack aStack5 = createStack(leTab, 5,10);
    printf("%s\n", toString(aStack5));
    
    float leTab2[1]= {4.f};
    stack aStack6 = createStack(leTab2, 1,10);
    printf("%s\n", toString(aStack6));
    
    int npiVal[3] = {2,7,3};
    int npi = evalNPI("ab+c+", npiVal);
    
    printf("%d\n", npi);

    int infVal[4] = {4,2,5,3};

    int infixe = evalInfixe("(4+2)*(5-3)", infVal);

}
