/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

int check_walls_up_right(object_t *pos, int i)
{
    if (pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == '#' ||
        pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == 'X' ||
        pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == 'X' ||
        pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == '#')
        return 1;
}

int check_walls_up_left(object_t *pos, int i)
{
    if (pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == '#' ||
        pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == 'X' ||
        pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == 'X' ||
        pos->arr[pos->x_pos[i] - 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == '#')
        return 1;
}

int check_walls_down_right(object_t *pos, int i)
{
    if (pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == '#' ||
        pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == 'X' ||
        pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == 'X' ||
        pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] + 1] == '#')
        return 1;
}

int check_walls_down_left(object_t *pos, int i)
{
    if (pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == '#' ||
        pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == 'X' ||
        pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == '#' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == 'X' ||
        pos->arr[pos->x_pos[i] + 1][pos->x_pos[i + 1]] == 'X' &&
            pos->arr[pos->x_pos[i]][pos->x_pos[i + 1] - 1] == '#')
        return 1;
}

int check_all_walls(object_t *pos)
{
    int k = 0;

    for (int i = 0; pos->x_pos[i] != -1; i += 2)
    {
        if (check_walls_up_right(pos, i) == 1 ||
            check_walls_up_left(pos, i) == 1 ||
            check_walls_down_left(pos, i) == 1 ||
            check_walls_down_right(pos, i) == 1)
            k++;
    }
    return k;
}