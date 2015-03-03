
#include <stdio.h>

void assertEquals( int attendu, int obtenu );
void assertEquals( float attendu, float obtenu, float epsilon );
void assertEquals( float attendu, float obtenu );
void assertEquals( double attendu, double obtenu, double epsilon );
void assertEquals( double attendu, double obtenu );
void assertEquals( char attendu, char obtenu );
void assertEquals( char* attendu, char* obtenu );