/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

char *create_buff(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    struct stat stot;
    stat(filepath, &stot);
    char *buffer = malloc(sizeof(char) * stot.st_size);
    int nb;

    if (fd == -1)
        return "1";
    nb = read(fd, buffer, stot.st_size);
    if (nb == -1)
        exit(84);
    if (buffer == NULL)
        exit (84);
    return (buffer);
}

void get_p_pos(object_t *pos, char search)
{
    pos->x = 0;
    pos->y = 0;
    for (int i = 0; pos->arr[i] != NULL; i++)
    {
        for (int j = 0; j != '\n'; j++)
        {
            if (pos->arr[i][j] == search)
            {
                pos->x = i;
                pos->y = j;
            }
        }
    }
}

void get_o_pos(object_t *pos)
{
    int k = 0;
    pos->o_pos = malloc(sizeof(int) * 100);

    for (int i = 0; pos->arr[i] != NULL; i++)
    {
        for (int j = 0; pos->arr[i][j] != '\0'; j++)
        {
            if (pos->arr[i][j] == 'O')
            {
                pos->o_pos[k] = i;
                k++;
                pos->o_pos[k] = j;
                k++;
            }
        }
    }
    pos->o_pos[k] = -1;
}
