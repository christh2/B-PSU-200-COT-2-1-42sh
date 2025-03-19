/*
** EPITECH PROJECT, 2023
** prompt
** File description:
** 42sh
*/

#include"../include/shell.h"

pid_t run_cmd(char *line, shell *ptr)
{
    int s;
    pid_t n = fork();
    if (n == 0) {
        execve(line, ptr->arg, ptr->env);
    } else {
        return n;
    }
}

void browse_dir(shell *ptr)
{
    int s;
    for (int i = 0;ptr->dir[i];i++) {
        char *line = concat_strings(ptr->dir[i], ptr->arg[0], '/');
        if (access(line, X_OK) == 0) {
            pid_t n = run_cmd(line, ptr);ptr->m = CMD;
            waitpid(n, &s, 0);free(line);break;
        }
        free(line);
    }
}

void case_of_env(shell *ptr, list *env)
{
    if (strcmp(ptr->arg[0], "setenv") == 0
    && set_env_error(ptr->arg, num_of_arg(ptr->arg)) == 1)
        return;
    if (strcmp(ptr->arg[0], "env") == 0) { printer(&env);
    ptr->m = CMD;
    } if (strcmp(ptr->arg[0], "setenv") == 0 && num_of_arg(ptr->arg) == 1) {
        printer(&env);ptr->m = CMD;
    } if (strcmp(ptr->arg[0], "setenv") == 0 && num_of_arg(ptr->arg) == 3) {
        insert_it(&env, ptr->arg[1], ptr->arg[2]);ptr->m = CMD;
    } if (strcmp(ptr->arg[0], "setenv") == 0 && num_of_arg(ptr->arg) == 2) {
        insert_it(&env, ptr->arg[1], "\0");ptr->m = CMD;
    } if (strcmp(ptr->arg[0], "unsetenv") == 0 && num_of_arg(ptr->arg) == 2) {
        delete_it(&env, ptr->arg[1]);ptr->m = CMD;
    } if (strcmp(ptr->arg[0], "unsetenv") == 0 && num_of_arg(ptr->arg) < 2)
        write(1, "unsetenv: Too few arguments.\n", 29);
    if (strcmp(ptr->arg[0], "unsetenv") == 0 && num_of_arg(ptr->arg) > 2)
        write(1, "unsetenv: Too many arguments.\n", 30);
}

void exe_cmd(shell *ptr ,char *str, list *env)
{
    int i = 0;
    int a = 0;
    if (strcmp(ptr->arg[0], "echo") == 0 && num_of_arg(ptr->arg) == 2)
        if (ptr->arg[1][0] == '$') {
            echo_my_var(&env, &ptr->arg[1][1], ptr);
            write(1, "\n", 1);ptr->m = CMD;
        }
    browse_dir(ptr);
    if (ptr->m == NONE) binary(ptr);
}

/*affichage du prompt dans la bouble principale*/
int display_prompt(shell *ptr, list *env)
{
    char *p = "[42sh@fedora]";ptr->and1 = NULL;ptr->and2 = NULL;
    char *str = NULL;ptr->arg = NULL;ptr->cmd = NULL;ptr->coma = NULL;
    size_t n = 0;ptr->c = 0;ptr->ret = 0;
    ptr->dir = put_arr(&env, ptr);
    while (1) {
        write(1, "\e[0;05m", 7);
        write(1, "\e[1;36m[42sh@fedora] \e[0m", 25);
        write(1, "\e[0m", 4);
        if (getline(&str, &n, stdin) == -1)
            exit_mode(ptr, env);ptr->ret = 0;
        delete_char(str, '\n');
        ptr->coma = str_word_array(str, ";");
        if (tab_len(ptr->coma) == 0) continue;
        coma_loop(ptr, env);
        free_tab(ptr->coma);ptr->coma = NULL;
    }
}
