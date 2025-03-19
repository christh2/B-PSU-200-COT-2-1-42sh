/*
** EPITECH PROJECT, 2023
** shell
** File description:
** str functions
*/
#include "../include/shell.h"

int my_strlen(char *str)
{
    int i = 0;
    for (;str[i] != '\0';i++);return i;
}

int tab_len(char **arr)
{
    int i = 0;
    for (;arr[i];i++);return i;
}

bool my_strcmp(char *str, char *tab)
{
    if (my_strlen(str) != my_strlen(tab))
        return false;
    for (int i = 0;str[i] != '\0';i++) {
        if (str[i] != tab[i])
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

char* new_str(char *tab, int n)
{
    int a = 0;
    int x = my_strlen(tab) - n;
    char *str = (char*)malloc(sizeof(char) * (x + 1));
    for (int i = n;tab[i] != '\0';i++) {
        str[a] = tab[i];a++;
    }
    str[a] = '\0';
    return str;
}
