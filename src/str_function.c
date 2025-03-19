/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell
*/
#include "../include/shell.h"

int tab_len(char **arr)
{
    int i = 0;for (;arr[i];i++);return i;
}

bool my_strcmp(char *str, char *tab)
{
    if (my_strlen(str) != my_strlen(tab))
        return false;
    for (int i = 0;str[i] != '\0';i++) {
        if (tab[i] != str[i])
            return false;
    }
    return true;
}

bool my_strncmp(char *str, char *tab, int n)
{
    for (int i = 0;i < n;i++) {
        if (str[i] != tab[i])
            return false;
    }
    return true;
}
