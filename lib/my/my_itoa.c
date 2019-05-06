/*
** EPITECH PROJECT, 2019
** template
** File description:
** my_itoa
*/

#include <stdio.h>
#include <stdlib.h>

char *my_itoa(int nb)
{
    char *new_str = malloc(sizeof(char) * 15);
    int nb_digit = 0;
    float multi = 0.1;
    int i = 0;
    int plus = 0;

    if (nb < 0) {
        new_str[0] = '-';
        plus = 1;
        nb *= -1;
    }
    for (long nb_s = nb; nb_s > 0; nb_s /= 10, multi *= 10)
        nb_digit += 1;
    nb_digit = (nb == 0) ? 1 : nb_digit;
    multi = (nb == 0) ? 10 : multi;
    for (i = plus; i != nb_digit + plus; i++, multi /= 10)
        new_str[i] = (nb / (int)multi % 10) + '0';
    new_str[i] = '\0';
    return (new_str);
}