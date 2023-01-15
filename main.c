/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** bsq.c
** open read write close malloc free stat
*/

#include "./include/bsqq.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    if (argc > 3)
        return 84;
    if (argc == 3) {
        bsq1(argc, argv);
    }
    if (argc == 2)
        bsq(argc, argv);
    return 0;
}
