#ifndef FUNC_H_H
#define FUNC_H_H

/*headers*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*structure*/
typedef struct lst
{
    char *item;
    char *QTY;
    int price;
}item_lst;

typedef struct log
{
    char Fname[20];
    char Sname[20];
    char passwd[20];
}log_in;

/* Prototypes*/
void logIn(void);
int checkLogin(char *Sign_name, char *Sign_password, char *Log_name, char *Log_password);

#endif /*FUNC_H_H*/