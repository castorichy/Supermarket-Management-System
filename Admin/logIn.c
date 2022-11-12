#include "func_h.h"

/**
 * 
*/

int check_user(void)
{
    int user;
    system("clear");
    printf("Select User;\n1. Admin. \n2. castomer care.\n");
    scanf("%d", &user);

    if (user == 1)
        return (1);
    else if (user == 2)
        return (2);
    else
        return (0); 
}

/**
 * 
*/
void logIn(void)
{
    int logStatus;
    log_in *UserDetailsSignUp = malloc(sizeof(log_in) * 100);
    log_in *UserDetailsLogIn = malloc(sizeof(log_in) * 100);
    /*char *name = malloc(sizeof(char) * 100);
    char *passwd = malloc(sizeof(char) * 20);*/
    char *userNAme = malloc(sizeof(char) * 20);
    int user = check_user();

    if (!UserDetailsLogIn || !UserDetailsSignUp)
    {
        printf("Error allocating memory\n");
        exit(-1);
    }
    if (user == 1)
        strcpy(userNAme, "Admin");
    else if (user == 2)
        strcpy(userNAme, "castomer care");
    else{
        printf("Invalid user please recheck user");
        exit(EXIT_FAILURE);
    }

    printf("\n\tWELCOME TO CASTORICHY SUPERMAKET\n\tPlease Sign Up TO Your account\n");
    printf("________________________________________________________________\n");
    printf("\n\t%s POTAL\n", userNAme);
    printf("Please enter your First name: ");
    scanf("%s", UserDetailsSignUp->Fname);
    printf("\n");
    printf("________________________________________________________________\n");
    printf("Please enter your Second name: ");
    scanf("%s", UserDetailsSignUp->Sname);
    printf("\n");
    printf("________________________________________________________________\n");
    printf("Please enter your password: ");
    scanf("%s", UserDetailsSignUp->passwd);
    printf("\n");

    system("clear");
    printf("\n\tWELCOME TO CASTORICHY SUPERMAKET\n\tPlease Log In TO Your account\n");
    printf("________________________________________________________________\n");
    printf("\n\t%s POTAL\n", userNAme);
    printf("Please enter your name: ");
    scanf("%s", UserDetailsLogIn->Fname);
    printf("\n");
    printf("________________________________________________________________\n");
    printf("Please enter your password: ");
    scanf("%s", UserDetailsLogIn->passwd);
    printf("\n");
    logStatus = checkLogin(UserDetailsSignUp->Fname,
        UserDetailsSignUp->passwd, 
        UserDetailsLogIn->Fname,
        UserDetailsLogIn->passwd
        );
    if (logStatus == 0)
        printf("Home page on Development\n");
    else
    {
        printf("You Enterd Wrong Password or First name\n");
        free(UserDetailsLogIn);
        free(UserDetailsSignUp);
        exit(EXIT_FAILURE);
    }
    free(UserDetailsLogIn);
    free(UserDetailsSignUp);
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