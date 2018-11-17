#include "/Users/olesia/Desktop/FIIT STU/MIP/MIP_PrPr_project1/project/project/Header.h"


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
POLE_STRUKTUR*  o_function(int *pocet_zaznamov, FILE **file, POLE_STRUKTUR **MASSIVE);
POLE_STRUKTUR*  a_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void v_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void r_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void p_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void x_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void m_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void s_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE);
void l_function(int *pocet_zaznamov, FILE **file, POLE_STRUKTUR **MASSIVE);
void k_function(FILE **file, POLE_STRUKTUR **MASSIVE);




//main:
int main() {
    FILE *file;                    //file
    POLE_STRUKTUR *MASSIVE = NULL; //pole structur
    int pocet_zaznamov;
    char funkcia;                  //znak pre funkcie
    while ((funkcia=getchar()))
    {
        switch (funkcia)
        {
            case 'o':
            {
                MASSIVE = o_function(&pocet_zaznamov, &file, &MASSIVE);
                break;
            }
            case 'v':
            {
                v_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 'x':
            {
                x_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 'r':
            {
                r_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 'p':
            {
                p_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 'a':
            {
                MASSIVE = a_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 'm':
            {
                m_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 's':
            {
                s_function(&pocet_zaznamov, &MASSIVE);
                break;
            }
            case 'l':
            {
                l_function(&pocet_zaznamov, &file, &MASSIVE);
                break;
            }
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
POLE_STRUKTUR* o_function(int *pocet_zaznamov, FILE **file, POLE_STRUKTUR **MASSIVE)
{
    *file = fopen("/Users/olesia/Desktop/FIIT STU/MIP/MIP_PrPr_project1/project/priestupky.txt", "r");
    
    char *riadok_subora;
    riadok_subora = (char *) malloc (50);
    
    int pocet_riadkov = 0;
    
    while (fgets ( riadok_subora, 50, *file ) )
    {
        if ( ( strchr ( riadok_subora, '\n' ) ) != NULL )
            pocet_riadkov++;
    }
    
    *pocet_zaznamov = pocet_riadkov/8;                                              //pocet zaznamov

    *file = fopen("/Users/olesia/Desktop/FIIT STU/MIP/MIP_PrPr_project1/project/priestupky.txt", "r");
    
    if (*MASSIVE != NULL)
    {
        free(*MASSIVE);                                                              //dealokovanie pola, ak ono uz bolo predtym vytvorene
    }
    
    char *prazdny_riadok;
    prazdny_riadok = (char*) malloc(50);
    int a = *pocet_zaznamov;
    
    *MASSIVE = (POLE_STRUKTUR*) malloc (sizeof(POLE_STRUKTUR)*(a));                  //vytvorenie dynamickeho pola structur
    for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
    {
        unsigned long dlzka_riadku;
        //nacitavanie zaznamov zo subora
        fgets( (*MASSIVE)[cislo_zaznamu].meno_priezvisko, 50, *file );               //meno priezvisko
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].meno_priezvisko );
        (*MASSIVE)[cislo_zaznamu].meno_priezvisko[dlzka_riadku-1] = '\0';
        
        fgets( (*MASSIVE)[cislo_zaznamu].pohlavie, 50, *file );                     // pohlavie
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].pohlavie );
        (*MASSIVE)[cislo_zaznamu].pohlavie[dlzka_riadku-1] = '\0';
        
        fgets( (*MASSIVE)[cislo_zaznamu].rok_narodenia, 50, *file );                //rok narodenia
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].rok_narodenia );
        (*MASSIVE)[cislo_zaznamu].rok_narodenia[dlzka_riadku-1] = '\0';
        
        fgets( (*MASSIVE)[cislo_zaznamu].SPZ, 50, *file );                         //SPZ
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].SPZ );
        (*MASSIVE)[cislo_zaznamu].SPZ[dlzka_riadku-1] = '\0';
        
        fgets( (*MASSIVE)[cislo_zaznamu].typ_priestupku, 50, *file );             //typ priestupku
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].typ_priestupku );
        (*MASSIVE)[cislo_zaznamu].typ_priestupku[dlzka_riadku-1] = '\0';
        
        fgets( (*MASSIVE)[cislo_zaznamu].vyska_pokuty, 50, *file );               //vyska pokuty
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].vyska_pokuty );
        (*MASSIVE)[cislo_zaznamu].vyska_pokuty[dlzka_riadku-1] = '\0';
        
        fgets( (*MASSIVE)[cislo_zaznamu].datum_priestupku, 50, *file );          //datum priestupku
        dlzka_riadku = strlen( (*MASSIVE)[cislo_zaznamu].datum_priestupku );
        (*MASSIVE)[cislo_zaznamu].datum_priestupku[dlzka_riadku-1] = '\0';
        
        fgets( prazdny_riadok, 50, *file );                                      //pre prazdny riadok medzi zaznamami
    }                                                                            //prekopirovanie vsetkych udajov do pola structur podla polozek
    
    if ( MASSIVE == NULL )
        printf( "Pole nie je naplnené" );                                        //v pripade neuspesnej alokacie
    
    return *MASSIVE;
}


