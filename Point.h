// point.h

#include <iostream>

#define PI 3.141592

#define EPSILON 0.000001




typedef struct

{
    double x;
    double y;
	char nom;


}point;

point construirePoint(char , double , double );

double distancep (point, point) ;

point projX (point) ;

point projY (point);

// rotation d'un angle par rapport à l'origine

point rotation    (point,double) ;

// --- Symetrie centrale par rapport a l'origine

point symetrie    (point);

point homothetie  (point ,double);

char* toString(point unPoint);

point *saisirPoint();
point** saisirTableauPoints(int unNb);
void clean_stdin();