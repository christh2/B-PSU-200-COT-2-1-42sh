/*
** EPITECH PROJECT, 2023
** n_curce
** File description:
** n_curce
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <ncurses.h>
#include <string.h>

int main()
{
    int c;
    initscr(); curs_set(false);
    keypad(stdscr, TRUE); refresh();
    while (c != 32) {
        clear();
        printw("toto\n");
        c = getch();
    } endwin();
    
}