void v_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    if ( MASSIVE != NULL )
    {
        for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
        {
            printf( "meno priezvisko: %s\n", (*MASSIVE)[cislo_zaznamu].meno_priezvisko );             //vypis vsetkych zazanamov
            printf( "pohlavie: %s\n", (*MASSIVE)[cislo_zaznamu].pohlavie );
            printf( "rok narodenia: %s\n", (*MASSIVE)[cislo_zaznamu].rok_narodenia );
            printf( "SPZ: %s\n", (*MASSIVE)[cislo_zaznamu].SPZ );
            printf( "typ priestupku: %s\n", (*MASSIVE)[cislo_zaznamu].typ_priestupku );
            printf( "vyska pokuty: %s\n", (*MASSIVE)[cislo_zaznamu].vyska_pokuty );
            printf( "datum priestupku: %s\n", (*MASSIVE)[cislo_zaznamu].datum_priestupku );
            putchar( '\n' );                                                                           //prazdny riadok medzi zaznamami
        }
    }
}


void x_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    if ( MASSIVE != NULL )
    {
        int aktualny_rok;
        scanf("%d", &aktualny_rok);                                                         //nacitanie aktualneho datumu
        aktualny_rok = aktualny_rok / 10000;                                                //vypocet roku
        
        for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
        {
            int datum_zaznamu = atoi( (*MASSIVE)[cislo_zaznamu].datum_priestupku );
            int typ_zaznamu = atoi( (*MASSIVE)[cislo_zaznamu].typ_priestupku );
            if ( ( datum_zaznamu / 10000 ) == aktualny_rok && typ_zaznamu == 0 )
            {
                printf("meno priezvisko: %s\nSPZ: %s\ndatum priestupku: %s\n\n", (*MASSIVE)[cislo_zaznamu].meno_priezvisko, (*MASSIVE)[cislo_zaznamu].SPZ, (*MASSIVE)[cislo_zaznamu].datum_priestupku);
            }
            
        }
    }
}


void r_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    if ( (*MASSIVE) != NULL)
    {
        double odmena = 0;
        
        int aktualny_mesiac;
        scanf("%d", &aktualny_mesiac);                                                         //nacitavanie aktualneho datumu
        aktualny_mesiac = aktualny_mesiac / 100;                                               //vypocet mesiaca
        
        for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
        {
            int mesiac_priestupku = atoi( (*MASSIVE)[cislo_zaznamu].datum_priestupku );
            mesiac_priestupku = mesiac_priestupku / 100;                                         //vypocet mesiaca priestupku
            if (aktualny_mesiac == mesiac_priestupku)
            {
                int typ_priestupku = atoi( (*MASSIVE)[cislo_zaznamu].typ_priestupku );
                int pokuta = atoi( (*MASSIVE)[cislo_zaznamu].vyska_pokuty );
                if (typ_priestupku == 1)
                {
                    odmena += pokuta * 0.052;
                }
                else
                {
                    if (typ_priestupku == 0)
                    {
                        odmena += pokuta * 0.038;
                    }
                }
            }
        }
        if (odmena != 0)
        {
            printf("%.2lf\n", odmena);
        }
    }
}


void p_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    if (MASSIVE != NULL)
    {
        for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
        {
            unsigned long dlzka_spz;
            dlzka_spz = strlen( (*MASSIVE)[cislo_zaznamu].SPZ );
            
            char *palindrom;
            palindrom = (char*) malloc(dlzka_spz);
            for(int cislo_znaku = 0; cislo_znaku < dlzka_spz; cislo_znaku++)
            {
                palindrom[cislo_znaku] = (*MASSIVE)[cislo_zaznamu].SPZ[dlzka_spz-1-cislo_znaku];                            //prepis SPZ v obratenom poradii
            }
            if ( strcmp( palindrom, (*MASSIVE)[cislo_zaznamu].SPZ ) == 0 )                                                  //zistinie ci je SPZ palindrom
            {
                printf("%s %s\n", (*MASSIVE)[cislo_zaznamu].meno_priezvisko, (*MASSIVE)[cislo_zaznamu].SPZ);
            }
        }
    }
}


