#include "func_h.h"

const int max_itemss = 20;
int num_items = 1;


int DeleteAll()
{
    FILE *file;

    file = fopen("items.txt", "w");
    if (file == NULL)
    {
        return -1;
    }

    if (fgetc(file) != EOF)
        fprintf(file, "%d", EOF);

    fclose(file);
    return (0);
}

/**
 * 
*/

int checkFile(int numItems, item_lst *items)
{
    FILE *file;

    file = fopen("items.txt", "r");
    if (file == NULL)
    {
        return -1;
    }

    if (fgetc(file) != EOF)
    {
        AppendToFile(numItems, items);
        ToMainMenu();
    }
    else
    {
        saveItemsToFile(numItems, items);
        ToMainMenu();
    }

    fclose(file);
    return (0);
}

/**
 * saveItemsToFile - save items to file
 * @numItems: number of items
 * @items: list of items
 * 
 * Return: 0 if successful and -1 otherwise
 */

int saveItemsToFile(int numItems, item_lst *items)
{
    int i = 0;
    FILE *fp;

    fp = fopen("items.txt", "w");
    if (fp == NULL)
    {
        return -1;
    }
    printf("price = %d", items[0].Price);

    fprintf(fp, "Code\t\t| Item Name \t\t| QTY\t\t\t| price\n");
    fprintf(fp, "_______________________________________________________________________\n");
    for (i = 0; i < numItems; i++)
    {
        fprintf(fp, "%d. \t\t\t| %s\t\t\t| %d\t\t\t| %d\n", num_items, items[i].itemName, items[i].quantity, items[i].Price);
        num_items++;
    }
    
    fclose(fp);

    return (0);
}

/**
 * 
*/

int AppendToFile(int numItems, item_lst *items)
{
    int i = 0;
    FILE *fp;

    fp = fopen("items.txt", "a");
    if (fp == NULL)
    {
        return -1;
    }
    printf("price = %d", items[0].Price);

    for (i = 0; i < numItems; i++)
    {
        fprintf(fp, "%d. \t\t\t| %s\t\t\t| %d\t\t\t| %d\n", num_items, items[i].itemName, items[i].quantity, items[i].Price);
        num_items++;
    }
    
    fclose(fp);

    return (0);
}


/**
 * 
*/

int readItemsInFile()
{
    int i = 0;
    FILE *fp;
    char ch, *item_list;

    fp = fopen("items.txt", "r");
    if (fp == NULL)
    {
        return -1;
    }
    item_list = malloc(sizeof(item_lst) * max_itemss);
    if (item_list == NULL)
    {
        free(item_list);
        printf("Error Allocating memory\n");
    }

    while (!feof(fp))
    {
        ch = fgetc(fp);
        item_list[i++] = ch;
    }
    printf("\t\t\tItem list\n");
    printf("________________________________________________________________\n\n");
    printf("%s", item_list);
    
    fclose(fp);
    free(item_list);

    return (0);
}