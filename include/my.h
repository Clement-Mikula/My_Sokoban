/*
** EPITECH PROJECT, 2020
** 0
** File description:
** 0
*/

#ifndef MY_H
#define MY_H

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct object_s {
    char **arr;
    int *o_pos;
    int *x_pos;
    int x;
    int y;
    WINDOW *screen;
} object_t;

char *create_buff(char *filepath);
void get_p_pos(object_t *pos, char search);
void get_o_pos(object_t *pos);
int check_collision(object_t *pos, int x, int y);
void move_player(object_t *pos, int x, int y);
void display_map(object_t *pos);
int game_end(object_t *pos);
void find_boxe(object_t *pos);
int check_walls_up_right(object_t *pos, int i);
int check_walls_up_left(object_t *pos, int i);
int check_walls_down_right(object_t *pos, int i);
int check_walls_down_left(object_t *pos, int i);
int check_all_walls(object_t *pos);
int check_walls(object_t *pos);
int game_loose(object_t *pos);
void move_p(object_t *pos, int key);
void reload_map(object_t *pos, int key, char *buffer);
void game_loop(object_t *pos, char *buffer);
void sokoban(char *argv[]);
int error_handling(object_t *pos);
void help(int argc, char **argv);
int verify_terminal_size(object_t *pos);

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char *str, char pars);

#endif /* MY_H */