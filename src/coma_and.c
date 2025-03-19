/*
** EPITECH PROJECT, 2023
** coma&&and
** File description:
** 42sh
*/

#include"../include/shell.h"

void redir_if_cut(shell *ptr, int a, list *env)
{
    if (check_str(ptr->and2[a]) == 2) {
        char **tab = str_word_array(ptr->coma[a], " >\n");
        redir_out(tab, env, ptr);
    } if (check_str(ptr->and2[a]) == 3) {
        char **tab = str_word_array(ptr->coma[a], " >>\n");
        redir_outout(tab, env, ptr);
    }
    if (check_str(ptr->and2[a]) == 4) {
        char **tab = str_word_array(ptr->coma[a], "<\n");
        redir_in(tab, env, ptr, a);
    }
    if (check_str(ptr->and2[a]) == 5) {
        char **tab = str_word_array(ptr->coma[a], "|\n");
        pip(ptr, env, tab);
    }
}

int arg_loop(shell *ptr, list *env)
{
    for (int i = 0;ptr->and2[i];i++) {
        if (check_str(ptr->and2[i]) >= 2) {
            redir_if_cut(ptr, i, env);
            continue;
        }
        ptr->arg = str_word_array(ptr->and2[i], " \n\t");
        translate(ptr,"ok", env);
        if (ptr->m == CMD) return 0;
    }
}

int and_condition(int c, shell *ptr, list *env)
{
    if (check_line(ptr->and1[c], '|')) {
        ptr->and2 = make_array(ptr->and1[c], "||");
        arg_loop(ptr, env);free_tab(ptr->and2);ptr->and2 = NULL;
        if (ptr->m == NONE || ptr->m == SEMI)
            return 0;
    } else {
            return 0;
    }return 1;
}

int loop_and(shell *ptr, list *env)
{
    for (int c = 0; ptr->and1[c] != NULL; c++) {
        if (and_condition(c, ptr, env) == 0) return 0;
    }return 1;
}

int coma_loop(shell *ptr, list *env)
{
    for (int a = 0; ptr->coma[a] != NULL; a++) {
        if (check_line(ptr->coma[a], '&')) {
            ptr->and1 = make_array(ptr->coma[a], "&&");
            int n = loop_and(ptr, env);free_tab(ptr->and1);
            ptr->and1 = NULL;
        } else {
            return 0;
        }
    }return 1;
}
