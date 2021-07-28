/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-1-myrpg-kaan.bouldoires
** File description:
** load_from_file
*/

#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"

int load_file_in_mem(char const *filepath, game_t *game)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);

    if (stat(filepath, &sb) == -1)
        return 84;
    game->map->str = malloc(sizeof(char) * (sb.st_size + 1));
    if (sb.st_size == 0)
        return 84;
    if (fd == -1)
        exit(84);
    if (read(fd, game->map->str, sb.st_size) == -1)
        exit(84);
    game->map->str[sb.st_size] = '\0';
    return 0;
}

void str_to_arr(game_t *game)
{
    int j = 0;
    int i = 0;
    int k = 0;

    game->map->arr = malloc(sizeof(char *) * game->map->rows);
    for (i = 0; i < game->map->rows; i++)
        game->map->arr[i] = malloc(sizeof(char) * game->map->cols[i]);
    for (i = 0, j = 0; j < game->map->rows; j++) {
        for (k = 0; k < game->map->cols[j]; k++) {
            game->map->arr[j][k] = game->map->str[i];
            i++;
        }
    }
}

void size_rows(game_t *game)
{
    int i = 0;

    game->map->rows = 0;
    while (game->map->str[i] != '\0') {
        if (game->map->str[i] == '\n')
            game->map->rows++;
        i++;
    }
}

void size_cols(game_t *game)
{
    int a = 0;
    int b = 0;

    game->map->cols = malloc(sizeof(int) * game->map->rows);
    for (int i = 0; i != game->map->rows; i++){
        for (b = 0; game->map->str[a] != '\n'
                 && game->map->str[a] != '\0'; a++, b++);
        game->map->cols[i] = b + 1;
        a++;
    }
}
