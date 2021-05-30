/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

void display_map(object_t *pos)
{
    int length = 0;

    for (int i = 0; pos->arr[i] != NULL; i++, length++)
        ;
    for (int i = 0; pos->arr[i] != NULL; i++)
        mvprintw((LINES / 4) + i - 2, COLS / 4, "%s", pos->arr[i]);
}

int game_end(object_t *pos)
{
    int nb_o = 0;
    int k = 0;

    for (; pos->o_pos[nb_o] != -1; nb_o++);
    nb_o /= 2;

    for (int i = 0; pos->o_pos[i] != -1; i += 2)
    {
        if (pos->arr[pos->o_pos[i]][pos->o_pos[i + 1]] == 'X')
            k++;
    }
    if (k == nb_o)
    {
        clear();
        usleep(10000);
        endwin();
        exit(0);
    }
    else
        return 0;
}

void find_boxe(object_t *pos)
{
    pos->x_pos = malloc(sizeof(int) * 100);
    int k = 0;

    for (int i = 0; pos->arr[i] != NULL; i++)
    {
        for (int j = 0; pos->arr[i][j] != '\0'; j++)
        {
            if (pos->arr[i][j] == 'X')
            {
                pos->x_pos[k] = i;
                pos->x_pos[k + 1] = j;
                k += 2;
            }
        }
    }
    pos->x_pos[k] = -1;
}

int check_walls(object_t *pos)
{
    int k = 0;
    int nb_x = 0;

    for (; pos->x_pos[nb_x] != -1; nb_x++)
        ;
    nb_x /= 2;

    k = check_all_walls(pos);

    if (k == nb_x)
    {
        clear();
        usleep(10000);
        endwin();
        exit(1);
    }
}

int game_loose(object_t *pos)
{
    int corner = 0;

    find_boxe(pos);
    corner = check_walls(pos);

    if (corner == 1)
        return 0;
    else
        return 1;
}