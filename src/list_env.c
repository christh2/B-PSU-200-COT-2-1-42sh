/*
** EPITECH PROJECT, 2023
** list
** File description:
** list
*/

#include "../include/shell.h"

void add_to_list(list **env, char *str)
{
    if (*env == NULL) {
        list *node = (list *)malloc(sizeof(list));
        node->str = str;
        node->next = *env;
        *env = node;
        return;
    }
    list *tmp = (*env);
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    list *node = (list *)malloc(sizeof(list));
    node->str = str;
    node->next = NULL;
    tmp->next = node;
}

void printer(list **env)
{
    list *tmp = *env;
    while (tmp != NULL) {
        write(1, tmp->str, strlen(tmp->str));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}

void echo_my_var(list **env, char *str, shell *ptr)
{
    list *tmp = *env;
    int j = strlen(str);
    char *c = malloc(sizeof(char));
    if (strcmp(str, "?") == 0) {
        printf("%d\n", ptr->rtn);
        return;
    }
    while (tmp != NULL) {
        if (strncmp(tmp->str, str, j) == 0) {
            write(1, &tmp->str[j + 1],strlen(&tmp->str[j + 1]));
            write(1, "\n", 1);
            return;
        }
        tmp = tmp->next;
    }
}

void insert_it(list **env, char *str1, char *str2)
{
    list *tmp = *env;
    while (tmp != NULL) {
        if (strncmp(tmp->str, str1, strlen(str1)) == 0) {
            tmp->str = my_strcat(my_strcat(str1, "="), str2);
            return;
        }
        tmp = tmp->next;
    }
    add_to_list(env, my_strcat(my_strcat(str1, "="), str2));
}

void delete_it(list **env, char *str)
{
    list *tmp = *env;
    while (tmp->next != NULL) {
        if (strncmp(tmp->next->str, str, strlen(str)) == 0) {
            list *save = tmp->next;
            tmp->next = tmp->next->next;
            free(save);
            return;
        }
        tmp = tmp->next;
    }
}
