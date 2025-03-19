/*
** EPITECH PROJECT, 2023
** shell
** File description:
** main function
*/
#include "../include/shell.h"

int main(int ac, char **av, char **env)
{
    shell ptr;
    ptr.env = tab_dup(env);
    list *new_env = (list *)malloc(sizeof(list));
    new_env = NULL;
    for (int i = 0; env[i] != NULL; i++)
        add_to_list(&new_env, env[i]);
    display_prompt(&ptr, new_env);
    freezer(&new_env);
}
