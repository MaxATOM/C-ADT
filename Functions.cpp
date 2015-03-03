#include "Functions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdarg>

using namespace::std;


double* triBulleVar (double unTab[], int uneTaille) {
    int i, j, k;
    double leSauv;
    double* leTab = (double *)malloc(sizeof(double)*uneTaille);
    
    if (unTab==NULL) throw -2.1;
    if (uneTaille <=0) throw -2.2;
    
    if (uneTaille == 1) return unTab;
    
    for (i=0; i<uneTaille; i++)
        leTab[i]=unTab[i];
    
    for (k= 0;k < uneTaille - 1; k++)
        
        for ( j = k + 1; j < uneTaille; j++)
            
            if (leTab[k] > leTab[j]) {
                leSauv = leTab[k] ;
                leTab[k] = leTab[j];
                leTab[j] = leSauv;
            }
    
    return leTab;
    
}

double* suppTous(double unTab[],int uneTaille, double uneValeur){
    double* pLeResultat = nullptr;
    int i=0;
    
    if(uneTaille<=0)throw -2.2;
    
    while(unTab[i]==unTab[i+1]){
        i++;
    }
    if(i-1==uneTaille)throw -2.3;
    /* si unTab avec que des 3 et on veut supprimer tous les 3 */
    
    
    for(i=0;i<=uneTaille;i++){
        if(unTab[i]==uneValeur){
            pLeResultat=suppElem(&unTab[i],uneTaille,i);
        }
    }
    return pLeResultat;
}


int recherche(double unTab[], int uneTaille, double unElement){
    int i;
    
    if (uneTaille<=0) throw -2.2;
    for (i=0; i<uneTaille; i++){
        if (unTab[i]==unElement) return i;
    }
    return -1;
}

bool estTrieDecroissant (double unTab[], int uneTaille){
    int i;
    if (uneTaille<=0) throw -2.1;
    if (uneTaille==1) return true;
    
    for(i=0;i<uneTaille;i++){
        if(unTab[i]<=unTab[i+1]) return false;
    }
    return true;
}

double* triSelectif(double unTab[], int uneTaille){
    int i, j, leIndiceMin;
    double leTab[uneTaille];
    double leTampon;
    double* pleTab;
    
    pleTab=&unTab[0];
    
    for(i=0; i<uneTaille; i++)
        leTab[i]=unTab[i];
    
    if(unTab[0]==NULL)  throw -2.1;
    
    if(uneTaille<=0)    throw -2.2;
    
    if(uneTaille==1)    return pleTab+uneTaille;
    
    
    for(i=0; i<uneTaille-1; i++){
        leIndiceMin=i;
        leTampon=leTab[i];
        for(j=i+1; j<uneTaille; j++){
            if(leTab[j]<leTampon){
                leIndiceMin=j ;
                leTampon=leTab[j];
            }
        }
        leTab[leIndiceMin]=leTab[i];
        leTab[i]=leTampon;
    }
    
    for(i=0; i<uneTaille; i++)
        unTab[i]=leTab[i];
    
    pleTab=&unTab[0];
    
    return pleTab;
}

double suppElemPos(double unTab[], int uneTaille, double uneValeur){
    
    int i;
    int leNbElem=uneTaille;
    int lePos=uneValeur;
    
    for (i=lePos+1;i<leNbElem;i++)
        unTab[i-1]=unTab[i];
    if(lePos<leNbElem)
        leNbElem--;
    
    return printf("%.0lf", unTab[i]);
}

void triBulle (double unTab[], int uneTaille){
    int j,k;
    double leSauveur;
    
    if(uneTaille==0)throw -2.1;
    if(uneTaille==1)return;
    for (k= 0;k < uneTaille - 1; k++)
        for ( j = k + 1; j < uneTaille; j++)
            if (unTab[k] > unTab[j]){
                leSauveur = unTab[k];
                unTab[k] = unTab[j];
                unTab[j] = leSauveur;
            }
}

bool estTrieCroissant(double* pUnTab, int uneTaille){
    int i;
    if(uneTaille<=0)throw -1;
    if(uneTaille==1)return true;
    for(i=0;i<uneTaille;i++)
    {
        if(pUnTab[i]>pUnTab[i+1])return false;
    }
    return true;
}

void trieSelection(double unTab[], int uneTaille)
{
    //if(uneTaille<=0)
    //throw -2.2;
    double leMin;
    int leIndiceMin, k, j;
    for(k=0;k<=uneTaille-2;k++)
    {
        leIndiceMin= k;
        leMin = unTab[k];
        for(j=k+1;j<=uneTaille-1;j++)
        {
            if(unTab[j] < leMin)
            {
                leIndiceMin = j ;
                leMin = unTab[j];
            }
        }
        unTab[leIndiceMin]=unTab[k];
        unTab[k]=leMin;
    }
}
int* rechercher(double unTab[], int uneTaille, double uneValeur){
    int i, leCompteur;
    int leTestNonVal = 0;
    int* leResultat = (int*)malloc(sizeof(int)*uneTaille);
    
    if(uneTaille==0) throw -2.1;
    
    leCompteur = 0;
    
    for(i=0;i<uneTaille;i++){
        if(unTab[i]==uneValeur){
            leResultat[leCompteur] = i;
            leCompteur++;
            leTestNonVal = 1;
        }
    }
    
    if(leTestNonVal==0)return NULL;
    
    return leResultat;
}

