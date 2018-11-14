
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struktura:
typedef struct
{
    char meno_priezvisko[50];
    char pohlavie[50];
    char rok_narodenia[50];
    char SPZ[50];
    char typ_priestupku[50];
    char vyska_pokuty[50];
    char datum_priestupku[50];
} POLE_STRUKTUR;

int main() {
    FILE *file;                    //file
    POLE_STRUKTUR *MASSIVE = NULL; //pole structur
    int K;                         //pocet zaznzmov
    char c;                        //znak pre funkcie
    return 0;
}
