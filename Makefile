##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC 	= 	main.c \
			src/initialisation/get_stat_basic_enemy.c \
			src/initialisation/init_audio_setting_menu.c \
			src/initialisation/init_die_menu.c \
			src/initialisation/init_setting.c \
			src/initialisation/init_data.c \
			src/initialisation/init_scenes.c \
			src/initialisation/usefull_init1.c \
			src/initialisation/usefull_init2.c \
			src/initialisation/usefull_init3.c \
			src/initialisation/init_scene_data.c \
			src/initialisation/init_main_menu.c \
			src/initialisation/init_new_game_menu.c \
			src/initialisation/init_credits.c \
			src/initialisation/init_hero.c \
			src/initialisation/init_basic_enemy.c \
			src/initialisation/init_pause_menu.c \
			src/initialisation/init_game.c \
			src/initialisation/init_miscellaneous.c \
			src/initialisation/init_hud.c \
			src/initialisation/init_hud2.c \
			src/initialisation/init_historical_hud.c \
			src/initialisation/init_inventory.c \
			src/initialisation/init_all_sfx.c \
			src/initialisation/init_all_sfx2.c \
			src/initialisation/init_fps_setting_menu.c \
			src/initialisation/init_collision_map.c \
			src/initialisation/init_items_ref.c \
			src/initialisation/init_help_menu.c \
			src/initialisation/init_help_menu2.c \
			src/initialisation/init_control_menu.c \
			src/initialisation/init_block_map.c \
			src/draw/draw.c \
			src/draw/draw_miscellaneous.c \
			src/draw/draw_obj.c \
			src/draw/draw_character.c \
			src/callback/callback_fps_menu.c \
			src/callback/callback_fps_menu2.c \
			src/callback/callback_main_menu.c \
			src/callback/callback_main_menu2.c \
			src/callback/callback_setting.c \
			src/callback/callback_new_game_menu.c \
			src/callback/callback_help.c \
			src/callback/callback_help2.c \
			src/callback/callback_control.c \
			src/callback/callback_control2.c \
			src/event/historical_event.c \
			src/event/event_hero_die.c \
			src/event/event_hero_gold.c \
			src/event/button_pressed_menu.c \
			src/event/event_hero_move.c \
			src/event/transition_between_map.c \
			src/event/all_event.c \
			src/event/chase_enemy_event.c \
			src/event/shift_game.c \
			src/event/event_enemies.c \
			src/event/event_hero.c \
			src/event/event_attack_hero.c \
			src/event/cost_mana_life.c \
			src/event/display_intro.c \
			src/event/display_intro2.c \
			src/event/hero_level_up_attributes.c \
			src/event/hero_level_up_attributes2.c \
			src/event/control_event.c \
			src/event/get_info_stat_enemy.c \
			src/animation/anim_obj.c \
			src/cleanup/cleanup.c \
			src/cleanup/cleanup_obj1.c \
			src/cleanup/cleanup_obj2.c \
			src/cleanup/cleanup_obj3.c \
			src/utils/collision_utils2.c \
			src/utils/collision_utils1.c \
			src/utils/utils.c \
			src/utils/linked_list.c \
			src/utils/linked_list2.c \
			src/inventory/event_open.c \
			src/inventory/print_inventory.c \
			src/inventory/event/handle_event.c \
			src/inventory/equip/equip_item.c \
			src/inventory/describe/describe.c \
			src/inventory/describe/stat_hero.c \
			src/inventory/delete/delete_item.c \
			src/spells/draw/draw_spells.c \
			src/spells/event/send_spell.c \
			src/spells/event/can_throw_spell.c \
			src/particle/snow_particle.c \
			src/particle/smoke_particle.c \
			src/particle/fire_particle.c \
			src/particle/rain_particle.c \
			src/particle/default_update_particle.c \
			src/spells/initialisation/set_spells.c \
			src/spells/initialisation/init_overviews.c \
			src/spells/draw/draw_overviews.c \
			src/spells/overview/setting_spell.c \
			src/spells/overview/setting_spell2.c \
			src/spells/overview/exec_spell.c \
			src/spells/overview/icons.c \
			src/spells/spells_attack/check_hit.c \
			src/trader/init_trader.c \
			src/trader/draw/draw.c \
			src/trader/init_stat.c \
			src/trader/event/event_open.c \
			src/trader/event/merchant_event.c \
			src/trader/event/buy.c \
			src/trader/event/selling.c \
			src/trader/init_merch.c \
			src/inventory/equip/use.c \
			src/initialisation/get_over_item.c \
			src/boss/init_boss.c \
			src/boss/shift/shift.c \
			src/boss/get_ring.c \
			src/boss/place_merchant.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_rpg

RM 		=	rm -rf

RM_TRASH =	*.o *~ *.gcno *.gcda libmy.a *.gch

CFLAGS	= 	-lm -Wextra -g -W -Wall -I ./include

CLFLAGS = 	-L lib -lall

CSFML   = 	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib && gcc $(SRC) -o $(NAME) $(CFLAGS) $(CSFML) $(CLFLAGS)

clean:
	make clean -C lib
	$(RM) $(OBJ) $(RM_TRASH)

fclean: clean
	make fclean -C lib
	$(RM) $(NAME)

re: fclean all