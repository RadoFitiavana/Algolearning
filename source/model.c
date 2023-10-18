#include "../header/model.h"
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

void adduser (user u)
{ 
    int rc ;  
    sqlite3* db ;
    rc = sqlite3_open ("../data/data.sq3", &db) ;

    if (rc != SQLITE_OK)
    {
        printf ("Une erreur s'est produite") ;
    }
    else
    {
        const char* sql = "INSERT INTO users (name, lev, sco1, sco2, sco3, sco4) VALUES (?, ?, ?, ?, ?, ?)" ;
        sqlite3_stmt* stmt ;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
        rc = sqlite3_bind_text(stmt, 1, u.username, -1, SQLITE_STATIC);
        rc = sqlite3_bind_int(stmt, 2, u.level) ;
        rc = sqlite3_bind_int(stmt, 3, u.score1) ;
        rc = sqlite3_bind_int(stmt, 4, u.score2) ;
        rc = sqlite3_bind_int(stmt, 5, u.score3) ;
        rc = sqlite3_bind_int(stmt, 6, u.score4) ;
        rc = sqlite3_step (stmt) ;
        sqlite3_finalize (stmt) ;
        sqlite3_close (db) ;
    }
}

void deluser (char* name)
{
    int rc ;
    sqlite3* db ;
    rc = sqlite3_open ("../data/data.sq3", &db) ;

    if (rc != SQLITE_OK)
    {
        printf ("Une erreur s'est produite") ;
    }
    else
    {
        const char* sql = "DELETE FROM users WHERE name=?" ;
        sqlite3_stmt* stmt ;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0) ;
        rc = sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) ;
        rc = sqlite3_step(stmt) ;
        sqlite3_finalize(stmt) ;
        sqlite3_close(db) ;
    } 
}

int finduser (char* name)
{
    int rc ;
    sqlite3* db ;
    rc = sqlite3_open ("../data/data.sq3", &db) ;

    if (rc != SQLITE_OK)
    {
        printf ("Une erreur s'est produite") ;
    }
    else
    {
        const char* sql = "SELECT name FROM users WHERE name=? " ;
        sqlite3_stmt* stmt ;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0) ;
        rc = sqlite3_bind_text (stmt, 1, name, -1, SQLITE_STATIC) ;
        rc = sqlite3_step (stmt) ;
        if (rc != SQLITE_ROW)
        {
            rc = 1 ;
        }
        else
        {
            rc = 0 ; 
        }

        sqlite3_finalize (stmt) ;
        sqlite3_close (db) ;

        return rc ;
    }
}

user* readuser (char* name)
{
    user* pu = NULL ;
        int rc ;
        sqlite3* db ;
        rc = sqlite3_open ("../data/data.sq3", &db) ;

        const char* sql = "SELECT * FROM users WHERE name=?" ;
        sqlite3_stmt* stmt ;
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0) ;
        rc = sqlite3_bind_text (stmt, 1, name, -1, SQLITE_STATIC) ;
        rc = sqlite3_step (stmt) ;
        char* nom = (char*) sqlite3_column_text(stmt, 0) ;
        strncpy (pu->username, nom, sizeof(pu->username) - 1) ;
        pu->username[sizeof(pu->username) - 1] = '\0';
        pu->level = sqlite3_column_int(stmt, 1) ;
        pu->score1 = sqlite3_column_int(stmt, 3);
        pu->score2 = sqlite3_column_int(stmt, 4);
        pu->score3 = sqlite3_column_int(stmt, 5);
        pu->score4 = sqlite3_column_int(stmt, 6);
        sqlite3_finalize (stmt) ;
        sqlite3_close (db) ;
    
    return pu ;
}