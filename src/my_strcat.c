/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** .c
*/
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int my_putstr(char const *str);
int my_strlen(const char *str);

char *my_strcat(char *f1, char *f2)
{
    int a = strlen(f1);
    int b = strlen(f2);
    char *str = (char *)malloc(sizeof(char) * (a + b + 1));
    for (int x = 0; x < a; x++)
        str[x] = f1[x];
    for (int x = 0; x <= b; x++)
        str[x + a] = f2[x];
    str[a + b] = '\0';
    return str;
}

char *my_strcpy(char *src)
{
    int a = 0;
    char *dest = (char *)malloc(sizeof(char) * strlen(src));
    for (; src[a] != '\0'; a++)
        dest[a] = src[a];
    dest[a] = '\0';
    return dest;
}
