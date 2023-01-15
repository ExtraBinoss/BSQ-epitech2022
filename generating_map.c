/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** generating_map.c
*/

#include "./include/bsqq.h"

char *generating_map(int argc, char **argv, struct cords *cord)
{
    int x = my_getnbr_zero(argv[1]);
    int j = 0;
    char *pattern = argv[2];
    int square_total = x * x + x;
    int compteur = 0;
    char *generate = malloc(sizeof(char ) * square_total);
    for (int i = 0; i < square_total ; i++) {
        generate[i] = pattern[j];
        j++;
        compteur++;
        if (j == my_strlen(argv[2]))
            j = 0;
        if (compteur == x ) {
            i++;
            generate[i] = '\n';
            compteur = 0;
        }
    }
    cord->first_world = generate;
}

int bsq1(int argc, char **argv)
{
    struct cords cord;
    int x = my_getnbr_zero(argv[1]);
    cord.world = malloc(sizeof(int) * (x *x + x));
    generating_map(argc, argv, &cord);
    cord.nb_rows = x;
    cord.nb_cols = x;
    cord.max_i = 0;
    bsq_square(&cord);
    write(1, cord.first_world, x * x + x);
    return 0;
}
