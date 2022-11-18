#include "func_h.h"

const int max_items = 20;

/**
 * hearder - andmin hearder page
 * 
 * Return: Nothing
*/
void hearder()
{
    system("clear");
    printf("**************************************************************\n");
    printf("*                 SuperMarket Management System              *\n");
    printf("*                                                            *\n");
    printf("*                         Admin Dashboard                    *\n");
    printf("**************************************************************\n\n");
}

/**
 * AdminDashboard - Admin Dashboard
 * @userName: andmin Named Name
 * 
 * Return: 0 When Success or -1 when Failure
*/

int AdminDashboard()
{
    int code;

    hearder();

    printf("Code\t\t\t| Choices\t\t| status\n");
    printf("________________________________________________________________\n");
    printf("1. \t\t\tAdd Items\t\tAvailable\n");
    printf("2. \t\t\tView Items\t\tAvailable\n");
    printf("3. \t\t\tAdd Castomer\t\tNot Available\n");
    printf("4. \t\t\tPrint Reciept\t\tNot Available\n");
    printf("5. \t\t\tDelete Items\t\tAvailable\n");
    printf("6. \t\t\tHelp\t\t\tNot Available\n");

    printf("________________________________________________________________\n");
    printf("Enter your Choice code here: ");
    scanf("%d", &code);
    if (code < 1 || code > max_items)
        handleChoiceError();
    else
        handleChoices(code);
    return (0);
}

/**
 * handleChoices - handle the choice given by the user
 * @code: The choice to be handled
 * 
 * Return: 0 if successful or -1 if an error occurred
*/

int handleChoices(int code)
{
    switch (code)
    {
        case 1:
        {
            addItems();
            break;
        }
        case 2:
        {
            viewItems();
            break;
        }
        case 3:
        {
            addCastomer();
            break;
        }
        case 4:
        {
            printReciept();
            break;
        }
        case 5:
        {
            DeleteAllCont();
            break;
        }

        case 6:
        {
            help();
            break;
        }
    }
    return (0);
}

/**
 * addItems - Add Items
 */

void handleChoiceError()
{
    char ch;

    printf("You entered invalid code do you want to return y/n: ");
    scanf("%s", &ch);
    if (ch == 'y' || ch ==  'Y')
    {
        AdminDashboard();
    }
    else if (ch == 'n' || ch ==  'N')
    {
        exit(EXIT_FAILURE);
    }
}

/**
 * 
*/

int addItems()
{
    char ch;
    int numItems, i = 0;
    item_lst *ItemsDetails = malloc(sizeof(item_lst) * max_items);
    
    hearder();
    
    printf("\n\t\tAdd Items\n");
    printf("________________________________________________________________\n");
    printf("Number of Items to add: ");
    scanf("%d", &numItems);

    if (numItems > max_items)
    {
        printf("You can only add up to 5 items at a time\n");
        printf("Do you want to continue? Y/n: ");
        scanf("%s", &ch);

        if (ch == 'y' || ch ==  'Y')
        {
            addItems();
        }
        else if (ch == 'n' || ch ==  'N')
        {
            AdminDashboard();
        }
    }
    else
    {
        while (i < numItems)
        {
            if (ItemsDetails == NULL)
            {
                free(ItemsDetails);
                printf("Not enough memory\n");
                exit(1);
            }

            ItemsDetails[i].ItemNumber = i;
            printf("\t\tItem [%d]\n", ItemsDetails[i].ItemNumber + 1);
            printf("\t\t---------\n");
            printf("\tItem Name: ");
            scanf("%s", ItemsDetails[i].itemName);
            printf("\n\tItem Price: ");
            scanf("%d", &ItemsDetails[i].Price);
            printf("\n\tItem Quantity: ");
            scanf("%d", &ItemsDetails[i].quantity);

            i++;
        }
    }
    i = checkFile(numItems, ItemsDetails);
    if (i == 0)
        ToMainMenu();
    else
        printf("Failed to save items to file");
    free(ItemsDetails);

    return (0);
}

/**
 * 
*/

int viewItems(int itemNumber)
{
    int err;

    (void)itemNumber;

    err = readItemsInFile();

    if (err != 0)
    {
        printf("Nothing in the file\n");
    }
    

    /*char ch;
    int i, size;
    item_lst ItemsDetails[5];

    hearder();

    printf("\n\t\tView Items\n");
    printf("________________________________________________________________\n");
    printf("Do you want to view all Items? Y/n\n");
    scanf("%s", &ch);

    if (ch == 'y' || ch ==  'Y')
    {
        for (i = 0; i < itemNumber; i++)
        {
            printf("Item Number: %d\n\n", ItemsDetails[i].ItemNumber);
            printf("Item Name: %s\n", ItemsDetails[i].itemName);
            printf("Item Price: %d\n", ItemsDetails[i].Price);
            printf("Item Quantity: %d\n\n", ItemsDetails[i].quantity);
        }
    }
    else if (ch == 'n' || ch ==  'N')
    {
        printf("Number of Items to view: ");
        scanf("%d", &size);
        if (size < 1 || size > itemNumber)
        {
            printf("Items are less than 5 please try again");
            AdminDashboard();
        }
        for (i = 0; i < size; i++)
        {
            printf("Item Number: %d\n\n", ItemsDetails[i].ItemNumber);
            printf("Item Name: %s\n", ItemsDetails[i].itemName);
            printf("Item Price: %d\n", ItemsDetails[i].Price);
            printf("Item Quantity: %d\n\n", ItemsDetails[i].quantity);
        }

    }*/
    
    return (0);
}

/**
 * 
*/

int addCastomer()
{
    hearder();
    return (0);
}

/**
 * 
*/

int printReciept()
{
    hearder();
    return (0);
}

int DeleteAllCont()
{
    hearder();
    DeleteAll();
    printf("All content in File deleted\n");
    ToMainMenu();
    return (0);
}

/**
 * 
*/

int help()
{
    hearder();
    return (0);
}

/**
 * 
 */

void ToMainMenu()
{
    char ch;
    printf("Do you want to return to main menu? Y/n: ");
    scanf("%s", &ch);

    if (ch == 'y' || ch ==  'Y')
    {
        AdminDashboard();
    }
    else if (ch == 'n' || ch ==  'N')
    {
        exit(0);
    }
}
