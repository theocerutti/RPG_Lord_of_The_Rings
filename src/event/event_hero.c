/*
** EPITECH PROJECT, 2019
** event_hero
** File description:
** event_hero
*/

#include "my_rpg.h"

void lvl_up_hero(data_t *d, float *xp_width)
{
    if (sfSound_getStatus(d->sfx.sfx[7].sound) != sfPlaying)
        sfSound_play(d->sfx.sfx[7].sound);
    upgrade_hero_attributes(d->hero.spell, &d->hero.stat, xp_width,
    &d->scenes[HUD].objs[1]);
    sfText_setString(d->scenes[HUD].txt[5].txt, big_strcat(2, "Level ",
    my_itoa(d->hero.stat.level)));
    sfText_setString(d->hero.bar.lvl.txt, big_strcat(2, "Lvl ",
    my_itoa(d->hero.stat.level)));
    cost_life_hero(d, d->hero.stat.max_life, HEAL);
    cost_mana_hero(d, d->hero.stat.max_mana, HEAL);
    if (d->hero.stat.xp > d->hero.stat.max_xp)
        lvl_up_hero(d, xp_width);
}

void add_xp_hero(data_t *d, float xp_amount)
{
    static float xp_width = 0;

    d->hero.stat.xp += xp_amount;
    xp_width += (xp_amount * d->scenes[HUD].objs[1].width) /
    d->hero.stat.max_xp;
    d->scenes[HUD].objs[1].rect.width = xp_width;
    if (d->hero.stat.xp >= d->hero.stat.max_xp) {
        lvl_up_hero(d, &xp_width);
    }
    sfSprite_setTextureRect(d->scenes[HUD].objs[1].s,
    d->scenes[HUD].objs[1].rect);
    sfText_setString(d->scenes[HUD].txt[2].txt, big_strcat(3,
    my_itoa(d->hero.stat.xp), " / ", my_itoa(d->hero.stat.max_xp)));
}

void all_event_hero(data_t *d)
{
    event_move_hero(d);
    if (d->trans >= 0) {
        if (d->hero.obj.rect.left + d->hero.obj.offset.x >= d->hero.obj.width)
            d->hero.is_attacking = FALSE;
        if (d->hero.is_attacking == TRUE)
            anim_obj_simple(&d->hero.obj, 0.05);
        else
            anim_obj_simple(&d->hero.obj, 0.1);
        check_die_hero(d);
        d->hero.clock.time = sfClock_getElapsedTime(d->hero.clock.clock);
        d->hero.clock.s = d->hero.clock.time.microseconds / 1000000.0;
        if (d->hero.clock.s > 1) {
            cost_life_hero(d, d->hero.stat.regen_life, HEAL);
            cost_mana_hero(d, d->hero.stat.regen_mana, HEAL);
            sfClock_restart(d->hero.clock.clock);
        }
    }
}