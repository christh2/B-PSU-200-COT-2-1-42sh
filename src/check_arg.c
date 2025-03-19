/*
** EPITECH PROJECT, 2023
** check_arg
** File description:
** minishell1
*/

#include"../include/shell.h"

int check_arg(shell *ptr, char *str)
{
    if (strcmp(ptr->arg[0], "cd") == 0 ||
        strcmp(ptr->arg[0], "env") == 0 ||
        strcmp(ptr->arg[0], "setenv") == 0 ||
        strcmp(ptr->arg[0], "unsetenv") == 0 ||
        strcmp(ptr->arg[0], "exit") == 0) {
        return 0;
    }
    return 1;
}

int num_of_arg(char **arg)
{
    int i = 0;
    for (i = 0; arg[i] != NULL; i++);
    return i;
}

void delete_char(char *line, char c)
{
    for (int i = 0;line[i] != '\0';i++) {
        if (line[i] == c)
            line[i] = '\0';
    }
}

bool check_condition(char *line, char c)
{
    bool a = false;
    for (int i = 0;line[i] != '\0';i++) {
        if (check(line[i], "\t\n ") == 1 && line[i] != c)
            a = true;
        if (check(line[i], "\t\n ") == 1 && line[i] == c && a == false)
            return false;
        if (line[i] == c && line[i + 1] == c && line[i + 2] == c)
            return false;
    }
    return a;
}

bool check_line(char *line, char c)
{
    bool a = check_condition(line, c);
    if (a == false) return false;
    char **arr = str_word_array(line, " \t\n");int l = tab_len(arr);
    if (arr[0][0] == c) {
        free_tab(arr);return false;
    } if (arr[l - 1][0] == c) {
        free_tab(arr);return false;
    }
    for (int i = 0;arr[i];i++) {
        if (arr[i][0] == '|' && arr[i + 1] != NULL
        && arr[i + 1][0] == '|') {
            free_tab(arr);return false;
        }
    }return true;
}
