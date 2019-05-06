/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb);

void my_putfloat(float nb, int index)
{
    int nb_commas = 0;
    int multipli = 1;

    if (index <= 0)
        my_put_nbr(nb);
    else {
        for (int i = 0; i != index; i++)
            multipli *= 10;
        nb_commas = nb * multipli;
        nb_commas %= multipli;
        my_put_nbr(nb);
        my_putchar('.');
        my_put_nbr(nb_commas);
    }
}