POLE_STRUKTUR* a_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    int cislo_noveho_zaznamu = 0;
    
    unsigned long dlzka_retazca;
    
    char biely_znak;
    
    if ( MASSIVE != NULL )
    {
        (*pocet_zaznamov)++;
        int a = *pocet_zaznamov;
        *MASSIVE = (POLE_STRUKTUR *) realloc (*MASSIVE, sizeof(POLE_STRUKTUR)*(a)); //vytvaranie vacsieho pola
        
        char *nacitane_meno;
        nacitane_meno = (char*) malloc (50);
        
        fgets(&biely_znak, 2, stdin);                                                              //pre '\n' po znuku funkcii
        
        fgets(nacitane_meno, 50, stdin);                                                           //nacitanie mena
        dlzka_retazca=strlen(nacitane_meno);
        nacitane_meno[dlzka_retazca-1]='\0';
        
        if (strcmp(nacitane_meno, (*MASSIVE)[0].meno_priezvisko)<0)                                //porovnanie mien podla abecedy
        {
            cislo_noveho_zaznamu = 0;
            for(int cislo_zaznamu = *pocet_zaznamov - 1; cislo_zaznamu > 0; cislo_zaznamu--)
            {
                (*MASSIVE)[cislo_zaznamu] = (*MASSIVE)[cislo_zaznamu-1];
            }
            strcpy((*MASSIVE)[cislo_noveho_zaznamu].meno_priezvisko, nacitane_meno);               //meno priezvisko
        }
        else
        {
            if ( strcmp(nacitane_meno, (*MASSIVE)[*pocet_zaznamov - 2].meno_priezvisko) > 0 )
            {
                cislo_noveho_zaznamu = *pocet_zaznamov - 1;
                strcpy( (*MASSIVE)[cislo_noveho_zaznamu].meno_priezvisko, nacitane_meno );         //meno priezvisko
            }
            else
            {
                for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov - 2; cislo_zaznamu++)
                {
                    if (strcmp(nacitane_meno, (*MASSIVE)[cislo_zaznamu].meno_priezvisko) > 0 && strcmp(nacitane_meno, (*MASSIVE)[cislo_zaznamu + 1].meno_priezvisko) < 0)
                    {
                        cislo_noveho_zaznamu = cislo_zaznamu + 1;
                        for (int cislo_zaznamu = *pocet_zaznamov - 1; cislo_zaznamu > cislo_noveho_zaznamu; cislo_zaznamu--)
                        {
                            (*MASSIVE)[cislo_zaznamu] = (*MASSIVE)[cislo_zaznamu-1];
                        }
                        strcpy( (*MASSIVE)[cislo_noveho_zaznamu].meno_priezvisko, nacitane_meno );  //meno priezvisko
                    }
                }
            }
        }
    }
    else
    {
        *pocet_zaznamov = 1;
        int a = *pocet_zaznamov;
        
        *MASSIVE = (POLE_STRUKTUR *) malloc (sizeof(POLE_STRUKTUR)*(a));
        fgets(&biely_znak, 2, stdin); //pre '\n' po 'a'
        
        fgets( (*MASSIVE)[cislo_noveho_zaznamu].meno_priezvisko, 50, stdin );               //meno priezvisko
        dlzka_retazca = strlen( (*MASSIVE)[cislo_noveho_zaznamu].meno_priezvisko );
        (*MASSIVE)[cislo_noveho_zaznamu].meno_priezvisko[dlzka_retazca - 1] = '\0';
    }
    //nacitavanie udajov
    fgets( (*MASSIVE)[cislo_noveho_zaznamu].pohlavie, 50, stdin );                            //pohlavie
    dlzka_retazca = strlen( (*MASSIVE)[cislo_noveho_zaznamu].pohlavie );
    (*MASSIVE)[cislo_noveho_zaznamu].pohlavie[dlzka_retazca - 1] = '\0';
    
    fgets( (*MASSIVE)[cislo_noveho_zaznamu].rok_narodenia, 50, stdin );                       //rok narodenia
    dlzka_retazca=strlen( (*MASSIVE)[cislo_noveho_zaznamu].rok_narodenia );
    (*MASSIVE)[cislo_noveho_zaznamu].rok_narodenia[dlzka_retazca - 1] = '\0';
    
    fgets( (*MASSIVE)[cislo_noveho_zaznamu].SPZ, 50, stdin );                                 //SPZ
    dlzka_retazca = strlen( (*MASSIVE)[cislo_noveho_zaznamu].SPZ );
    (*MASSIVE)[cislo_noveho_zaznamu].SPZ[dlzka_retazca - 1] = '\0';
    
    fgets( (*MASSIVE)[cislo_noveho_zaznamu].typ_priestupku, 50, stdin );                       //typ priestupku
    dlzka_retazca = strlen( (*MASSIVE)[cislo_noveho_zaznamu].typ_priestupku );
    (*MASSIVE)[cislo_noveho_zaznamu].typ_priestupku[dlzka_retazca - 1] = '\0';
    
    fgets( (*MASSIVE)[cislo_noveho_zaznamu].vyska_pokuty, 50, stdin );                         //vyska pokuty
    dlzka_retazca = strlen( (*MASSIVE)[cislo_noveho_zaznamu].vyska_pokuty );
    (*MASSIVE)[cislo_noveho_zaznamu].vyska_pokuty[dlzka_retazca - 1] = '\0';
    
    fgets( (*MASSIVE)[cislo_noveho_zaznamu].datum_priestupku, 50, stdin );                     //datum priestupku
    dlzka_retazca = strlen( (*MASSIVE)[cislo_noveho_zaznamu].datum_priestupku );
    (*MASSIVE)[cislo_noveho_zaznamu].datum_priestupku[dlzka_retazca - 1] = '\0';
    
    return *MASSIVE;
}


