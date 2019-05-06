/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** my_calloc
*/

#include <stdlib.h>

void *my_memset(void *dest, char value, size_t allocated_size)
{
    char *ptr = (char *)dest;

    while (allocated_size > 0) {
        *ptr = value;
        ptr++;
        allocated_size -= 1;
    }
    ptr--;
    *ptr = '\0';
    return (dest);
}

void my_fillmem(void *data, size_t allocated_size, char value)
{
    my_memset(data, value, allocated_size);
}

void *my_calloc(size_t size, size_t nb_elem, char value)
{
    void *data = malloc(size);
    if (data != NULL)
        my_fillmem(data, nb_elem, value);
    return (data);
}
