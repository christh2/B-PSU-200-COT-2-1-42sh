/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** status_error
*/

#include"../include/shell.h"

int status_error(int status)
{
    if (WIFSIGNALED(status)) {
        if ( WTERMSIG(status) == SIGSEGV) {
            printf("Segmentation fault\n");
            return 139;
        }
        if ( WTERMSIG(status) == SIGFPE) {
            printf("Floating exception\n");
            return 136;
        }
    }
}
