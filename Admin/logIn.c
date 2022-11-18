#include "func_h.h"

/**
 * 
*/

int check_user(void)
{
    int user;
    system("clear");
    printf("\t\tSelect User\n\t1. Admin. \n\t2. Cashier.\n");
    scanf("%d", &user);

    if (user == 1)
        return (1);
    else if (user == 2)
    {
        printf("User portal Not Available");
        exit(EXIT_SUCCESS);
    }
    return (0); 
}

/**
 * 
*/
void adminLogin(void)
{
    int logStatus;
    log_in *UserDetailsLogIn = malloc(sizeof(log_in));
    char *userNAme = malloc(sizeof(char) * 20);
    int user = check_user();

    if (!UserDetailsLogIn)
    {
        printf("Error allocating memory\n");
        exit(-1);
    }
    if (user == 1)
        strcpy(userNAme, "Admin");
    else{
        printf("Invalid user please recheck user");
        exit(EXIT_FAILURE);
    }

    home:
    system("clear");
   /* printf("\n\tWELCOME TO CASTORICHY SUPERMAKET\n\tPlease Log In To Your account\n");
    printf("________________________________________________________________\n");*/

    hearder();
    printf("\n\t%s POTAL\n\t\t\tPlease LogIn\n", userNAme);
    printf("______________________________________\n");
    printf("\t\tName: ");
    scanf("%s", UserDetailsLogIn->userName);
    printf("\t\tPassword: ");
    scanf("%s", UserDetailsLogIn->passwd);
    printf("\n");
    /*calling checklogin Function*/
    logStatus = checkLogin("admin",
        "password", 
        UserDetailsLogIn->userName,
        UserDetailsLogIn->passwd
        );

    if (logStatus == 0)
    {
        if(AdminDashboard() == -1)
        {
            printf("Error: Admin Dashboard is not available");
        }
    }
    else
    {
        printf("You Enterd Wrong Password or Username\n");
        goto home;
        free(UserDetailsLogIn);
    }
    free(UserDetailsLogIn);
}

/**
 * 
*/

int checkLogin(char *Sign_name, char *Sign_password, char *Log_name, char *Log_password)
{
    if (strcmp(Log_name, Sign_name) == 0 && strcmp(Log_password, Sign_password) == 0)
        return (0);
    return (-1);
}
