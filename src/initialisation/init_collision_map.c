/*
** EPITECH PROJECT, 2019
** init_scenes
** File description:
** init_scenes
*/

#include "my_rpg.h"

char **get_collide(char *name)
{
    int ret = 0;
    char *file = NULL;
    int fd = open(name, O_RDONLY);
    int size_file = get_size_file(name);

    if (fd == -1)
        return (NULL);
    file = malloc(sizeof(char) * (size_file + 1));
    ret = read(fd, file, size_file + 1);
    if (ret == -1)
        return (NULL);
    file[size_file] = '\0';
    return (my_str_to_word_array(file));
}

void init_collide(data_t *data)
{
    data->scenes[LVL_1_F].col = get_collide("assets/collide/dark");
    data->scenes[LVL_1_C].col = get_collide("assets/collide/city_winter");
    data->scenes[LVL_2_F].col = get_collide("assets/collide/forest_win_aut");
    data->scenes[LVL_2_C].col = get_collide("assets/collide/city_autumn");
    data->scenes[LVL_3_F].col = get_collide("assets/collide/forest_sp_aut");
    data->scenes[LVL_3_C].col = get_collide("assets/collide/city_spring");
}