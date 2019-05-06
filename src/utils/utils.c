/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#include "my_rpg.h"

int myrand(int min, int max)
{
    int stock = 0;
    int random_nb = 0;

    if (min > max) {
        stock = min;
        max = min;
        min = stock;
    }
    if (max - min + 1 != 0)
        random_nb = (rand() % (max - min + 1)) + min;
    return (random_nb);
}

float myrand_float(float min, float max)
{
    return (((rand() / (float) RAND_MAX) * (max - min)) + min);
}

int get_size_file(char *name)
{
    FILE *fd = fopen(name, "r");
    int size = 0;
    size_t n = 0;
    char *line = NULL;
    int ret = 0;

    if (fd == NULL)
        return (0);
    ret = getline(&line, &n, fd);
    while (ret != -1) {
        size += my_strlen(line) + 1;
        ret = getline(&line, &n, fd);
    }
    return (size);
}