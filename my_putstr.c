/*
** EPITECH PROJECT, 2022
** B-PSU-100-MPL-1-1-bsmyls-alan.trebugeais
** File description:
** my_putstr.c
*/

#include "./include/bsqq.h"

int my_putstr(char const *str)
{
    for (int i = 0 ; str[i] != 0 ; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
