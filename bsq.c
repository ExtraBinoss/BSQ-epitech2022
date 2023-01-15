/*
** EPITECH PROJECT, 2022
** B-CPE-110-MPL-1-1-BSQ-alan.trebugeais
** File description:
** bsq.c
*/

#include "./include/bsqq.h"

char **store_map(char *map_mem, int nb_rows, int nb_cols)
{
    char **map = mem_alloc_2d_array(nb_rows, nb_cols);
    for (int i = 0; i < nb_rows ; i++) {
        for (int j = 0; j < nb_cols ; j++) {
            map[i][j] = map_mem[i * (nb_cols + 1) + j];
        }
    }
    return map;
}

int bsq(int argc, char **argv)
{
    struct cords cord;
    struct stat st;
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return 84;
    stat(argv[1], &st);
    unsigned long file_size = st.st_size;
    cord.world = malloc(sizeof(int) * file_size);
    cord.first_world = load_file_in_mem(argv[1], argc, argv);
    cord.nb_rows = fs_get_number_from_first_line(argv[1]);
    int jump = my_strlen_line(cord.first_world);
    cord.first_world += jump;
    cord.nb_cols = my_strlen_line(cord.first_world) - 1;
    cord.max_i = 0;
    bsq_square(&cord);
    write(1, cord.first_world, file_size - jump);
    return 0;
}
