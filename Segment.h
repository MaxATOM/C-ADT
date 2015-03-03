#include "Point.h"

typedef struct
{
	point ptA;
    point ptB;

}segment;

segment construireSegment (point,point);
double longueur(segment);
point milieu(segment);
bool aligne(segment, point);
bool appartient(segment, point);
segment plusGrand(segment*, int);
