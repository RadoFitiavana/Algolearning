#include "../header/controler.h"
#include "../header/tools.h"
#include "../header/model.h"

char menu ()
{
    char choice = 'a' ;
    while (choice != '0' && choice != '1' && choice != '2')
    {
        printf ("Veuillez choisir parmi les options données\n") ;
        printf ("\t0 - Exit\n
            \t1 - Continu\n
            \t2 - New game\n") ;

        printf ("-> ") ;
        readchar (&choice) ;
    }

    return choice ;
    
}

void control (char* name)
{
    char choice = menu () ;
    
}
