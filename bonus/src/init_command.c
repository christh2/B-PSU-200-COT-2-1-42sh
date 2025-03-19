/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell
*/
#include "../include/shell.h"

int list_len(control *fst)
{
    int n = 0;
    list *tmp = fst->first;
    while (tmp) {
        n++;tmp = tmp->next;
    }
    return n;
}

char* init_str(control *fst)
{
    int n = list_len(fst);
    char *str = (char*)malloc(sizeof(char) * (n + 1));
    int a = 0;list *tmp = fst->first;
    while (tmp) {
        str[a] = tmp->c;a++;
        tmp = tmp->next;
    }
    str[a] = '\0';
    return str;
}

void convert_vector(int p, window *ptr)
{
    if (p == 0) {
        sfRectangleShape_setPosition(ptr->curs, (sfVector2f) {118,0});
    } else {
        sfFloatRect re = sfText_getGlobalBounds(ptr->tab);
        sfRectangleShape_setPosition(ptr->curs, (sfVector2f) {re.left + re.width, 0});
    }
}

void end_condition(char *line, window *ptr, char **env)
{
    if (ptr->m == END) {
        ptr->sh.arr = str_word_array(line, "\n\t ");
        exec_cmd(&ptr->sh, env);free_tab(ptr->sh.arr);
        ptr->sh.out = read_file("file");
        sfText_setString(ptr->ot, ptr->sh.out);
        sfText_setPosition(ptr->ot, (sfVector2f) {700, 400});
        sfRenderWindow_drawText(ptr->win, ptr->ot, NULL);
        ptr->m = START;
    }
}

int get_env(char **env)
{
    char *str = "PATH";
    for (int i = 0;env[i];i++) {
        if (my_strncmp(env[i], str, my_strlen(str))) {
            return i;
        }
    }
    return -1;
}

void init_dir(shell *ptr, char **env)
{
    int n = get_env(env);
    if (n != -1) {
        char *f = "PATH=";
        char *str = new_str(env[n], my_strlen(f));
        ptr->dir = str_word_array(str, ":");free(str);
    }
}
