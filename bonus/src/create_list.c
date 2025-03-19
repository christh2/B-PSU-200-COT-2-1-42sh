/*
** EPITECH PROJECT, 2023
** shell
** File description:
** list
*/
#include "../include/shell.h"

list* create_node(char c, int n)
{
    list *node = (list*)malloc(sizeof(list));
    node->next = NULL;node->c = c;node->n = n;
    return node;
}

void add_to_list(control *fst, list *node)
{
    if (fst->first == NULL) {
        fst->first = node;
    } else {
        list *tmp = fst->first;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void free_list(control *fst)
{
    list *tmp = fst->first;list *ptr;
    while (tmp) {
        ptr = tmp;
        tmp = tmp->next;
        free(ptr);
    }
    free(fst);
}

void delete_condition(list *node, control *fst, list *prev)
{
    if (node == fst->first) {
        fst->first = node->next;
        node->next = NULL;free(node);
    } else {
        if (prev != NULL) {
            prev->next = node->next;
            node->next = NULL;free(node);
        }
    }
}

void delete_node(control *fst, int n)
{
    list *tmp = fst->first;
    list *prev = NULL;
    while (tmp) {
        if (tmp->n == n) {
            delete_condition(tmp, fst, prev);break;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
