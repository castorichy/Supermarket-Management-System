#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct logstore
{
    char name[50];
    int age;
}log_st;

void addToFile(log_st *);

#endif /* FUNC_H*/