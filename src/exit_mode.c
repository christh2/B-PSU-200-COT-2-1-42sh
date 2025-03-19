/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell
*/
#include "../include/shell.h"

void exit_mode(shell *ptr, list *env)
{
    if (ptr->and1 != NULL) free_tab(ptr->and1);
    if (ptr->dir != NULL) free_tab(ptr->dir);
    if (ptr->arg != NULL) free_tab(ptr->arg);
    if (ptr->and2 != NULL) free_tab(ptr->and2);
    if (ptr->coma != NULL) free_tab(ptr->coma);
    freezer(&env);
    exit(ptr->ret);
}
