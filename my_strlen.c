/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** my_strlen.c
*/

#include "./include/bsqq.h"

void my_putchar(char c);

int my_strlen(char const *str)
{
    int countstr = 0;
    while ( *str != 0 ) {
        str++;
        countstr += 1;
    }
    return countstr;
}

int my_strlen_line(char const *str)
{
    int countstr = 0;
    while ( *str != '\n' ) {
        str++;
        countstr += 1;
    }
    return countstr + 1;
}

int my_strlen_line_star(int *nb)
{
    int countstr = 0;
    while ( *nb != '\n' ) {
        nb++;
        countstr += 1;
    }
    return countstr + 1;
}
