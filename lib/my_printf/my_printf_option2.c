/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
void my_putchar(char c);
int my_putnbr_base(int nb, char const *base);
void my_putn_ch(int nb, char ch);
int count_digits_base(int nb, char *base);

void option_with_point5(char c, va_list args, char ch, int nb_pf)
{
    int nb = 0;
    int count_nb_calc = 0;

    switch (c) {
        case 'i':
        case 'd':
            nb = va_arg(args, int);
            count_nb_calc = count_digits_base(nb, "0123456789");
            my_putn_ch(nb_pf - count_nb_calc, ch);
            my_putnbr_base(nb, "0123456789");
            break;
        default:
            my_putchar(c);
            break;
    }
}
