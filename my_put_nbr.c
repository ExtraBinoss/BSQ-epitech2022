/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-bsmyls-alan.trebugeais
** File description:
** my_put_nbr.c
*/

#include "./include/bsqq.h"

void my_put_nbr(unsigned int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar('0' + nb % 10);
}
