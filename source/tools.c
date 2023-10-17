#include "../header/tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearbuffer ()
{
    int c = 0 ;

    while (c != '\n' && c != EOF)
    {
        // Tant que le buffer n'est pas vide, le nettoyer
        c = getchar () ;
    }
}

void readstr (char* pstr, int dim)
{
    char* search = NULL ; // pointeur de recherche de caractère
    char* tem = NULL ; // temoin de la lecture, NULL si erreur de lecture
    tem = fgets (pstr, dim, stdin) ;

    while (tem == NULL)
    {
        printf ("Une erreur s'est produite, veuillez rééssayer\n") ;
        tem = fgets (pstr, dim, stdin) ;
        system ("clear") ;
    }

    search = strchr (pstr, '\n') ; // recherche de '\n' dans pstr

    while (search != NULL)
    {
        printf ("L'entreée doit contenir %d caractères, veuillez réessayer", dim-1) ;
        tem = fgets (pstr, dim, stdin) ;
        while (tem == NULL)
        {
            printf ("Une erreur s'est produite, veuillez rééssayer\n") ;
            tem = fgets (pstr, dim, stdin) ;
            system ("clear") ;
        }

        search = strchr (pstr, '\n') ; // recherche de '\n' dans pstr
    }
}

void readchar (char* chr)
{
    char* tem = fgets (chr, 1, stdin) ;
    while (tem == NULL)
    {
        printf ("Une erreur s'est produite, veuillez reessayer\n") ;
        tem = fgets (chr, 1, stdin) ;
    }
    clearbuffer () ;
}

