/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(long nb)
{
    int nb_chiffre = 0;
    long multi = 1;

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (long nb_temp = nb; nb_temp > 0; nb_temp /= 10, multi *= 10)
        nb_chiffre += 1;
    multi /= 10;
    for (int i = 0; i != nb_chiffre; i++, multi /= 10)
        my_putchar((nb / multi % 10) + '0');
    return (0);
}
