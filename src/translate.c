/*
** EPITECH PROJECT, 2023
** shell
** File description:
** translate cmd
*/
#include "../include/shell.h"

void translate(shell *ptr, char *str, list *env)
{
    ptr->m = NONE;
    if (strcmp(ptr->arg[0], "exit") == 0) {
        exit_mode(ptr, env);
    } if (check_arg(ptr, str) == 0) {
        case_of_env(ptr, env);
    } if (strcmp(ptr->arg[0], "cd") == 0) {
        command_cd(ptr);
    } if (check_arg(ptr, str) != 0) {
        exe_cmd(ptr, ptr->arg[0], env);
    } if (ptr->m == NONE)
        printf("%s: Command not found.\n", ptr->arg[0]);
    free_tab(ptr->arg);ptr->arg = NULL;
}

int translate_end(shell *ptr, char *str, list *env)
{
    int j = 0;
    if (check_arg(ptr, str) == 0) {
        case_of_env(ptr, env);
    } else {
        int pid;
        pid = fork();
        if (pid == 0) {
            return (exe_cmd_end(ptr, ptr->arg[0]) == 1) ? 2 : 0;
        } else {
            waitpid(pid, &ptr->rtn, 0);
        }
    } if (strcmp(ptr->arg[0], "exit") == 0)
        exit(0);
    free_tab(ptr->arg);
}

int exe_cmd_end(shell *ptr ,char *str)
{
    int i = 0;
    if (strlen(str) == 0)
        return (0);
    for ( i = 0; ptr->dir[i] != NULL; i++) {
        char *line = concat_strings(ptr->dir[i],str,'/');
        if (access(line, X_OK) == 0) {
            execve(line,ptr->arg,ptr->env);
            free(line);break;
        }
        free(line);
    }
    if (access(ptr->arg[0], X_OK) == 0)
        execve(ptr->arg[0], ptr->arg, ptr->env);
    ptr->m = NONE;return 1;
}
