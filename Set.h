//
//  Ensemble.h
//  Exo1
//
//  Created by Maxime Carrillo on 06/01/2015.
//  Copyright (c) 2015 Maxime Carrillo. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct sEnsemble{
    
    int cardinal;
    int* pElements;
    
} ensemble ;



ensemble construireEnsemble();

bool estVide(ensemble unEnsemble);

bool appartient(ensemble unEnsemble, int unElement);

int cardinal(ensemble unEnsemble);

void ajouter(ensemble unEnsemble, int unElement);

ensemble union_(ensemble unEnsemble1, ensemble unEnsemble2);

ensemble intersection_(ensemble unOp1, ensemble unOp2);

char* toString(ensemble unEnsemble);

void detruireEnsemble(ensemble unEnsemble);

