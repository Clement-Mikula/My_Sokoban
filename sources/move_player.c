/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

void move_player(object_t *pos, int x, int y)
{
    if (check_collision(pos, x, y) == 1)
        return;
    else
    {
        pos->arr[pos->x][pos->y] = ' ';
        pos->x += x;
        pos->y += y;
        pos->arr[pos->x][(pos->y)] = 'P';

        for (int i = 0; pos->o_pos[i] != -1; i += 2)
        {
            if (pos->arr[pos->o_pos[i]][pos->o_pos[i + 1]] == ' ')
                pos->arr[pos->o_pos[i]][pos->o_pos[i + 1]] = 'O';
        }
    }
}

int check_collision(object_t *pos, int x, int y)
{
    if (pos->arr[pos->x + x][pos->y + y] == '#')
        return 1;
    if (pos->arr[pos->x + x][pos->y + y] == 'X')
    {
        if (pos->arr[pos->x + x * 2][pos->y + y * 2] == 'X' ||
            pos->arr[pos->x + x * 2][pos->y + y * 2] == '#')
            return 1;
        else if (pos->o_pos[0] == pos->x && pos->o_pos[1] == pos->y)
            pos->arr[pos->x][pos->y] = '0';
        else
            pos->arr[pos->x + x * 2][pos->y + y * 2] = 'X';
        return 0;
    }
    return 0;
}