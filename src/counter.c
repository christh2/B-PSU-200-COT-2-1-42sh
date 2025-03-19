/*
** EPITECH PROJECT, 2023
** shell
** File description:
** counter
*/
#include "../include/shell.h"

int line_nbr(char *line, char *sep)
{
    int y = 0;
    for (int i = 0; line[i] != '\0';i++) {
        if (line[i] == sep[0] && line[i + 1] == sep[1])
            y++;
    }
    return y + 1;
}

int* cols_nbr(char *line, char *sep)
{
    int y = line_nbr(line, sep);int a = 0;int x = 0;
    int *tab = (int*)malloc(sizeof(int) * y);
    for (int i = 0;line[i] != '\0';i++) {
        if (line[i] == sep[0] && line[i + 1] == sep[1]) {
            (line[i + 1] == sep[1]) ? (tab[a] = x,x = 0,a++) : 0;
        } if ((line[i] != sep[0]) || (line[i] == sep[0]
        && i - 1 >= 0 && line[i - 1] != sep[0] && line[i + 1] != sep[0]) ) {
            x++;
        }
    }
    tab[a] = x;
    return tab;
}