void m_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    if ( MASSIVE != NULL )
    {
        int novy_pocet_zaznamov = *pocet_zaznamov;
        
        int aktualny_datum;
        scanf("%d", &aktualny_datum);
        
        for (int cislo_zaznamu = 0; cislo_zaznamu < novy_pocet_zaznamov; cislo_zaznamu++)
        {
            int datum_priestupku = atoi( (*MASSIVE)[cislo_zaznamu].datum_priestupku );
            int typ_priestupku = atoi( (*MASSIVE)[cislo_zaznamu].typ_priestupku );
            if ( datum_priestupku < aktualny_datum && typ_priestupku == 0 )
            {
                if ( cislo_zaznamu != *pocet_zaznamov - 1 )
                {
                    for (int cislo_zaznamu_novy = cislo_zaznamu; cislo_zaznamu_novy < *pocet_zaznamov; cislo_zaznamu_novy++)    //zmena zaznamov v poli structur
                        (*MASSIVE)[cislo_zaznamu_novy] = (*MASSIVE)[ cislo_zaznamu_novy + 1];
                }
                
                novy_pocet_zaznamov = novy_pocet_zaznamov - 1;
                *MASSIVE = (POLE_STRUKTUR *) realloc (*MASSIVE, sizeof(POLE_STRUKTUR)*(novy_pocet_zaznamov));                    //zmena velkosti pola
                cislo_zaznamu--;
            }
        }
        if (*pocet_zaznamov == novy_pocet_zaznamov)
        {
            printf("Zaznamy neboli zistene\n");                                                                              //ked neexistuju zaznami do aktualneho datumu a z odnatiim VP
        }
        else
        {
           *pocet_zaznamov = novy_pocet_zaznamov;
        }
    }
}


void s_function(int *pocet_zaznamov, POLE_STRUKTUR **MASSIVE)
{
    if (MASSIVE != NULL)
    {
        int posun;
        scanf("%d", &posun);
        
        for (int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
        {
            unsigned long dlzka_mena = strlen( (*MASSIVE)[cislo_zaznamu].meno_priezvisko );
            for (int cislo_znaku = 0; cislo_znaku < dlzka_mena; cislo_znaku++)
            {
                if ( (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] != ' ' )                                                                   //kodovanie, posun o n
                    (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] += posun;
                if ( (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] > 'Z' && (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] < 'a' )   //pripad ked  'Z' < pismeno < 'a'
                {
                    (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] = (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] - 'Z' + 'A' - 1;
                    
                }
                else
                {
                    if ( (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] > 'z' )                                                                 //pripad ked 'z' < pismeno
                    {
                        (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku] = (*MASSIVE)[cislo_zaznamu].meno_priezvisko[cislo_znaku]- 'z' + 'a' - 1;
                    }
                }
            }
        }
    }
}


void l_function(int *pocet_zaznamov, FILE **file, POLE_STRUKTUR **MASSIVE)
{
    *file = fopen("/Users/olesia/Desktop/FIIT STU/MIP/MIP_PrPr_project1/project/priestupky.txt", "w");   //otvoranie suboru pre prepisanie
    
    for( int cislo_zaznamu = 0; cislo_zaznamu < *pocet_zaznamov; cislo_zaznamu++)
    {
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].meno_priezvisko );
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].pohlavie );
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].rok_narodenia );
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].SPZ );
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].typ_priestupku );
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].vyska_pokuty );
        fprintf( *file, "%s\n", (*MASSIVE)[cislo_zaznamu].datum_priestupku );
        fputc( '\n', *file );
    }                                                                                                    //tlac udajov do suboru
    fclose(*file);
}

void k_function(FILE **file, POLE_STRUKTUR **MASSIVE)
{
    if ((*file=fopen("/Users/olesia/Desktop/FIIT STU/MIP/MIP_PrPr_project1/project/priestupky.txt", "r")) != NULL)
    {
        fclose(*file);       //zatvorenie suboru
    }
    free(*MASSIVE);          //uvolnenie pola
    exit(EXIT_SUCCESS);      //ukoncenie programu
}
