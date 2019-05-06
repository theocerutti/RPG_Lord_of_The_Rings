/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Day 06 - task15
*/

#include <unistd.h>

void my_putchar(char c);

int my_strlen(char const *str);

int my_putnbr_base(int nb, char const *base)
{
    int nb_chiffre = 0;
    int multi = 1;
    int len_b = my_strlen(base);

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    for (int nb_temp = nb; nb_temp > 0; nb_temp /= len_b, multi *= len_b)
        nb_chiffre += 1;
    multi /= len_b;
    if (nb <= 10)
        my_putchar('0');
    for (int i = 0; i != nb_chiffre; i++, multi /= len_b) {
        my_putchar(base[nb / multi % len_b]);
    }
    return (0);
}
