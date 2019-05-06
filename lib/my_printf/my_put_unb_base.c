/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

int my_putnbr_base(int nb, char const *base);

void my_put_unb_base(unsigned int whole, char *base)
{
    if ((int) whole < 0) {
        my_putnbr_base((long) whole, base);
    } else if ((int) whole >= 0)
        my_putnbr_base(whole, base);
}
