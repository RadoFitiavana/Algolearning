#ifndef TOOLS_H
#define TOOLS_H

/*Lecture au clavier d'une chaine de caractères */
void readstr (char*, int) ;
// char*: pointeur sur la mémoire de la chaine à lire
// int: nombre de caractère à lire

/*Clear le buffer après une lecture au clavier*/
void clearbuffer () ;

/*Lecture d'un caractère au clavier*/
void readchar (char*) ;
// char* : pointeur sur le caractère à lire

#endif