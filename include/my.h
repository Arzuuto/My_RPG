/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY__H__
#define MY__H__

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

void my_putchar(char c);
void my_putstr(char const *str);
void my_put_nbr(int nb);
void my_printf(char *str, ...);
void my_put_strocta(char *str);
void my_put_hexa(int nb);
void my_puthexa_upper(int nb);
void my_put_address(long int nb);
void my_insigned_nbr(unsigned nb);
void my_put_octa(int nb);
void my_put_binary(int nb);
int my_compute_power_it(int nb, int p);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_atoi(char *str);
int main(int argc, char **argv, char **env);
char **str_to_tab(char *str, char *filter);

#endif/*MY__H__*/
