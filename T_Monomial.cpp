#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Tests_Unit.h"
#include "Polynomial.h"

using namespace std;

int main()
{
monome leMonome={-5,5}, leMonome2={4,5};

    printf("valeurMonome: %lf\n",valeurMonome(leMonome2,2));

    printf("\nafficherMonome(derivee)\n");
    afficherMonome(derivee(leMonome),'X');

    printf("\n\nafficherMonome(leMonome)\n");
    afficherMonome(leMonome,'X');

    printf("\n\nafficherMonome(primitive)\n");
    afficherMonome(primitive(leMonome,0),'X');

    printf("\nafficherMonome(multiplication)\n");
    afficherMonome(multiplication(leMonome,leMonome2),'X');
    
    afficherMonome(leMonome,'X');

    assertEquals("-1.000000X5", toString(addition(leMonome, leMonome2), 'X') );
    assertEquals(4., coefficient(leMonome2));
//    polynome lePolynome = construirePolynome(2, leMonome, leMonome2);
    

    printf("\n\n");

    return 0;
}


