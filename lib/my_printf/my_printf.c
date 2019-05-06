/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
void my_put_unb_base(unsigned int whole, char *base);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putnbr_base(long nb, char const *base);
void my_putfloat(float nb, int index);
void my_putstr_oct(char *str);
int option_with_point(int i, char *str, va_list args);

void option4(char str_c, va_list args)
{
    switch (str_c) {
        case 's':
            my_putstr(va_arg(args, char *));
            break;
        default:
            my_putchar('%');
            my_putchar(str_c);
            break;
    }
}

void option3(char str_c, va_list args)
{
    switch (str_c) {
        case 'u':
            my_put_unb_base(va_arg(args, unsigned int), "0123456789");
            break;
        case 'c':
            my_putchar(va_arg(args, int));
            break;
        case 'p':
            my_putstr("0x");
            my_putnbr_base(va_arg(args, long), "0123456789abcdef");
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            option4(str_c, args);
            break;
    }
}

void option2(char str_c, va_list args)
{
    switch (str_c) {
        case 'i':
        case 'd':
            my_putnbr_base(va_arg(args, int), "0123456789");
            break;
        case 'S':
            my_putstr_oct(va_arg(args, char *));
            break;
        case 'b':
            my_put_unb_base(va_arg(args, unsigned int), "01");
            break;
        case 'f':
            my_putfloat(va_arg(args, double), 2);
            break;
        default:
            option3(str_c, args);
            break;
    }
}

void my_printf_option(char str_c, char *str, va_list args, int i)
{
    switch (str_c) {
        case 'o':
            if (str[i - 1] == '#')
                my_putchar('0');
            my_put_unb_base(va_arg(args, unsigned int), "01234567");
            break;
        case 'x':
            if (str[i - 1] == '#')
                my_putstr("0x");
            my_put_unb_base(va_arg(args, unsigned int), "0123456789abcdef");
            break;
        case 'X':
            if (str[i - 1] == '#')
                my_putstr("0X");
            my_put_unb_base(va_arg(args, unsigned int), "0123456789ABCDEF");
            break;
        default:
            option2(str_c, args);
            break;
    }
}

int my_printf(char *str, ...)
{
    int i = 0;

    va_list ap;
    va_start(ap, str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && ((str[i + 1] == '.') || (str[i + 1] >= '0'
        && str[i + 1] <= '9') || (str[i + 1] == ' '))) {
            i += 2;
            i = option_with_point(i, str, ap);
        } else if (str[i] == '%') {
            i += 1;
            if (str[i] == '#' || str[i] == '-' || str[i] == '+')
                i += 1;
            my_printf_option(str[i], str, ap, i);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
    return (0);
}
