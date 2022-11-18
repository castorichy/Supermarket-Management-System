#include "func.h"

int main(void)
{
    log_st *logsdet = malloc(sizeof(log_st) *100);

    printf("Enter your name: ");
    scanf("%s", logsdet->name);
    printf("Enter your Age: ");
    scanf("%d", &logsdet->age);

    addToFile(logsdet);
    free(logsdet);
    return (0);
}

void addToFile(log_st *logsdet)
{
    int fd, wfd;
    size_t size, n = sizeof(logsdet->name)/sizeof(log_st);
    char getName[50];

    fd = open("list.txt", O_CREAT | O_TRUNC |O_RDWR, 0666);
    if (fd == -1)
    {
        printf("Failed to open list.txt");
        exit(0);
    }

    wfd = write(fd, logsdet->name, sizeof(logsdet->name));
    if (wfd == -1)
    {
        printf("Failed to Write list.txt");
        exit(0);
    }

    size = getline(&getName, &n, fd);
    printf("Your name: %s\n", getName);
    close(fd);
}

