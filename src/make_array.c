/*
** EPITECH PROJECT, 2023
** shell
** File description:
** make double array
*/
#include "../include/shell.h"

char** alloc_tab(char *line, char *sep)
{
    int y = line_nbr(line, sep);
    int *tab = cols_nbr(line, sep);
    char **arr = (char**)malloc(sizeof(char*) * (y + 1));
    for (int i = 0;i < y;i++) {
        arr[i] = (char*)malloc(sizeof(char) * (tab[i] + 1));
    }
    return arr;
}

void init_tab(char **arr, char *line, char *sep)
{
    int a = 0;int b = 0;
    for (int i = 0;line[i] != '\0';i++) {
        if ((line[i] != sep[0] ) || (line[i] == sep[0] &&
        i - 1 >= 0 && line[i - 1] != sep[0] && line[i + 1] != sep[0])) {
            arr[b][a] = line[i];a++;
        } if (line[i] == sep[0]) {
            (line[i + 1] == sep[1]) ? (arr[b][a] = '\0',b++,a = 0) : 0;
        }
    }b++;
    arr[b] = NULL;
}

char** make_array(char *word, char *sep)
{
    char **arr = alloc_tab(word, sep);
    init_tab(arr, word, sep);return arr;
}
