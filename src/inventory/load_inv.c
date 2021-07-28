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
#include "game.h"
#include "my.h"

int load_file_in_mem_inv(char const *filepath, game_t *game)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);

    if (stat(filepath, &sb) == -1)
        return 84;
    game->inv->str = malloc(sizeof(char) * (sb.st_size + 1));
    if (sb.st_size == 0)
        return 84;
    if (fd == -1)
        exit(84);
    if (read(fd, game->inv->str, sb.st_size) == -1)
        exit(84);
    game->inv->str[sb.st_size] = '\0';
    return 0;
}

void str_to_arr_inv(game_t *game)
{
    int j = 0;
    int i = 0;
    int k = 0;

    game->inv->arr = malloc(sizeof(char *) * game->inv->rows);
    for (i = 0; i < game->inv->rows; i++)
        game->inv->arr[i] = malloc(sizeof(char) * game->inv->cols[i]);
    for (i = 0, j = 0; j < game->inv->rows; j++) {
        for (k = 0; k < game->inv->cols[j]; k++) {
            game->inv->arr[j][k] = game->inv->str[i];
            i++;
        }
    }
}

void size_rows_inv(game_t *game)
{
    int i = 0;

    game->inv->rows = 0;
    while (game->inv->str[i] != '\0') {
        if (game->inv->str[i] == '\n')
            game->inv->rows++;
        i++;
    }
}

void size_cols_inv(game_t *game)
{
    int a = 0;
    int b = 0;

    game->inv->cols = malloc(sizeof(int) * game->inv->rows);
    for (int i = 0; i != game->inv->rows; i++){
        for (b = 0; game->inv->str[a] != '\n'
                 && game->inv->str[a] != '\0'; a++, b++);
        game->inv->cols[i] = b + 1;
        a++;
    }
}
