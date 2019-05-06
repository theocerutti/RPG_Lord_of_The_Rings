/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>

int get_nb_cell(char const *str)
{
    char c;
    char c_1;
    int i = 0;
    int nb_cell = 0;

    while ((str[i] <= ' ' || str[i] >= 127) && str[i] != '\0')
        i += 1;
    for (; str[i] != '\0'; i++) {
        c = str[i];
        c_1 = str[i + 1];
        if ((c_1 > ' ' && c_1 < 127) && (c <= ' ' || c >= 127)) {
            nb_cell += 1;
        }
    }
    return (nb_cell + 1);
}

char *add_word_tab(char const *str, int *index_start)
{
    int index_final = 0;
    char *word = NULL;
    int j = 0;

    while ((str[*index_start] <= ' ' || str[*index_start] >= 127) && \
    str[*index_start] != '\0')
        *index_start += 1;
    index_final = *index_start;
    while ((str[index_final] > ' ' && str[index_final] < 127) && \
    str[index_final] != '\0')
        index_final += 1;
    word = malloc(sizeof(char) * (index_final - *index_start) + 1);
    for (int i = *index_start; i < index_final; i++, j++)
        word[j] = str[i];
    word[j] = '\0';
    *index_start = index_final;
    return (word);
}

char **my_str_to_word_array(char const *str)
{
    int nb_cell = get_nb_cell(str) + 1;
    char **tab = malloc(sizeof(char *) * (nb_cell + 1));
    int elem = 0;
    int index_start = 0;

    for (elem = 0; elem < nb_cell - 1; elem++) {
        tab[elem] = add_word_tab(str, &index_start);
    }
    tab[elem] = NULL;
    return (tab);
}
