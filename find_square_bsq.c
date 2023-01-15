/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** find_square_bsq.c
*/

#include "./include/bsqq.h"

int square_conditions(struct cords *cord, int i, struct positions *pos)
{
    if (i - cord->nb_cols - 2 >= 0
    && cord->world[i - cord->nb_cols - 2] != 84) {
        pos->left_diagonal = cord->world[i - cord->nb_cols - 2];
    }
    if (i - 1 >= 0 && cord->world[i - 1] != 84 ) {
        pos->left = cord->world[i - 1];
    }
    if (i - cord->nb_cols - 1 >= 0
    && cord->world[i - cord->nb_cols - 1] != 84) {
        pos->top = cord->world[i - cord->nb_cols - 1];
    }
}

int square_math_comparaison(struct cords *cord, int i, struct positions *pos)
{
    square_conditions(cord, i, pos);
    if (pos->left < pos->top) {
        pos->final = pos->left;
    } else {
        pos->final = pos->top;
    }
    if (pos->final > pos->left_diagonal) {
        pos->final = pos->left_diagonal;
    }
    if (pos->final == -1) {
        pos->final = 0;
    }
    biggest_square_comparaison(cord, i, pos);
}

int square_math(struct cords *cord, struct positions *pos)
{
    for (int i = 0; cord->first_world[i] != '\0'; i++) {
        if (cord->world[i] != 84 && cord->world[i] != 0) {
            square_math_comparaison(cord, i, pos);
        }
    }
}

int square_scanner(struct cords *cord, struct positions *pos)
{
    for (int i = 0; cord->first_world[i] != '\0'; i++) {
        if (cord->first_world[i] == 'o') {
            cord->world[i] = 0;
        }
        if (cord->first_world[i] == '.') {
            cord->world[i] = 1;
        }
        if (cord->first_world[i] == '\n') {
            cord->world[i] = 84;
        }
    }
    square_math(cord, pos);
}

int bsq_square(struct cords *cord)
{
    struct positions pos = {0};
    square_scanner(cord, &pos);
    int p = (cord->nb_cols - 1);
    for (int x = cord->max_i; x > cord->max_i - pos.biggest_size; x--) {
        cord->first_world[x] = 'x';
        for (int y = cord->max_i; y > cord->max_i - p  * pos.biggest_size;
        y -= cord->nb_cols + 1) {
            cord->first_world[y - (cord->max_i - x)] = 'x';
        }
    }
    return 0;
}
