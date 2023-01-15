/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** bsqq.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#pragma once

typedef struct cords {
    int nb_cols;
    int nb_rows;
    int biggest_pos_x;
    int biggest_pos_y;
    int *world;
    char *first_world;
    int max_i;
    int map_size;
} cords;

typedef struct positions {
    int left_diagonal;
    int left;
    int top;
    int final;
    int biggest_size;
} positions;

void my_put_nbr(unsigned int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strlen_line(char const *str);
int my_getnbr(char const *str);
void show_int_array(struct cords *cords);

int fs_get_number_from_first_line(char const *filepath);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char *load_file_in_mem(char const *filepath, int argc, char **argv);

int bsq(int argc, char **argv);
char **store_map(char *map_mem, int nb_rows, int nb_cols);
int bsq_square(struct cords *cord);
int find_square_bsq(struct cords *cord, struct positions *pos);
int square_scanner(struct cords *cord, struct positions *pos);
int square_math(struct cords *cord, struct positions *pos);
int square_math_comparaison(struct cords *cord, int i, struct positions *pos);
int square_conditions(struct cords *cord, int i, struct positions *pos);
int biggest_square_comparaison(struct cords *cord, int i, struct positions *);

int my_getnbr_zero(char const *str);
char *generating_map(int argc, char **argv, struct cords *cord);
int bsq1(int argc, char **argv);
