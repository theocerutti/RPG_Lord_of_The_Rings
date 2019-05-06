/*
** EPITECH PROJECT, 2019
** my_str_cat using va_args
** File description:
** my_strcat_va_args
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int my_strlen(char const *str);
char *my_strcat(char const *dest, char const *src);

char *big_strcat(int nb_args, ...)
{
    char *ret = "";
    char *str = NULL;

    va_list args;
    va_start(args, nb_args);
    for (int i = 0; i < nb_args; i++) {
        str = va_arg(args, char *);
        ret = my_strcat(ret, str);
    }
    va_end(args);
    return (ret);
}