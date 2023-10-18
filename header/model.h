#ifndef MODEL_H
#define MODEL_H

typedef struct {
    char username[5] ;
    int level ;
    int score1 ;
    int score2 ;
    int score3 ;
    int score4 ;
} user ;

user* readuser (char*) ; 
void adduser (user) ;
void deluser (char*) ;
int finduser (char*) ;


#endif