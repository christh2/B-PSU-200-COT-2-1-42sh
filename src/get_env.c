/*
** EPITECH PROJECT, 2023
** shell
** File description:
** get env
*/
#include "../include/shell.h"

char** put_arr(list **ptr, shell *d)
{
    int a = 0;
    list *tmp = *ptr;
    while (tmp) {
        if (my_strncmp("PATH",tmp->str,4)) {
            char *str = skip_str(tmp->str,6);
            (str == NULL) ? (a = 1) : 0;
            switch (a) {
                case 1 :
                    d->c = 1;
                    return NULL;
            }
            char **arr = str_word_array(str, ":");
            free(str);return arr;
        }
        tmp = tmp->next;
    }
    return NULL;
}
