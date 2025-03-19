/*
** EPITECH PROJECT, 2023
** count
** File description:
** count elem
*/
#include "../include/shell.h"

int check(char c, char *line)
{
    for (int i = 0;line[i] != '\0';i++) {
        if (c == line[i])
            return 0;
    }
    if (c == '\0')
        return 0;
    return 1;
}

int count_lines(char *str, char *line)
{
    int y = 0;
    for (int i = 0;str[i] != '\0';i++) {
        if (check(str[i], line) == 1 && check(str[i + 1], line) == 0) {
            y++;
        }
    }
    return y;
}

int* count_cols(char *str, char *line)
{
    int y = count_lines(str,line);
    int *tab = (int*)malloc(sizeof(int) * y);
    int a = 0;int x = 0;
    for (int i = 0;str[i] != '\0';i++) {
        if (check(str[i], line) == 1)
            x++;
        if (check(str[i], line) == 1 && check(str[i + 1], line) == 0) {
            tab[a] = x;x = 0;a++;
        }
    }
    return tab;
}
