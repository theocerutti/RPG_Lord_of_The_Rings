/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** task02
*/

void my_putchar(char c);

void my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
