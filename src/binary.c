/*
** EPITECH PROJECT, 2023
** shell
** File description:
** binary
*/
#include "../include/shell.h"

void binary(shell *ptr)
{
    if (access(ptr->arg[0], X_OK) == 0) {
        ptr->m = CMD;
        pid_t n = fork();
        if (n == 0) {
            execve(ptr->arg[0],ptr->arg,ptr->env);
        } else {
            int s;
            waitpid(n, &s, 0);status_error(s);
        }
    }
}

int check_str(char *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '&' && str[a + 1] == '&')
            return 1;
        if (str[a] == '>' && str[a + 1] != '>') return 2;
        if (str[a] == '>' && str[a + 1] == '>' && str[a + 2] != '>')
            return 3;
        if (str[a] == '<' && str[a + 1] != '<') return 4;
        if (str[a] == '|' && str[a + 1] != '|') return 5;
    }
    return 0;
}
