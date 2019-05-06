/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_strlen(char const *str);
void my_putnstr(char const *str, int n);
int my_getnbr(char const *str);
int my_putnbr_base(int nb, char const *base);
void my_put_unb_base(unsigned int whole, char *base);
void my_putn_ch(int nb, char ch);
int count_digits_base(int nb, char *base);
void option_with_point5(char c, va_list args, char ch, int nb_pf);

void option_with_point4(char c, va_list args, char ch, int nb_pf)
{
    unsigned int whole = 0;
    int count_nb_calc = 0;

    switch (c) {
        case 'X':
            whole = va_arg(args, unsigned int);
            count_nb_calc = count_digits_base(whole, "0123456789ABCDEF");
            my_putn_ch(nb_pf - count_nb_calc, ch);
            my_put_unb_base(whole, "0123456789ABCDEF");
            break;
        default:
            option_with_point5(c, args, ch, nb_pf);
            break;
    }
}

void option_with_point3(char c, va_list args, char ch, int nb_pf)
{
    unsigned int whole;
    int count_nb_calc = 0;

    switch (c) {
        case 'u':
            whole = va_arg(args, unsigned int);
            count_nb_calc = count_digits_base(whole, "0123456789");
            my_putn_ch(nb_pf - count_nb_calc, ch);
            my_put_unb_base(whole, "0123456789");
            break;
        case 's':
            my_putnstr(va_arg(args, char *), nb_pf);
            break;
        default:
            option_with_point4(c, args, ch, nb_pf);
            break;
    }
}

void option_with_point2(char c, va_list args, char ch, int nb_pf)
{
    unsigned int whole;
    int count_nb_calc = 0;

    switch (c) {
        case 'o':
            whole = va_arg(args, unsigned int);
            count_nb_calc = count_digits_base(whole, "01234567");
            my_putn_ch(nb_pf - count_nb_calc, ch);
            my_put_unb_base(whole, "01234567");
            break;
        case 'x':
            whole = va_arg(args, unsigned int);
            count_nb_calc = count_digits_base(whole, "0123456789abcdef");
            my_putn_ch(nb_pf - count_nb_calc, ch);
            my_put_unb_base(whole, "0123456789abcdef");
            break;
        default:
            option_with_point3(c, args, ch, nb_pf);
            break;
    }
}

void handle_option(char *ch, int *i, char *str)
{
    if (str[*i - 1] == '.' || str[*i - 1] == '0') {
        *ch = '0';
    } else if (str[*i - 1] == ' ') {
        *ch = ' ';
    } else {
        *i -= 1;
        *ch = ' ';
    }
    if (str[*i - 1] == ' ' && str[*i] >= 'a' && str[*i] <= 'z')
        my_putchar(' ');
}

int option_with_point(int i, char *str, va_list args)
{
    char *str_nb;
    char ch;
    int nb = 0;
    int nb_digits = 0;

    handle_option(&ch, &i, str);
    str_nb = malloc(sizeof(char) * (my_strlen(str) - i));
    for (int j = i, index = 0; str[j] != '\0'; j++, index++)
        str_nb[index] = str[j];
    nb = my_getnbr(str_nb);
    nb_digits = count_digits_base(nb, "0123456789");
    option_with_point2(str[i + nb_digits], args, ch, nb);
    free(str_nb);
    return (i + nb_digits);
}
