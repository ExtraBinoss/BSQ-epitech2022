/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** show_int_array.c
*/

#include "./include/bsqq.h"

void show_int_array(struct cords *cord)
{
    for (int i = 0; i < my_strlen(cord->first_world); i++) {
        if (cord->world[i] == 84) {
            my_putchar('\n');
        } else {
            my_put_nbr(cord->world[i]);
            my_putchar(' ');
        }
    }
}
