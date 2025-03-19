/*
** EPITECH PROJECT, 2023
** rights
** File description:
** find rights
*/
#include <sys/stat.h>
#include <stdio.h>
#include "../include/shell.h"

int fst_right(char *str)
{
    struct stat b;
    stat(str, &b);
    mode_t mode = b.st_mode;
    if (S_ISDIR(mode))
        return 0;
    if (S_ISREG(mode))
        return 1;
}

char** tab_dup(char **tab)
{
    int y = tab_len(tab);
    char **arr = (char**)malloc(sizeof(char*) * (y + 1));
    for (int i = 0;i < y;i++) {
        arr[i] = strdup(tab[i]);
    }
    arr[y] = NULL;
    return arr;
}
