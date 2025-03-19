/*
** EPITECH PROJECT, 2023
** piper
** File description:
** piper
*/

#include "../include/shell.h"

void dup_the_direction(int pipefd[2], int i, int ac)
{
    if (i == 0) {
        dup2(pipefd[1], 1);
        close(pipefd[1]);
    } else if (i == ac) {
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        close(pipefd[0]);
    } else {
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        pipe(pipefd);
        dup2(pipefd[1], 1);
    }
}

void exec_in_pip_all_cmd(shell *ptr, list *env, char **tab)
{
    int pipefd[2];
    int j;
    pipe(pipefd);
    int in = dup(0);
    int out = dup(1);
    int ac = num_of_arg(tab) - 1;
    for (int i = 0; i <= ac; i++) {
        int tmp0 = dup(0);
        int tmp1 = dup(1);
        ptr->arg = str_word_array(tab[i], " \n");
        dup_the_direction(pipefd, i, ac);
        translate(ptr, tab[i], env);
        dup2(in, 0);
        dup2(out, 1);
        if (i == ac) exit(0);
    }
}

void pip(shell *ptr, list *env, char **tab)
{
    int f = fork();
    if (f == 0)
        exec_in_pip_all_cmd(ptr, env, tab);
    else
        wait(NULL);
}
