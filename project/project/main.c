
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
POLE_STRUKTUR*  a_function(int *K, POLE_STRUKTUR **MASSIVE);
void v_function(int *K, POLE_STRUKTUR **MASSIVE);
void r_function(int *K, POLE_STRUKTUR **MASSIVE);
void p_function(int *K, POLE_STRUKTUR **MASSIVE);
void x_function(int *K, POLE_STRUKTUR **MASSIVE);
void m_function(int *K, POLE_STRUKTUR **MASSIVE);
void s_function(int *K, POLE_STRUKTUR **MASSIVE);
void k_function(FILE **file, POLE_STRUKTUR **MASSIVE);

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
                MASSIVE = a_function(&K, &MASSIVE);
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
                k_function(&file, &MASSIVE);
                break;
            }
        }
    }
    return 0;
}


//funkcie:
POLE_STRUKTUR* o_function(int *K, FILE **file, POLE_STRUKTUR **MASSIVE)
{
    *file = fopen("/Users/olesia/Desktop/FIIT STU/PrPr/project1/priestupky.txt", "r");
    char *s;
    s=(char *) malloc (50);
    int k=0;
    while(fgets(s, 50, *file))
    {
        if ((strchr(s, '\n')) != NULL)
            k++;
    }
    *K=k/8;        //pocet zaznamov

    *file = fopen("/Users/olesia/Desktop/FIIT STU/PrPr/project1/priestupky.txt", "r");
    
    if (*MASSIVE != NULL)
    {
        free(*MASSIVE);                       //dealokovanie pola, ak ono uz bolo predtym vytvorene
    }
    
    char *c;
    c = (char*) malloc(50);
    int a = *K;
    
    *MASSIVE = (POLE_STRUKTUR*) malloc (sizeof(POLE_STRUKTUR)*(a)); //vytvorenie dynamickeho pola structur
    for (int i=0; i<*K; i++)
    {
        unsigned long n;
        //nacitavanie zaznamov zo subora
        fgets((*MASSIVE)[i].meno_priezvisko, 50, *file); //meno priezvisko
        n=strlen((*MASSIVE)[i].meno_priezvisko);
        (*MASSIVE)[i].meno_priezvisko[n-1]='\0';
        
        fgets((*MASSIVE)[i].pohlavie, 50, *file);     // pohlavie
        n=strlen((*MASSIVE)[i].pohlavie);
        (*MASSIVE)[i].pohlavie[n-1]='\0';
        
        fgets((*MASSIVE)[i].rok_narodenia, 50, *file);    //rok narodenia
        n=strlen((*MASSIVE)[i].rok_narodenia);
        (*MASSIVE)[i].rok_narodenia[n-1]='\0';
        
        fgets((*MASSIVE)[i].SPZ, 50, *file);               //SPZ
        n=strlen((*MASSIVE)[i].SPZ);
        (*MASSIVE)[i].SPZ[n-1]='\0';
        
        fgets((*MASSIVE)[i].typ_priestupku, 50, *file);     //typ priestupku
        n=strlen((*MASSIVE)[i].typ_priestupku);
        (*MASSIVE)[i].typ_priestupku[n-1]='\0';
        
        fgets((*MASSIVE)[i].vyska_pokuty, 50, *file);      //vyska pokuty
        n=strlen((*MASSIVE)[i].vyska_pokuty);
        (*MASSIVE)[i].vyska_pokuty[n-1]='\0';
        
        fgets((*MASSIVE)[i].datum_priestupku, 50, *file);     //datum priestupku
        n=strlen((*MASSIVE)[i].datum_priestupku);
        (*MASSIVE)[i].datum_priestupku[n-1]='\0';
        
        fgets(c, 50, *file);                                   //pre prazdny riadok medzi zaznamami
    }                                                 //prekopirovanie vsetkych udajov do pola structur podla polozek
    
    if (MASSIVE==NULL)
        printf("Pole nie je naplnené");    //v pripade neuspesnej alokacie
    
    return *MASSIVE;
}


void v_function(int *K, POLE_STRUKTUR **MASSIVE)
{
    if (MASSIVE!=NULL)
    {
        for (int i=0; i<*K; i++)
        {
            printf("meno priezvisko: %s\n", (*MASSIVE)[i].meno_priezvisko);      //vypis vsetkych zazanamov
            printf("pohlavie: %s\n", (*MASSIVE)[i].pohlavie);
            printf("rok narodenia: %s\n", (*MASSIVE)[i].rok_narodenia);
            printf("SPZ: %s\n", (*MASSIVE)[i].SPZ);
            printf("typ priestupku: %s\n", (*MASSIVE)[i].typ_priestupku);
            printf("vyska pokuty: %s\n", (*MASSIVE)[i].vyska_pokuty);
            printf("datum priestupku: %s\n", (*MASSIVE)[i].datum_priestupku);
            putchar('\n');                                                       //prazdny riadok medzi zaznamami
        }
    }
}


void x_function(int *K, POLE_STRUKTUR **MASSIVE)
{
    if(MASSIVE!=NULL)
    {
        int a;
        scanf("%d", &a);                      //nacitanie aktualneho datumu
        a=a/10000;                            //vypocet roku
        for (int i =0; i<*K; i++)
        {
            int b = atoi((*MASSIVE)[i].datum_priestupku);
            int c = atoi((*MASSIVE)[i].typ_priestupku);
            if ((b/10000)==a && c==0)
                printf("meno priezvisko: %s\nSPZ: %s\ndatum priestupku: %s\n\n", (*MASSIVE)[i].meno_priezvisko, (*MASSIVE)[i].SPZ, (*MASSIVE)[i].datum_priestupku);
        }
    }
}


