#ifndef FUNC_H_H
#define FUNC_H_H

/*headers*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*----------------------
|      structure        |
------------------------*/
typedef struct lst
{
    char itemName[20];
    int quantity;
    int Price;
    int ItemNumber;
    struct lst *next;
}item_lst;

typedef struct log
{
    char userName[20];
    char passwd[20];
}log_in;

        /*----------------------
        |      Prototypes        |
        ------------------------*/

 /*----------------------
|      login.c file    |
------------------------*/
int checkLogin(char *Sign_name, char *Sign_password, char *Log_name, char *Log_password);
void adminLogin(void);

/*----------------------
|      Dashboad.c file    |
------------------------*/
int AdminDashboard();
void hearder();
int handleChoices(int code);
int addItems();
int viewItems();
int addCastomer();
int printReciept();
int help();
void handleChoiceError();
void ToMainMenu();

#endif /*FUNC_H_H*/