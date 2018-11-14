
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
void o_function(void);
void a_function(void);
void v_function(void);
void r_function(void);
void p_function(void);
void x_function(void);
void m_function(void);
void s_function(void);
void k_function(void);

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
                o_function();
                break;
            }
            case 'v':
            {
                v_function();
                break;
            }
            case 'x':
            {
                x_function();
                break;
            }
            case 'r':
            {
                r_function();
                break;
            }
            case 'p':
            {
                p_function();
                break;
            }
            case 'a':
            {
                a_function();
                break;
            }
            case 'm':
            {
                m_function();
                break;
            }
            case 's':
                s_function();
                break;
            case 'k':
            {
                k_function();
                break;
            }
        }
    }
    return 0;
}
