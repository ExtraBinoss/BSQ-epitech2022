/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** square_compare.c
*/

#include "./include/bsqq.h"

int biggest_square_comparaison(struct cords *cord, int i, struct positions *pos)
{
    pos->final += 1;
    cord->world[i] = pos->final;
    if (pos->biggest_size < pos->final) {
        pos->biggest_size = pos->final;
        cord->max_i = i;
    }
}
