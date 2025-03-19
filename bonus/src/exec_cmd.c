/*
** EPITECH PROJECT, 2023
** shell
** File description:
** command
*/
#include "../include/shell.h"

void exec_condition(shell *ptr, char **env, char *exe)
{
    int n = fork();
    if (n == 0) {
        printf("Open\n");
        int fd = open("file", O_RDWR |O_CREAT| O_TRUNC, 0666);
        dup2(fd, 1);
        execve(exe, ptr->arr, env);
        close(fd);
    } else {
        wait(NULL);
    }
}

char* read_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat b;
    stat(file, &b);
    char *str = (char*)malloc(sizeof(char) * b.st_size);
    read(fd, str, b.st_size);
    close(fd);return str;
}

void exec_cmd(shell *ptr, char **env)
{
    for (int i = 0;ptr->dir[i];i++) {
        char *str = concat_with_char(ptr->dir[i], ptr->arr[0], '/');
        //printf("%s\n",str);
        if (access(str, X_OK) == 0) {
           // printf("ok\n");
            exec_condition(ptr, env, str);
            free(str);break;
        }
        free(str);
    }
}
