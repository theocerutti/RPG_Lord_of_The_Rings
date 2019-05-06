/*
** EPITECH PROJECT, 2018
** Handle linked_list
** File description:
** Handle linked_list
*/

#include "my_rpg.h"

int get_size_list(list_t *list)
{
    int size = 0;
    node_t *tmp = *list;

    while (tmp != NULL) {
        size += 1;
        tmp = tmp->next;
    }
    return (size);
}