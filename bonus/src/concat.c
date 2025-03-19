/*
** EPITECH PROJECT, 2023
** concat
** File description:
** concat strings
*/
#include "../include/shell.h"

char* concat_with_char(char *str, char *tab, char c)
{
    int a = my_strlen(str);int b = my_strlen(tab);int n = a + b + 1;
    char *dir = (char*)malloc(sizeof(char) * (n + 1));
    int x = 0;
    for (int i = 0;str[i] != '\0';i++) {
        dir[x] = str[i];x++;
    }
    dir[x] = c;x++;
    for (int i = 0;tab[i] != '\0';i++) {
        dir[x] = tab[i];x++;
    }
    dir[x] = '\0';
    return dir;
}

char* add_char(char *tab, char c)
{
    int n = my_strlen(tab);
    char *str = (char*)malloc(sizeof(char) * (n + 2));int i;
    for (i = 0;tab[i] != '\0';i++) {
        str[i] = tab[i];
    }
    str[i] = c;i++;str[i] = '\0';
    return str;
}