void r_function(int *K, POLE_STRUKTUR **MASSIVE)
{
    if ((*MASSIVE)!=NULL)
    {
        double odmena=0;
        int a;
        scanf("%d", &a);                                       //nacitavanie aktualneho datumu
        a=a/100;                                               //vypocet mesiaca
        for (int i =0; i<*K; i++)
        {
            int b = atoi((*MASSIVE)[i].datum_priestupku);
            b=b/100;                                          //vypocet mesiaca priestupku
            if (a==b)
            {
                int c = atoi((*MASSIVE)[i].typ_priestupku);
                int d = atoi((*MASSIVE)[i].vyska_pokuty);
                if (c==1)
                {
                    odmena+=d*0.052;
                }
                else
                {
                    if (c==0)
                    {
                        odmena+=d*0.038;
                    }
                }
            }
        }
        if (odmena!=0)
        {
            printf("%.2lf\n", odmena);
        }
    }
}


void p_function(int *K, POLE_STRUKTUR **MASSIVE)
{
    if (MASSIVE!=NULL)
    {
        for (int i=0; i<*K; i++)
        {
            unsigned long n;
            n=strlen((*MASSIVE)[i].SPZ);
            char *a;
            a = (char*) malloc(n);
            for(int j=0; j<n; j++)
            {
                a[j]=(*MASSIVE)[i].SPZ[n-1-j];                                       //prepis SPZ v obratenom poradii
            }
            if (strcmp(a, (*MASSIVE)[i].SPZ)==0)                                     //zistinie ci je SPZ palindrom
                printf("%s %s\n", (*MASSIVE)[i].meno_priezvisko, (*MASSIVE)[i].SPZ);
        }
    }
}


POLE_STRUKTUR* a_function(int *K, POLE_STRUKTUR **MASSIVE)
{
    int b = 0;
    unsigned long n;
    char c;
    if(MASSIVE!=NULL)
    {
        (*K)++;
        int a=*K;
        *MASSIVE = (POLE_STRUKTUR *) realloc (*MASSIVE, sizeof(POLE_STRUKTUR)*(a)); //vytvaranie vacsieho pola
        char *A;
        A = (char*) malloc (50);
        fgets(&c, 2, stdin); //pre '\n' po 'a'
        fgets(A, 50, stdin); //nacitanie mena
        n=strlen(A);
        A[n-1]='\0';
        if (strcmp(A, (*MASSIVE)[0].meno_priezvisko)<0) //porovnanie mien podla abecedy
        {
            b=0;
            for(int i=*K-1; i>0; i--)
            {
                (*MASSIVE)[i]=(*MASSIVE)[i-1];
            }
            strcpy((*MASSIVE)[b].meno_priezvisko, A);   //meno priezvisko
        }
        else
        {
            if (strcmp(A, (*MASSIVE)[*K-2].meno_priezvisko)>0)
            {
                b=*K-1;
                strcpy((*MASSIVE)[b].meno_priezvisko, A);  //meno priezvisko
            }
            else
            {
                for (int i=0; i<*K-2; i++)
                {
                    if (strcmp(A, (*MASSIVE)[i].meno_priezvisko)>0 && strcmp(A, (*MASSIVE)[i+1].meno_priezvisko)<0)
                    {
                        b=i+1;
                        for (int i=*K-1; i>b; i--)
                        {
                            (*MASSIVE)[i]=(*MASSIVE)[i-1];
                        }
                        strcpy((*MASSIVE)[b].meno_priezvisko, A);  //meno priezvisko
                    }
                }
            }
        }
    }
    else
    {
        *K=1;
        int a=*K;
        b=0;
        *MASSIVE = (POLE_STRUKTUR *) malloc (sizeof(POLE_STRUKTUR)*(a));
        fgets(&c, 2, stdin); //pre '\n' po 'a'
        
        fgets((*MASSIVE)[b].meno_priezvisko, 50, stdin);  //meno priezvisko
        n=strlen((*MASSIVE)[b].meno_priezvisko);
        (*MASSIVE)[b].meno_priezvisko[n-1]='\0';
    }
    //nacitavanie udajov
    fgets((*MASSIVE)[b].pohlavie, 50, stdin);    //pohlavie
    n=strlen((*MASSIVE)[b].pohlavie);
    (*MASSIVE)[b].pohlavie[n-1]='\0';
    
    fgets((*MASSIVE)[b].rok_narodenia, 50, stdin);   //rok narodenia
    n=strlen((*MASSIVE)[b].rok_narodenia);
    (*MASSIVE)[b].rok_narodenia[n-1]='\0';
    
    fgets((*MASSIVE)[b].SPZ, 50, stdin);   //SPZ
    n=strlen((*MASSIVE)[b].SPZ);
    (*MASSIVE)[b].SPZ[n-1]='\0';
    
    fgets((*MASSIVE)[b].typ_priestupku, 50, stdin);   //typ priestupku
    n=strlen((*MASSIVE)[b].typ_priestupku);
    (*MASSIVE)[b].typ_priestupku[n-1]='\0';
    
    fgets((*MASSIVE)[b].vyska_pokuty, 50, stdin);    //vyska pokuty
    n=strlen((*MASSIVE)[b].vyska_pokuty);
    (*MASSIVE)[b].vyska_pokuty[n-1]='\0';
    
    fgets((*MASSIVE)[b].datum_priestupku, 50, stdin);   //datum priestupku
    n=strlen((*MASSIVE)[b].datum_priestupku);
    (*MASSIVE)[b].datum_priestupku[n-1]='\0';
    
    return *MASSIVE;
}
