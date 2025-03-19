/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** 42sh
*/

#include"../include/shell.h"

int my_strlen(char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
