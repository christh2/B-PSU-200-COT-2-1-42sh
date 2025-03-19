/*
** EPITECH PROJECT, 2023
** shell
** File description:
** new str
*/
#include "../include/shell.h"

char* new_str(char *str, int n)
{
    int a = my_strlen(str);
    int x = a - n;
    char *tab = (char*)malloc(sizeof(char) * x);
    int b = 0;
    for (int i = n - 1;str[i] != '\0';i++) {
        tab[b] = str[i];b++;
    }
    return tab;
}

char* skip_str(char *str, int n)
{
    int a = my_strlen(str);
    int x = a - n;
    if (x == 0) {
        return NULL;
    }
    char *tab = (char*)malloc(sizeof(char) * x);
    int b = 0;
    for (int i = n - 1;str[i] != '\0';i++) {
        tab[b] = str[i];b++;
    }
    return tab;
}

bool is_numeric(char c)
{
    if (c <= '9' && c >= '0')
        return true;
    else
        return false;
}

bool is_alpha(char c)
{
    if ((c <= 'Z' && c >= 'A') ||
    (c >= 'a' && c <= 'z'))
        return true;
    else
        return false;
}
