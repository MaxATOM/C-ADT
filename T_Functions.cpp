#include <iostream>
#include "Functions.h"
#include "Tests_Unit.h"

using namespace std;

int main()
{
double leTab1[5] = {3.,12.,8.,2.,6.};
double *leTab1Trie = triBulleVar(leTab1, 5);

char *leTab1TrieStr = toString(leTab1Trie, 5);
char *leTab1TrieManuelStr = toString(5, 2.,3.,6.,8.,12.);
    
double leTab2[3] = {32.24,13.38,29.32};
double *leTab2Trie = triBulleVar(leTab2, 3);
    
char *leTab2TrieStr = toString(leTab2Trie, 5);
char *leTab2TrieManuelStr = toString(5, 13.38,29.32,32.24);
    
    
    assertEquals(leTab1TrieManuelStr,leTab1TrieStr);
    assertEquals(leTab2TrieManuelStr,leTab2TrieStr);

    try {
        double leTab2[2] = {3.,4.};
        double *leTab2Trie = triBulleVar(leTab2, 0);
    } catch (double e) {
        printf("Erreur %.1lf, taille inférieur ou égale à 0", e);
    }
    return 0;
}

