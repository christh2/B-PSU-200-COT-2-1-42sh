/*
** EPITECH PROJECT, 2023
** shell
** File description:
** window
*/
#include "../include/shell.h"

void init_window(window *ptr)
{
    ptr->mode.bitsPerPixel = 32;ptr->title = "Terminal XFCE";
    ptr->mode.height = 1200;ptr->mode.width = 1500;
    ptr->win = sfRenderWindow_create(ptr->mode, ptr->title,
    sfDefaultStyle, NULL);
    char *file = "mongek/Mongek-Regular.ttf";
    ptr->text = sfText_create();ptr->font = sfFont_createFromFile(file);
    char *prompt = "42sh@fedora/>";sfText_setFont(ptr->text, ptr->font);
    sfText_setString(ptr->text, prompt);
    sfText_setColor(ptr->text, sfGreen);
    sfText_setPosition(ptr->text, (sfVector2f) {0,0});
    sfText_setScale(ptr->text, (sfVector2f) {0.7,0.7});
    ptr->fst = (control*)malloc(sizeof(control));ptr->fst->first = NULL;
    ptr->p = 0;ptr->tab = sfText_create();sfText_setFont(ptr->tab, ptr->font);
    sfText_setColor(ptr->tab, sfWhite);
    sfText_setPosition(ptr->tab, (sfVector2f) {120,0});
    sfText_setScale(ptr->tab, (sfVector2f) {0.7,0.7});ptr->cmd = NULL;
    sfText_setString(ptr->tab, ptr->cmd);
}

void destroy_window(window *ptr)
{
    sfText_destroy(ptr->text);
    sfFont_destroy(ptr->font);
    sfRenderWindow_destroy(ptr->win);
    sfText_destroy(ptr->tab);
    if (ptr->cmd != NULL) {
        free(ptr->cmd);
    }free_list(ptr->fst);sfText_destroy(ptr->ot);
    sfRectangleShape_destroy(ptr->rect);
    sfRectangleShape_destroy(ptr->curs);
}

void init_data(window *ptr, char **env)
{
    ptr->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(ptr->rect, (sfVector2f) {1000, 90});
    sfRectangleShape_setPosition(ptr->rect, (sfVector2f) {118,0});
    sfRectangleShape_setFillColor(ptr->rect, sfBlack);
    ptr->curs = sfRectangleShape_create();
    sfRectangleShape_setSize(ptr->curs, (sfVector2f) {1, 23});
    sfRectangleShape_setFillColor(ptr->curs, sfWhite);
    sfRectangleShape_setPosition(ptr->curs, (sfVector2f) {118, 0});
    ptr->m = START;init_dir(&ptr->sh, env);
    ptr->ot = sfText_create();sfText_setFont(ptr->ot, ptr->font);
    sfText_setColor(ptr->ot, sfWhite);
}
void display_window(window *ptr, char **env)
{
    init_window(ptr);
    init_data(ptr, env);
    while (sfRenderWindow_isOpen(ptr->win)) {
        event(ptr);
        sfText_setString(ptr->tab, ptr->cmd);
        sfRenderWindow_display(ptr->win);
        sfRenderWindow_drawRectangleShape(ptr->win, ptr->rect, NULL);
        sfRenderWindow_drawText(ptr->win, ptr->tab, NULL);
        sfRenderWindow_drawText(ptr->win, ptr->text, NULL);
        sfRenderWindow_drawRectangleShape(ptr->win, ptr->curs, NULL);
        end_condition(ptr->cmd, ptr, env);
        convert_vector(ptr->p, ptr);
    }destroy_window(ptr);
}