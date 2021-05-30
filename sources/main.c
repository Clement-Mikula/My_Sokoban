/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#include "my.h"

void move_p(object_t *pos, int key)
{
    if (key == KEY_DOWN)
        move_player(pos, 1, 0);
    if (key == KEY_UP)
        move_player(pos, -1, 0);
    if (key == KEY_LEFT)
        move_player(pos, 0, -1);
    if (key == KEY_RIGHT)
        move_player(pos, 0, 1);
}

void reload_map(object_t *pos, int key, char *buffer)
{
    if (key == ' ')
        pos->arr = my_str_to_word_array(buffer, '\n');
}

void game_loop(object_t *pos, char *buffer)
{
    int key = 0;
    int i = 0;

    while (key != '\n')
    {
        clear();
        i = verify_terminal_size(pos);
        if (i != 1)
            display_map(pos);
        get_p_pos(pos, 'P');
        key = getch();
        reload_map(pos, key, buffer);
        move_p(pos, key);
        display_map(pos);
        refresh();
        game_end(pos);
        game_loose(pos);
    }
}

void sokoban(char *argv[])
{

    char *buffer = create_buff(argv[1]);
    initscr();
    object_t pos;
    pos.screen = newwin(1000, 1000, 0, 0);
    noecho();
    curs_set(FALSE);
    keypad(stdscr, true);
    pos.arr = my_str_to_word_array(buffer, '\n');
    get_o_pos(&pos);
    error_handling(&pos);

    game_loop(&pos, buffer);

    endwin();
}

int main(int argc, char *argv[])
{
    help(argc, argv);
    sokoban(argv);
    return 0;
}