/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

void help(int argc, char **argv)
{
    if (argc != 2)
        exit(84);
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n\n");
        my_putstr("map:   file representing the warehouse map");
        my_putstr(", containing ‘#’ for walls, \n");
        my_putstr("     ‘P’ for the player, ‘X’ for boxes");
        my_putstr(" and ‘O’ for storage locations.\n");
        exit (0);
    }
}