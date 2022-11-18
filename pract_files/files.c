#include "../Admin/func_h.h"

int main()
{
    FILE *file;
    int i = 0, j = 0;
    char ch, *name, files[50];

    file = fopen("testFile.bin", "w");
    if (file == NULL)
    {
        return -1;
    }
   for (; i < 3; i++)
    {
        fprintf(file, "Code\t\tItem Name \t\t QTY\t\t\tprice\n");
        fprintf(file, "_______________________________________________________________________\n");
        fprintf(file, "1. \t\tRice \t\t\t50\t\t\t120\n");
        fprintf(file, "2. \t\tTrouser\t\t\t40\t\t\t100\n");
        fprintf(file, "3. \t\tflour\t\t\t50\t\t\t300\n");
        fprintf(file, "%s\n", files);
    }
    
    fprintf(file, "Hello world.\n");
    fclose(file);

    file = fopen("testFile.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    name = malloc(sizeof(char) * 1024);
    if (name == NULL)
    {
        free(name);
        return -1;
    }

    /*Deleting contents of a file*/
    /*while (!feof(file))
    {
        fgetc(file);
    }*/
    /*View content of a file*/
    while (!feof(file))
    {
        ch = fgetc(file);
        name[j++] = ch;
    }
    printf("%s\n", name);
    
    fclose(file);
    free(name);
    return (0);
}