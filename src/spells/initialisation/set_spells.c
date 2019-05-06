/*
** EPITECH PROJECT, 2019
** set spells in rpg
** File description:
** rpg
*/

#include "my_rpg.h"

void fill_spells_stat(data_t *data, char *buff, int index)
{
    char **spell_info = my_str_to_word_array(buff);
    sfVector2f pos[4] = {{665, 1000}, {732, 1000}, {798, 1000}, {865, 1000}};
    sfTexture *text[4] = {
        sfTexture_createFromFile("assets/images/spells/spell0.jpg", NULL),
        sfTexture_createFromFile("assets/images/spells/spell1.jpg", NULL),
        sfTexture_createFromFile("assets/images/spells/spell2.jpg", NULL),
        sfTexture_createFromFile("assets/images/spells/spell3.jpg", NULL)
    };

    data->hero.spell[index].stat.attack = my_atoi(spell_info[1]);
    data->hero.spell[index].stat.mana = my_atoi(spell_info[2]);
    data->hero.spell[index].spell.pos = pos[index];
    data->hero.spell[index].spell.t = sfTexture_copy(text[index]);
    data->hero.spell[index].spell.s = sfSprite_create();
    data->hero.spell[index].spell.width = 59;
    data->hero.spell[index].spell.height = 59;
    sfSprite_setTexture(data->hero.spell[index].spell.s, text[index], sfTrue);
    sfSprite_setPosition(data->hero.spell[index].spell.s, pos[index]);
}

void set_spells(data_t *data)
{
    int nread = 0;
    char *buff = NULL;
    FILE *fd = fopen("assets/data/spells", "r");
    size_t size = 0;

    nread = getline(&buff, &size, fd);
    for (int i = 0; i < 4; i++) {
        nread = getline(&buff, &size, fd);
        buff[nread] = '\0';
        fill_spells_stat(data, buff, i);
    }
    fclose(fd);
}

void init_spells_overview(data_t *data)
{
    for (int i = 0; i < 4; i++)
        data->overview_activate[i] = 0;
    init_overview_0(data);
    init_overview_1(data);
    init_overview_2(data);
    init_overview_3(data);
}