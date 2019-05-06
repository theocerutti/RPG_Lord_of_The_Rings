/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

void my_putchar(char c);
void my_putnbr_base(int i, char *base);
void my_putstr(char *str);

void add_zero(char c)
{
    if (c <= 7)
        my_putstr("00");
    else if (c > 7)
        my_putchar('0');
}

void my_putstr_oct(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            add_zero(str[i]);
            my_putnbr_base(str[i], "01234567");
        } else
            my_putchar(str[i]);
    }
}
