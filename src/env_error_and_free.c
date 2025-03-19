/*
** EPITECH PROJECT, 2023
** env
** File description:
** env
*/

#include "../include/shell.h"

void freezer(list **env)
{
    list *tmp = *env;
    while (tmp != NULL) {
        list *save = tmp;
        tmp = tmp->next;
        free(save);
    }
}

int my_bracket(char *str, char *str2)
{
    int br1 = 0; int br2 = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') br1++;
        if (str[i] == ')') br2++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] == '(') br1++;
        if (str2[i] == ')') br2++;
    }
    if (br1 == 0 && br2 == 0)
        return 0;
    if (br1 > br2)
        write(1, "Too many ('s.\n", 14);
    if (br2 > br1)
        write(1, "Too many )'s.\n", 14);
    if (br1 == br2)
        write(1, "Badly placed ()'s.\n", 19);
    return 1;
}

int char_sanity(char s)
{
    if (!((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z')))
        return 1;
}

int sanity_check(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (char_sanity(str[i]) == 1 && i == 0) {
            write(1, "setenv: Variable name must begin with a letter.\n", 48);
            return 1;
        }
        if (char_sanity(str[i]) == 1 && i != 0) {
            write(1, "setenv: Variable name must ", 27);
            write(1, "contain alphanumeric characters.\n", 33);
            return 1;
        }
    }
}

int set_env_error(char **com, int aci)
{
    if (aci == 3)
        if (my_bracket(com[1], com[2]) == 1)
            return 1;
    if (aci == 2)
        if (my_bracket(com[1], "\0") == 1)
            return 1;
    if (strcmp(com[0], "setenv") == 0 && aci > 1) {
        if (sanity_check(com[1]) == 1)
            return 1;
    }
}
