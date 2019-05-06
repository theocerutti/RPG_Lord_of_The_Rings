/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
