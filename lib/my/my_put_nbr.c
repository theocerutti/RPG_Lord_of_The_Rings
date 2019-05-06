/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Day 03 - task07
*/

#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int nb_chiffre = 0;
    long multi = 1;

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (int nb_temp = nb; nb_temp > 0; nb_temp /= 10, multi *= 10)
        nb_chiffre += 1;
    multi /= 10;
    for (int i = 0; i != nb_chiffre; i++, multi /= 10)
        my_putchar((nb / multi % 10) + '0');
    return (0);
}
