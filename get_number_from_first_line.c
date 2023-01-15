/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** get_number_from_first_line.c
*/

#include "./include/bsqq.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;
    for ( ; str[i] != '\n'; i++) {
            nb = nb + str[i] - '0';
            nb = nb * 10;
    }
    nb = nb / 10;
    return nb;
}

int my_getnbr_zero(char const *str)
{
    int nb = 0;
    int i = 0;
    for ( ; str[i] != '\0'; i++) {
            nb = nb + str[i] - '0';
            nb = nb * 10;
    }
    nb = nb / 10;
    return nb;
}

int fs_get_number_from_first_line(char const *filepath)
{
    char buffer[1024];
    int return_value = 0;
    int fd = open(filepath, O_RDONLY);
    read(fd, buffer, 1024);
    for (int i = 0; buffer[i] != '\n'; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z') {
            return 84;
        }
        if (buffer[i] < '0' || buffer[i] > '9') {
            return 84;
            }
        }
    return_value = my_getnbr(buffer);
    return (return_value);
}
