/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** my_realloc
*/

#include <stdlib.h>
#include <stdio.h>

char *my_strcpy(char *dest, char const *src);

void *my_realloc(void *data, size_t size)
{
    void *new_data = malloc(size);

    if (new_data == NULL)
        return (NULL);
    my_strcpy(new_data, data);
    return (new_data);
}
