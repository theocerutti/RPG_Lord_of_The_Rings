/*
** EPITECH PROJECT, 2018
** my_putfloat
** File description:
** my_function, my_putfloat
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb);

void my_put_float(float nb, int index)
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
