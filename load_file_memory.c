/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** load_file_memory.c
** nb rows = first line, nb col = strlen puis memalloc2darray le carré entier
*/

#include "./include/bsqq.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **a = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i != nb_rows; i++) {
        a[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    for (int j = 0; j < nb_rows; j++) {
        for (int k = 0; k < nb_cols; k++) {
            a[j][k] = '\0';
        }
    }
    a[nb_rows] = NULL;
    return a;
}

char *load_file_in_mem(char const *filepath, int argc, char **argv)
{
    struct stat buf;
    unsigned long number;
    char *buffer;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;

    stat(filepath, &buf);
    number = buf.st_size;
    buffer = malloc(sizeof(char) * (number + 1));
    if (!buffer)
        return NULL;
    read(fd, buffer, number);
    buffer[number] = '\0';
    close(fd);
    return buffer;
}
