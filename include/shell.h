/*
** EPITECH PROJECT, 2023
** shell
** File description:
** minishell project header
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>

#ifndef SHELL_H_
    #define SHELL_H_

/*Enumération des états du shell
NONE : aucune commande n'est exécutée
CMD  : commande exécutée
*/
typedef enum state state;
enum state {
    NONE,CMD,SEMI
};

typedef struct list {
    char *str;
    struct list *next;
} list;

/*Structure du shell
dir : double tableau des répertoires de PATH
arg : double tableau des arguments
cmd : double tableau des séparateurs
*/
typedef struct shell shell;
struct shell {
    char **dir;
    char **coma;
    char **and1;
    char **and2;
    char **arg;
    char **cmd;
    state m;
    char *line;
    char **env;
    int c;int d;
    int rtn;
    int ret;
    int status;
};
int check(char c, char *line);
int count_lines(char *str, char *line);
int* count_cols(char *str, char *line);
void free_tab(char **arr);
char** alloc_arr(char **arr, char *str, char *line);
void init_arr(char **arr, char *str, char *line);
char** str_word_array(char *word, char *sep);
void free_tab(char **arr);
void printer(list **env);
void add_to_list(list **env, char *str);
int num_of_arg(char **arg);
char *my_strcat(char *f1, char *f2);
void insert_it(list **env, char *str1, char *str2);
void delete_it(list **env, char *str);
void freezer(list **env);
char *concat_strings(char *src, char *src2,char c);
char *concat_str(char *src, char *src2);
int check_arg(shell *ptr, char *str);
char* skip_str(char *str, int n);
char* new_str(char *str, int n);
bool my_strncmp(char *str, char *tab, int n);
char** put_arr(list **ptr, shell *d);
int my_strlen(char *str);
void translate(shell *ptr, char *str, list *env);
void exe_cmd(shell *ptr ,char *str, list *env);
void case_of_env(shell *ptr, list *env);
int tab_len(char **arr);
char** tab_dup(char **tab);
int set_env_error(char **com, int aci);
int translate_end(shell *ptr, char *str, list *env);
int exe_cmd_end(shell *ptr ,char *str);
int coma_loop(shell *ptr, list *env);
int check_str(char *str);
void command_cd(shell *ptr);
void redir_out(char **tab, list *new_env, shell *ptr);
void redir_outout(char **tab, list *env, shell *ptr);
void redir_in(char **tab, list *env, shell *ptr, int a);
void pip(shell *ptr, list *env, char **tab);
int line_nbr(char *line, char *sep);
int* cols_nbr(char *line, char *sep);
char** make_array(char *word, char *sep);
bool check_line(char *line, char c);
void delete_char(char *line, char c);
void exit_mode(shell *ptr, list *env);
void binary(shell *ptr);
int main(int ac, char **av, char **env);
int display_prompt(shell *ptr, list *env);
int check_str(char *str);
int status_error(int status);
void echo_my_var(list **env, char *str, shell *ptr);

#endif
