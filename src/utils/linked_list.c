/*
** EPITECH PROJECT, 2018
** Handle linked_list
** File description:
** Handle linked_list
*/

#include "my_rpg.h"

void delete_list(list_t *list)
{
    node_t *tmp = NULL;

    while (*list != NULL) {
        tmp = *list;
        *list = (*list)->next;
        free_character_obj(&tmp->ch);
        free(tmp);
    }
    *list = NULL;
}

void push(list_t *list, character_t new_ch)
{
    node_t *tmp = *list;
    node_t *new_node = malloc(sizeof(node_t));

    new_node->ch = new_ch;
    new_node->next = NULL;
    if (is_empty(*list)) {
        *list = new_node;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
}

void push_index(list_t *list, character_t new_ch, int n)
{
    node_t *current = *list;
    node_t *temp_node = NULL;
    node_t *new_node = malloc(sizeof(node_t));

    new_node->ch = new_ch;
    if (is_empty(*list)) {
        *list = new_node;
        return;
    }
    if (n == 0) {
        temp_node = current;
        new_node->next = current;
        *list = new_node;
        return;
    }
    for (int i = 0; i < n - 1 && current->next != NULL; i++)
        current = current->next;
    temp_node = current->next;
    current->next = new_node;
    new_node->next = temp_node;
}

void pop_index(list_t *list, int n)
{
    int i = 0;
    node_t *current = *list;
    node_t *temp_node = NULL;

    if (is_empty(*list)) {
        *list = NULL;
        return;
    }
    if (n == 0) {
        *list = (*list)->next;
        return;
    }
    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL)
            return;
        current = current->next;
    }
    temp_node = current->next;
    current->next = temp_node->next;
    free(temp_node);
}

int is_empty(list_t list)
{
    return ((list == NULL) ? 1 : 0);
}
