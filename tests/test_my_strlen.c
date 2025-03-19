/*
** EPITECH PROJECT, 2023
** test
** File description:
** strlen
*/

#include"../include/shell.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test (my_strlen, my_strlen) {
    char *str = "42sh";
    int i = 4;
    cr_assert(my_strlen(str) == i);
}
