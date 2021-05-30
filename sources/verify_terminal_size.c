/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

int verify_terminal_size(object_t *pos)
{
    int x = 1;
    for (; pos->arr[1][x] != '#'; x++)
    ;
    x++;

    int y = 0;
    for (; pos->arr[y] != NULL; y++)
        ;
    if (COLS < x || LINES < y)
    {
        clear();
        char *str = "please enlarge the terminal\n";
        mvprintw((LINES / 2), COLS / 3, "%s", str);
        return 1;
    }
}