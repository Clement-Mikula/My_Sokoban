/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

int error_handling(object_t *pos)
{
    for (int i = 0; pos->arr[i] != NULL; i++)
    {
        for (int j = 0; j != '\0'; j++)
        {
            if (pos->arr[i][j] == '#' || pos->arr[i][j] == ' ' ||
                pos->arr[i][j] == 'X' || pos->arr[i][j] == 'P' ||
                pos->arr[i][j] == 'O' || pos->arr[i][j] == '\n')
                NULL;
            else
                return 84;
        }
    }
}