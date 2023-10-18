#include "../header/tools.h"
#include "../header/view.h"
#include "../header/controler.h"
#include "../header/model.h"
#include <stdlib.h>

char mainmenu ()
{ 
    char choice ;
    printf ("\t0 - Exit\n
            \t1 - Login\n
            \t2 - New profile\n
            ")
    readchar (&choice) ;
    while (choice != '0' && choice != '1' && choice != '2')
    {
        printf ("\t0 - Exit\n
            \t1 - Login\n
            \t2 - New profile\n
            ")
        readchar (&choice) ;
    }
}

char* login ()
{
    printf ("login is working") ;
    return NULL ;
}

char* newprofile ()
{
    printf ("newprofile is working") ;
    return NULL ;
}

int main ()
{
    system ("clear") ;
    char mainchoice ;
    char name[5] ;
    mainchoice = mainmenu () ;
    while (mainchoice != '0')
    {
        switch (mainchoice){
        case '1' :
            name = login () ;
            break ;
        
        case '2' :
            name = newprofile () ;
            break ;
        }

        control (name) ;
        system ("clear") ; 
        mainchoice = mainmenu () ;   
    }  
    
    return 0 ;
}