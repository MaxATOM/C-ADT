#include "Set.h"

ensemble construireEnsemble() {
    
    ensemble unE;
    unE.cardinal = 0;
    unE.pElements  = (int*)malloc(sizeof(int)*10);
    if (unE.pElements == NULL) throw -1;
    return unE;
    
    
}


void ajouter(ensemble *unEnsemble, int unElem)
{
    //Contr™ler la validitŽ des paramtres
    
    
    // Contr™le s'il faut agrandir ou non
    
    if (unEnsemble->cardinal == 0 || unEnsemble->cardinal%10!= 0)
    {
        
        // Ajouter l'Žlement
        
        
        
    }
    else
    {
        // Agrandir l'ensemble
        ensemble newE;
        newE.pElements= (int*)malloc(sizeof(int)*(unEnsemble->cardinal/10+1)*10);
        
        if (newE.pElements==NULL) throw -1.0;
        
        // Recopier le contenu de l'ensemble precedent dans le nouveau
        
        
        // Ajouter le nouvel element dans le nouvel ensemble
        
        
        
        // libŽrer mŽmoire de l'ancien remplacer le nouvel ensemble a l'ancien
        
        free(unEnsemble->pElements) ;
        unEnsemble->pElements = newE.pElements;
    }
}

bool appartient(ensemble unEnsemble, int unElement){

    if(unEnsemble.cardinal==0) return false;
    for(int i=0; i<unEnsemble.cardinal; i++) if(unEnsemble.pElements[i]==unElement) return true;
    return false;
}

char* toString (ensemble unEnsemble) {
char* pBuffer, *laChaine, *leNombre;
int laTailleTotale=0;

    leNombre="";
    for (int j=0;j<cardinal(unEnsemble);j++){
        sprintf(leNombre,"%d",unEnsemble.pElements[j]);

        laTailleTotale=laTailleTotale+(int)strlen(leNombre);
    }

    pBuffer=(char*) malloc(sizeof(char)*(laTailleTotale+5+cardinal(unEnsemble)*2));
    if (pBuffer==NULL) throw -1.0;

    if (cardinal(unEnsemble)==0){
        sprintf(pBuffer,"L'ensemble est vide");
        return pBuffer;
    }
    laChaine="";
    sprintf(pBuffer,"{ ");
    for (int i=0;i<cardinal(unEnsemble);i++){
        sprintf(laChaine,"%d",unEnsemble.pElements[i]);
        strcat(pBuffer,", ");
        strcat(pBuffer, laChaine);
    }
    strcat(pBuffer, "} ");

    return pBuffer;
}

int cardinal(ensemble unEnsemble){

    if(unEnsemble.cardinal<0)throw -2.0;

    return unEnsemble.cardinal;

}


bool estVide(ensemble unEnsemble){

    if (unEnsemble.cardinal == 0) return true;
        return false;
}


ensemble intersection_(ensemble unOpr1, ensemble unOpr2){
ensemble leResultat;

    leResultat=construireEnsemble();

    if(cardinal(unOpr1)==0)return leResultat;
    if(cardinal(unOpr2)==0)return leResultat;

    for(int i=0; i<cardinal(unOpr1);i++)
            if(appartient(unOpr2, unOpr1.pElements[i])) ajouter(leResultat, unOpr1.pElements[i]);
    return leResultat;
}
