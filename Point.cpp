//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"



point construirePoint(char unNom, double unX, double unY)
{
	point pt;
	pt.nom=unNom;
	pt.x=unX;
	pt.y= unY;
	return pt;
}


// --- Projection sur l'axe des abscisses

point projX (point pt) {return construirePoint('R',pt.x,0);}


// --- Projection sur l'axe des ordonnees
//
point projY (point pt) {return construirePoint('R',0,pt.y);}


// --- Calcul de la distance entre deux points
//
double distancep (point pt1,point pt2)
{
	double a1= pt1.x;
	double b1= pt1.y;
	double a2= pt2.x;
	double b2= pt2.y;

   return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}


// --- Rotation d'un angle teta par rapport a l'origine
point rotation (point pt,double teta)
{
   double a1=cos(teta);
   double b1=sin(teta);
   double a2=pt.x;
   double b2=pt.y;

   return construirePoint('R',a1*a2-b1*b2, a1*b2+b1*a2);
}


// --- Symetrie centrale par rapport a l'origine

point symetrie(point pt) {
    pt.x = -1*pt.x;
    pt.y = -1*pt.y;

    return (pt);
}
//



// --- Homothetie par rapport a l'origine
point homothetie (point pt, double rapport){

   // Controler la validite du rapport

   if (rapport==0.0) throw -1;
   return construirePoint('R',pt.x*rapport, pt.y*rapport);
}

point *saisirPoint() {
    point *pResultat = (point*)malloc(sizeof(point));
    if (pResultat==NULL) throw -1;
    printf("Saisir le nom du point : ");
    scanf("%c",&pResultat->nom);
    fflush(stdin);
    printf("Entrez X : ");
    scanf("%lf",&pResultat->x);
    fflush(stdin);
    printf("Entrez Y : ");
    scanf("%lf",&pResultat->y);
    fflush(stdin);

    return pResultat;
}


void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


point** saisirTableauPoints(int unNb) {
    
    point **ppResultat = (point**)malloc(sizeof(point)*(unNb+1));
    if (ppResultat==NULL)  throw -1;
    for(int i=0; i<unNb;i++) {
      ppResultat[i]=saisirPoint();
    }
    ppResultat[unNb]= NULL;
    return ppResultat;
}
char * toString(point unP)
{
   char* pBuffer;
   pBuffer=(char*) malloc(sizeof(char)*40);
   if (pBuffer==NULL) return NULL;
   sprintf(pBuffer, "%c(%.2f, %.2f)", unP.nom,unP.x, unP.y);

   // Restituer le resultat
   //
   return pBuffer;
}