int rechercheDico(double unTab[],int uneTaille,double uneValeur){
    int laTaille, leInf, leSup, leMilieu, leRang, i;
    
    if(uneTaille==0) throw -2.2;
    if(uneTaille==1) return uneTaille;
    
    if(unTab[1]<unTab[0]) throw -2.1;
    for(i=uneTaille;i==0;i--){
        laTaille=uneTaille-1;
        if((unTab[i])<(unTab[laTaille])) throw -2.1;
    }
    
    leInf=0;
    laTaille=uneTaille-1;
    leSup=laTaille;
    while(leInf < leSup){
        leMilieu=(leInf+leSup)/2;
        if(unTab[leMilieu]<uneValeur)
            leInf=leMilieu+1;
        else
            leSup=leMilieu;
    }
    leRang=leInf+1;
    
    return leRang;
}

double* suppElem(double unTab[],int uneTaille, double uneValeur)
{
    
    int i=0,j;
    double * pLeResultat;
    
    while(uneValeur != unTab[i] && i<uneTaille-1)
    {
        i++;
    }
    if(unTab[i] == uneValeur)
    {
        for(j=i+1; j<uneTaille;j++)
        {
            unTab[j-1]=unTab[i];
            uneTaille--;
        }
    }
    else throw -1;
    pLeResultat=suppElem(unTab,uneTaille,uneValeur);
    
    return pLeResultat;
    
}

double * inserElemPos(double unTab[], int uneTaille, int unRang, double uneVal){
    double leTab[uneTaille+1];
    int laColonneA, laColonneB;
    
    laColonneB=0;
    for(laColonneA=0; laColonneA<uneTaille; laColonneA++){
        if(laColonneA==(unRang-1)){
            leTab[laColonneB]=uneVal;
            laColonneB++;
        }
        leTab[laColonneB]=unTab[laColonneA];
        laColonneB++;
    }
    return leTab;
}

//permet díinsÈrer un ÈlÈment dans un tableau de rÈels triÈ
double * inserElem(double unTab[], int uneTaille, int uneVal){
    double leTab[uneTaille+1];
    int laColonne;
    
    if (estTrieCroissant(unTab,uneTaille) || estTrieDecroissant(unTab,uneTaille)){
        for(laColonne=0; laColonne<uneTaille; laColonne++){
            leTab[laColonne]=unTab[laColonne];
            leTab[uneTaille]=uneVal;
        }
    }
        else
                throw -2.1;
    
        return leTab;
    

}

char* toString(int uneTaille, ...) {
    
    double* leTab = (double *)malloc(sizeof(double)*uneTaille);
    
//On créé une liste d'arguments variables
    va_list ap;
//La macro va_start fait pointer ap sur le premier argument variable fourni à la fonction.
    va_start(ap,uneTaille);
    
//    la macro va_arg renvoie le premier argument variable et fait pointer ap sur l'argument suivant.
//    type est le type de l'argument qui va être lu et va_arg génère une expression de ce même type.
    for(size_t i=0;i<uneTaille;i++) {
        leTab[i] = va_arg(ap,double);
    }
//La macro va_end remet tout en état normal avant le retour à la fonction appelante.
    va_end(ap);
    
    // Calculer la taille totale du buffer resultant
    int tailleTot=0;
    for (int i= 0; i<uneTaille; i++)
        tailleTot+=sizeof(int)*uneTaille+sizeof(char)*2; // pour espace et virgule entre chaque élement
    // Allouer le buffer résultant
    char* pBuffer = (char*)malloc(tailleTot+ sizeof(char)*2) ; // 2 pour {}
    if(pBuffer == NULL) throw -1.0;
    // Initialiser le buffer resultant
    int pos= sprintf(pBuffer, "{");
    // Remplir le buffer resultant
    for(int j=0; j<uneTaille; j++)
    {
        // Enregistrer l'element courant dans le buffer
        pos+=sprintf(pBuffer+pos, "%f ", leTab[j]);
        // Enregistrer le caractere de separation de chaque element // (excepte pour le dernier)
        if(j<uneTaille-1) pos+=sprintf(pBuffer+pos, ", ");
    }
    strcat(pBuffer, "}"); return pBuffer;
}

char* toString(double * unTab,int unN) {
    // Calculer la taille totale du buffer resultant
    int tailleTot=0;
    for (int i= 0; i<unN; i++)
        tailleTot+=sizeof(int)*unN+sizeof(char)*2; // pour espace et virgule entre chaque élement
    // Allouer le buffer résultant
    char* pBuffer = (char*)malloc(tailleTot+ sizeof(char)*2) ; // 2 pour {}
    if(pBuffer == NULL) throw -1.0;
    // Initialiser le buffer resultant
    int pos= sprintf(pBuffer, "{");
    // Remplir le buffer resultant
    for(int j=0; j<unN; j++)
    {
        // Enregistrer l'element courant dans le buffer
        pos+=sprintf(pBuffer+pos, "%f ", unTab[j]);
        // Enregistrer le caractere de separation de chaque element // (excepte pour le dernier)
        if(j<unN-1) pos+=sprintf(pBuffer+pos, ", ");
    }
    strcat(pBuffer, "}"); return pBuffer;
}