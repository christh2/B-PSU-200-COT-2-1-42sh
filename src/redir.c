/*
** EPITECH PROJECT, 2023
** new
** File description:
** redir
*/

#include "../include/shell.h"

void redir_out(char **tab, list *env, shell *ptr)
{
    int id = open(tab[1], O_CREAT | O_RDWR | O_TRUNC, 0666);
    ptr->arg = str_word_array(tab[0], " ");
    int pid = fork();
    if (pid == 0) {
        dup2(id, 1);
        translate(ptr, tab[0], env);
        exit(0);
    } else
        wait(NULL);
}

void redir_outout(char **tab, list *env, shell *ptr)
{
    int id = open(tab[1], O_CREAT | O_APPEND | O_RDWR, 0666);
    ptr->arg = str_word_array(tab[0], " ");
    int pid = fork();
    if (pid == 0) {
        dup2(id, 1);
        translate(ptr, tab[0], env);
        exit(0);
    } else
        wait(NULL);
}

void redir_in_secundo(char **tab, list *env, shell *ptr)
{
    char **new = str_word_array(tab[0], " \n");
    int id = open(new[0], O_CREAT | O_RDWR | O_APPEND, 0666);
    ptr->arg = str_word_array(&tab[0][strlen(new[0]) + 1], " \n");
    int pid = fork();
    if (pid == 0) {
        dup2(id, 0);
        translate(ptr, &tab[0][strlen(new[0]) + 1], env);
        exit(0);
    } else
        wait(NULL);
}

void redir_in(char **ol_tab, list *env, shell *ptr, int a)
{
    if (num_of_arg(ol_tab) == 1) {
        redir_in_secundo(ol_tab, env, ptr);
        return;
    }
    char **tab = str_word_array(ptr->coma[a], " <\n");
    int id = open(tab[1], O_RDWR | O_APPEND, 0666);
    ptr->arg = str_word_array(tab[0], " ");
    int pid = fork();
    if (pid == 0) {
        dup2(id, 0);
        translate(ptr, tab[0], env);
        exit(0);
    } else
        wait(NULL);
}
