
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

//funkcie:
POLE_STRUKTUR*  o_function(int *K, FILE **file, POLE_STRUKTUR **MASSIVE);
POLE_STRUKTUR*  a_function(int *K, FILE **file, POLE_STRUKTUR **MASSIVE);
void v_function(int *K, POLE_STRUKTUR **MASSIVE);
void r_function(int *K, POLE_STRUKTUR **MASSIVE);
void p_function(int *K, POLE_STRUKTUR **MASSIVE);
void x_function(int *K, POLE_STRUKTUR **MASSIVE);
void m_function(int *K, POLE_STRUKTUR **MASSIVE);
void s_function(int *K, POLE_STRUKTUR **MASSIVE);
void k_function(int *K, FILE **file, POLE_STRUKTUR **MASSIVE);

int main() {
    FILE *file;                    //file
    POLE_STRUKTUR *MASSIVE = NULL; //pole structur
    int K;                         //pocet zaznzmov
    char c;                        //znak pre funkcie
    while ((c=getchar()))
    {
        switch (c)
        {
            case 'o':
            {
                MASSIVE = o_function(&K, &file, &MASSIVE);
                break;
            }
            case 'v':
            {
                v_function(&K, &MASSIVE);
                break;
            }
            case 'x':
            {
                x_function(&K, &MASSIVE);
                break;
            }
            case 'r':
            {
                r_function(&K, &MASSIVE);
                break;
            }
            case 'p':
            {
                p_function(&K, &MASSIVE);
                break;
            }
            case 'a':
            {
                MASSIVE = a_function(&K, &file, &MASSIVE);
                break;
            }
            case 'm':
            {
                m_function(&K, &MASSIVE);
                break;
            }
            case 's':
                s_function(&K, &MASSIVE);
                break;
            case 'k':
            {
                k_function(&K, &file, &MASSIVE);
                break;
            }
        }
    }
    return 0;
}
