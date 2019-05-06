/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c);
int my_strlen(char const *str);

int my_putnbr_base(long nb, char const *base)
{
    long nb_chiffre = 0;
    long multi = 1;
    long len_b = my_strlen(base);

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (long nb_temp = nb; nb_temp > 0; nb_temp /= len_b, multi *= len_b) {
        nb_chiffre += 1;
    }
    multi /= len_b;
    for (long i = 0; i != nb_chiffre; i++, multi /= len_b)
        my_putchar(base[nb / multi % len_b]);
    return (0);
}
