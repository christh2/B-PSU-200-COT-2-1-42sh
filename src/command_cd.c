/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell
*/
#include "../include/shell.h"
int tab_len(char **arr);
int my_strlen(char *str);
bool my_strcmp(char *str, char *tab);
int fst_right(char *str);

void error_cd(char *file)
{
    if (access(file, F_OK) != 0) {
        printf("%s: No such file or directory.\n", file);
        return;
    } if (fst_right(file) == 1) {
        printf("%s: Not a directory.\n",file);
    }
}

int cd_case(char **arr)
{
    if (tab_len(arr) == 1 || (tab_len(arr) == 2 && my_strcmp(arr[1], "~"))) {
        return 1;
    } if (tab_len(arr) == 2 && my_strcmp(arr[1], "-") == false) {
        return 2;
    }
}

void command_cd(shell *ptr)
{
    if (cd_case(ptr->arg) == 1) {
        char *home = getenv("HOME");
        chdir(home);
    } if (cd_case(ptr->arg) == 2) {
        int n = chdir(ptr->arg[1]);
        n == -1 ? error_cd(ptr->arg[1]), ptr->m = SEMI, ptr->ret = 1 : 0;
        n != -1 ? ptr->m = CMD : 0;
    }
}
