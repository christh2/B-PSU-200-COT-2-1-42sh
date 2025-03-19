/*
** EPITECH PROJECT, 2022
** concat_strings
** File description:
** phoenix
*/

#include"../include/shell.h"

char *concat_strings(char *src, char *src2,char c)
{
    int i;
    int j;
    int n1 = strlen(src);
    int n2 = strlen(src2);
    char *dest = malloc(sizeof(char) * (n1 + n2 + 1));
    for ( i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = c;
    i++;
    for ( j = 0 ; src2[j] != '\0'; j++) {
        dest[i] = src2[j];
        i++;
    }
    return dest;
}

char *concat_str(char *src, char *src2)
{
    int i;
    int j;
    int n1 = strlen(src);
    int n2 = strlen(src2);
    char *dest = malloc(sizeof(char) * (n1 + n2 + 1));
    for ( i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for ( j = 0 ; src2[j] != '\0'; j++) {
        dest[i] = src2[j];
        i++;
    }
    return dest;
}
