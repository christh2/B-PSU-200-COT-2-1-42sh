/*
** EPITECH PROJECT, 2023
** shell
** File description:
** shell
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <fcntl.h>
#include <SFML/Graphics/RenderWindow.h>
#include <stdbool.h>
#include <sys/wait.h>

#ifndef SHELL_H_
    #define SHELL_H_

typedef struct list list;
struct list {
    int n;
    char c;
    list *next;
};

typedef struct control control;
struct control {
    list *first;
};

typedef enum state state;
enum state {
    START,END,
};

typedef struct shell shell;
struct shell {
    char **arr;
    char **map;
    char **dir;
    char *out;
};

typedef struct window window;
struct window {
    sfRenderWindow *win;
    sfVideoMode mode;
    char *title;
    sfEvent event;sfFont *font;sfText *text;
    char *cmd;sfText *tab;
    control *fst;int p;
    sfRectangleShape *rect;
    sfRectangleShape *curs;
    int c;state m;shell sh;
    sfText *ot;
};

void event(window *ptr);
void display_window(window *ptr, char **env);
list* create_node(char c, int n);
void add_to_list(control *fst, list *node);
void free_list(control *fst);
void delete_node(control *fst, int n);
char* init_str(control *fst);
int list_len(control *fst);
void convert_vector(int p, window *ptr);
char** str_word_array(char *word, char *sep);
int check(char c, char *line);
int count_lines(char *str, char *line);
int* count_cols(char *str, char *line);
void free_tab(char **arr);
int my_strlen(char *str);
int tab_len(char **arr);
bool my_strcmp(char *str, char *tab);
bool my_strncmp(char *str, char *tab, int n);
char* new_str(char *tab, int n);
void init_dir(shell *ptr, char **env);
char* concat_with_char(char *str, char *tab, char c);
void exec_cmd(shell *ptr, char **env);
void end_condition(char *line, window *ptr, char **env);
char* read_file(char *file);

#endif
