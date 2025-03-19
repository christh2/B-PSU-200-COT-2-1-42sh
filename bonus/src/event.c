/*
** EPITECH PROJECT, 2023
** shell
** File description:
** event management
*/
#include "../include/shell.h"

bool is_valid(char c)
{
    if (c == '\b') {
        return false;
    } else {
        return true;
    }
}

void write_event(window *ptr, char c)
{
    if (is_valid(c)) {
        list *node = create_node(c, ptr->p);
        add_to_list(ptr->fst, node);ptr->p++;
        if (ptr->cmd != NULL) {
            free(ptr->cmd);
        }
        ptr->cmd = init_str(ptr->fst);
    } else {
        delete_node(ptr->fst, ptr->p - 1);ptr->p -= 1;
        if (ptr->cmd != NULL) {
            free(ptr->cmd);
        }
        ptr->cmd = init_str(ptr->fst);
    }
}

void event(window *ptr)
{
    while (sfRenderWindow_pollEvent(ptr->win, &ptr->event)) {
        if (ptr->event.type == sfEvtClosed) {
            sfRenderWindow_close(ptr->win);
        } if (ptr->event.type == sfEvtTextEntered) {
            char c = ptr->event.text.unicode;
            write_event(ptr, c);
        } if (ptr->event.type == sfEvtKeyPressed &&
        ptr->event.key.code == sfKeyEnter) {
            ptr->m = END;
        }
    }
}
