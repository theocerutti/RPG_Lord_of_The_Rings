/*
** EPITECH PROJECT, 2019
** init ref_items
** File description:
** rpg
*/

#include "my_rpg.h"

game_object_t get_info_items(char *line)
{
    game_object_t object;
    char **stat = my_str_to_word_array(line);

    object.offset.x = my_getnbr(stat[1]);
    object.offset.y = my_getnbr(stat[1]);
    object.rect.height = my_getnbr(stat[1]);
    object.rect.width = my_getnbr(stat[1]);
    object.rect.left = my_getnbr(stat[2]);
    object.rect.top = my_getnbr(stat[3]);
    object.id = ITEM_ID;
    return (object);
}

void prepare_name_desc(stat_t *stat)
{
    for (int i = 0; stat->name[i] != '\0'; i++) {
        if (stat->name[i] == '_')
            stat->name[i] = ' ';
        if (stat->name[i] == '|')
            stat->name[i] = '\n';
    }
    for (int i = 0; stat->describe[i] != '\0'; i++) {
        if (stat->describe[i] == '_')
            stat->describe[i] = ' ';
        if (stat->describe[i] == '|')
            stat->describe[i] = '\n';
    }
}

stat_t get_info_stat(char *line)
{
    stat_t stat;
    char **arr = my_str_to_word_array(line);

    stat.type = my_getnbr(arr[11]);
    stat.name = my_strcpy(arr[9]);
    stat.describe = my_strcpy(arr[10]);
    stat.attack = my_getnbr(arr[4]);
    stat.defense = my_getnbr(arr[5]);
    stat.mana = my_getnbr(arr[6]);
    stat.life = my_getnbr(arr[7]);
    stat.value = my_getnbr(arr[8]);
    stat.gold = my_getnbr(arr[12]);
    prepare_name_desc(&stat);
    return (stat);
}

item_t *get_items_ref(void)
{
    item_t *ref = malloc(sizeof(item_t) * 27);
    FILE *fd = fopen("assets/data/items", "r");
    char *buff = NULL;
    size_t size = 0;
    int nread = 0;

    nread = getline(&buff, &size, fd);
    for (int i = 0; i < 27; i++) {
        nread = getline(&buff, &size, fd);
        buff[nread - 1] = '\0';
        ref[i].item = get_info_items(buff);
        ref[i].stat = get_info_stat(buff);
    }
    return (ref);
}