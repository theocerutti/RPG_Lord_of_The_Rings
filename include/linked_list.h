/*
** EPITECH PROJECT, 2019
** linked_list header
** File description:
** header
*/

void delete_list(list_t *list);
void push(list_t *list, character_t new_ch);
void push_index(list_t *list, character_t new_ch, int n);
void pop_index(list_t *list, int n);
void print_list(list_t list);
int is_empty(list_t list);
int get_size_list(list_t *list);