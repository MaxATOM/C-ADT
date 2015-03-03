#include "Segment.h"
#include <stdbool.h>
#include <math.h>

segment construireSegment (point unPtA, point unPtB) {

    if (unPtA.x==unPtB.x && unPtA.y==unPtB.y) throw -2.1;

    segment seg;
    seg.ptA = unPtA;
    seg.ptA = unPtB;

    return seg;
}

double longueur(segment unSegment) {

    return distancep(unSegment.ptA, unSegment.ptB);
//return sqrt(pow((unSegment.ptB.x-unSegment.ptA.x),2)+(pow((unSegment.ptB.y-unSegment.ptA.y),2)));
}

point milieu(segment unSegment) {


    return construirePoint('M', (unSegment.ptA.x+unSegment.ptB.x)/2.f,(unSegment.ptA.y+unSegment.ptB.y)/2.f);

}

bool aligne(segment unSegment, point unPoint) {

//    return (fabs(unPoint.x) >= fabs(unSegment.ptA.x) && fabs(unPoint.x) <= fabs(unSegment.ptB.x) && fabs(unPoint.y) >= fabs(unSegment.ptA.y) && fabs(unPoint.y) <= fabs(unSegment.ptB.y));

// Controler si vecteur AP et PB sont colineaires
    return (fabs((unPoint.x-unSegment.ptA.x)*(unSegment.ptA.y-unPoint.y) - (unPoint.y-unSegment.ptA.y) * (unSegment.ptB.x-unPoint.x)) <= EPSILON);

}

segment plusGrand(segment* unTab, int uneTaille) {
int i;
segment leSegment;

    if (unTab==NULL) throw -2.1;
    if (uneTaille <= 0) throw -2.2;

    leSegment = unTab[0];

    for (i=1; i<uneTaille;i++)
            if (longueur(unTab[i]) > longueur(leSegment)) leSegment = unTab[i];

return leSegment;
}
