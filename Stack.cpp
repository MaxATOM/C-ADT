//
//  stack.cpp
//  Exo1
//
//  Created by Maxime Carrillo on 13/01/2015.
//  Copyright (c) 2015 Maxime Carrillo. All rights reserved.
//

#include "Stack.h"

char* toString(stack aStack) {
char* pBuffer="";
    
    if (aStack.top==-1) {
        asprintf(&pBuffer,"[{}, -1]");
        return pBuffer;
    }

    for (int i=0;i<aStack.top;i++)
        asprintf(&pBuffer,"%s%f, ",pBuffer,aStack.pTab[i]);
    
    asprintf(&pBuffer, "[{%s%f}, %d]",pBuffer, aStack.pTab[aStack.top], aStack.top);
    
    return pBuffer;
    

}

char* toString(stack aStack) {
    char* pBuffer, *leNombre;
    int laTailleTotale = 0;
    
    if (aStack.top==-1) {
        pBuffer = (char*)malloc(sizeof(char)*8);
        if (pBuffer==NULL) throw -1.0;
        
        sprintf(pBuffer,"[{}, -1]");
        return pBuffer;
    }
    
    for (int j=0;j<=aStack.top;j++){
        int len = asprintf(&leNombre, "%f", aStack.pTab[j]);
        sprintf(leNombre, "%f", aStack.pTab[j]);
        laTailleTotale+=(int)len;
    }
    
    int len = asprintf(&leNombre, "%d", aStack.top);
    laTailleTotale+=(int)len;
    
    free(leNombre);
    
    
    // Pile sous forme "[{a,b,c,…},top]"
    pBuffer = (char*)malloc(sizeof(char)*laTailleTotale+6+aStack.top*2);
    
    if (pBuffer==NULL) throw -1.0;
    
    sprintf(pBuffer,"[{");
    
    for (int i=0;i<aStack.top;i++){
        sprintf(pBuffer,"%s%f, ",pBuffer,aStack.pTab[i]);
    }
    
    sprintf(pBuffer, "%s%f}, %d]",pBuffer, aStack.pTab[aStack.top], aStack.top);
    
    return pBuffer;
    
    
}

char* toString(stack aStack) {
    char* pBuffer, *pTravail;
    
    // Pile sous forme "[{a,b,c,…},top]"
    pBuffer = (char*)malloc(sizeof(char)*80);
    
    if (pBuffer==NULL) throw -1.0;
    
    if (aStack.top==-1) {
        sprintf(pBuffer,"[{}, -1]");
        return pBuffer;
    }
    
    pTravail = (char*)malloc(sizeof(char)*80);
    
    if (pTravail==NULL) throw -1.0;
    
    
    sprintf(pBuffer,"[{");
    for (int i=0;i<aStack.top;i++){
        sprintf(pTravail,"%f, ",aStack.pTab[i]);
        strcat(pBuffer, pTravail);
    }
    sprintf(pTravail, "%f}, %d]", aStack.pTab[aStack.top], aStack.top);
    strcat(pBuffer, pTravail);
    
    free(pTravail);
    return pBuffer;
    
    
}

stack createStack(int uneTaille) {
stack theStack;
    
    if (uneTaille <= 0) throw -2.1;
    
    theStack.top=-1;
    theStack.sizeMax = uneTaille;
    theStack.pTab = (float*)malloc(sizeof(float)*uneTaille);
    if (theStack.pTab == NULL) throw -1.0;
    
    return theStack;
    
}

stack createStack() {
stack theStack;
    
    theStack.top=-1;
    theStack.sizeMax=10;
    theStack.pTab = (float*)malloc(sizeof(float)*10);
    if (theStack.pTab == NULL) throw -1.0;
    
    return theStack;
    
}

stack createStack(float* unTab, int uneTailleTab, int uneTaillePile) {
    
    if (unTab == NULL) throw -1.0;
    
    stack theStack = construirePile(uneTaillePile);
    theStack.top = uneTailleTab-1;
    theStack.pTab = unTab;
    
    return theStack;
    
}

void pile(stack *aStack, float uneValeur) {

    if (aStack->top == aStack->sizeMax) throw -3.1;
    
    aStack->top++;
    aStack->pTab[aStack->top] = uneValeur;
    
}

stack pile(stack aStack, float uneValeur) {
    
        if (aStack.top == aStack.sizeMax) throw -3.1;
    
        aStack.top++;
        aStack.pTab[aStack.top] = uneValeur;
        return aStack;
    }


stack unstack(stack aStack) {
    float *leTab;

    if (aStack.top==-1) throw -2.1;

    leTab=(float*)malloc(sizeof(float)*aStack.top+1);
    for (int i=0; i<aStack.top; i++)
        leTab[i]=aStack.pTab[i];
                
        aStack.pTab=leTab;
        aStack.top--;
        return aStack;
    
    
}

void unstack(stack *aStack) {
    if (aStack->top==-1) throw -2.1;
    
    aStack->pTab[aStack->top]=NULL;
    aStack->top--;
    
    
    
}

void destroyStack(stack *pUnePile) {
    
    pUnePile->top = -1;
    //  pUnePile->sizeMax = 0;
    free(pUnePile->pTab);
    pUnePile->pTab = NULL;
}

int nbElements(stack aStack){
    int i;
    for(i=0; i<aStack.sizeMax;i++){
        if(aStack.pTab[i] == NULL) return i;
    }
    
    return i-1;
}

bool isEmpty(stack aStack){
    if(aStack.top==-1) return true;
    return false;
}

bool isFull(stack aStack){
    return (aStack.top==aStack.sizeMax-1);
    
}

int top(stack aStack){
    if(estVide(aStack)) throw -2.1;
    return aStack.top;
}

void empty(stack aStack){
    aStack.top = -1;
}

bool equals(stack unOpr1, stack unOpr2){
    
    if(unOpr1.top != unOpr2.top)return false;
    if(unOpr1.sizeMax != unOpr2.sizeMax)return false;
    
    for(int i=0; i<=unOpr1.top; i++)
        if(unOpr1.pTab[i] != unOpr2.pTab[i])return false;
    
    return true;
}

stack clone(stack aStack){
    stack theStack;
    
    theStack.top = aStack.top;
    theStack.sizeMax = aStack.sizeMax;
    
    if(aStack.top==-1) return theStack;
    
    for(int i=0; i<=aStack.top; i++)
        theStack.pTab[i] = aStack.pTab[i];
    
    return theStack;
}

float valueTop(stack aStack) {
    
    return aStack.pTab[top(aStack)];
}
