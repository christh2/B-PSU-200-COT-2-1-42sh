/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** word in double array
*/
#include "../include/shell.h"

char** alloc_arr(char **arr, char *str, char *line)
{
    int *tab = count_cols(str,line);int y = count_lines(str, line);
    arr = (char**)malloc(sizeof(char*) * (y + 1));
    for (int i = 0;i < y;i++) {
        arr[i] = (char*)malloc(sizeof(char) * (tab[i] + 1));
    }
    free(tab);
    return arr;
}

void init_arr(char **arr, char *str, char *line)
{
    int a = 0,b = 0;
    for (int i = 0;str[i] != '\0';i++) {
        if (check(str[i], line) == 1) {
            arr[b][a] = str[i];a++;
        } if (check(str[i], line) == 1 && check(str[i + 1], line) == 0) {
            arr[b][a] = '\0';a = 0;b++;
        }
    }
    arr[b] = NULL;
}

char** str_word_array(char *word, char *sep)
{
    char **arr;
    arr = alloc_arr(arr,word,sep);
    init_arr(arr,word,sep);
    return arr;
}

void free_tab(char **arr)
{
    for (int i = 0;arr[i];i++) {
        free(arr[i]);
    }
    free(arr);
}
