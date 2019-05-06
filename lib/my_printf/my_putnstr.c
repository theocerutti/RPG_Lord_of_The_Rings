/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

void my_putchar(char c);

void my_putnstr(char const *str, int n)
{
    for (int i = 0; i != n && str[i] != '\0'; i++)
        my_putchar(str[i]);
}
