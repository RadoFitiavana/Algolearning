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
    char* name = (char*) calloc (5, sizeof(char)) ;
    name[4] = '\0' ;
    printf ("username: ") ;
    readstr (name, 4) ;

    return name ;
}

char* newprofile ()
{
    user u ;
    printf ("entrer un username de 4 caractères: ");
    readstr (u.username, 4) ;
    while (finduser (u.username) == 0)
    {
        printf ("cet username existe déja, veuillez réessayer: ") ;
        readstr (u.username, 4) ;
    }
    adduser (u) ;

    return u.username ;
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