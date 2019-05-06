/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** LIB
*/

#include "lib.h"

/*
** Bosses functions
*/

void draw_bosses(data_t *data);
void shift_bosses(data_t *data, int x_off, int y_off);

void place_merchant(data_t *data, character_t boss);
void get_drop_item(data_t *data, character_t enemy);
void get_the_ring(data_t *data, character_t boss);
boss_t get_bosses_data(void);

/*
** Merchant functions
*/

#define MAX_MERCHANT 24

merchant_t get_merch(data_t *data);
character_t get_trader(data_t *data);
game_object_t get_use(void);

void draw_merchant(data_t *data);

void set_pos_inventory(sfVector2f pos[2], int index);
void init_each_case_m(data_t *data, sfVector2f pos[2], int i, sfTexture *itms);
void set_stat_txt_merch(data_t *data);
void init_merchant(data_t *data);

int can_buy(data_t *data, int index);
void buy_item(data_t *data, int index);

int is_item_merch(data_t *data);
void merchant_event(data_t *data, sfEvent *event);
void merchant_handling(data_t *data);
void open_merchant(data_t *data);

void sell_handling(data_t *data, int index);

int can_merch(data_t *data);

void change_story1(data_t *data);
void change_story2(data_t *data);

game_object_t get_overview_item(void);

/*
** Spells functions
*/

int one_spell_on(data_t *data);

void set_spells(data_t *data);
void init_spells_overview(data_t *data);
void send_spell_anim(data_t *data);

void init_overview_0(data_t *data);
void init_overview_1(data_t *data);
void init_overview_2(data_t *data);
void init_overview_3(data_t *data);

void draw_spells_overviews(data_t *data);
void draw_overview_0(data_t *data);
void draw_overview_1(data_t *data);
void draw_overview_2(data_t *data);
void draw_overview_3(data_t *data);

void draw_spells(data_t *data);

void event_spells(data_t *data, sfEvent *event);

void set_spell0(data_t *data);
void set_spell1(data_t *data);
void set_spell2(data_t *data);
void set_spell3(data_t *data);

void exec_spell0(data_t *data);
void exec_spell1(data_t *data);
void exec_spell2(data_t *data);
void exec_spell3(data_t *data);

int can_throw_spell(data_t *data, int spell);
int can_throw_spell_anim(int *overview_activate_anim);
void set_icon(data_t *data);

void spell0_hit(data_t *data, node_t *enem);
void spell1_hit(data_t *data, node_t *enem);
void spell2_hit(data_t *data, node_t *enem);
void spell3_hit(data_t *data, node_t *enem);

/*
** Inventory functions
*/

#define MAX_BAG 32
#define MAX_ITEM 27

void set_first_items(data_t *data);

void set_pos_inventory(sfVector2f pos[2], int index);
void set_stat_txt(data_t *data);

item_t *get_items_ref(void);
void update_hero_stat(data_t *data);
void description_item(data_t *data, int index);
void use_item(data_t *data, int index);
void un_equip_item(data_t *data, int index);
void delete_inventory_item(data_t *data, int index);
void inventory_event(data_t *data);

void inventory_handling(data_t *);
void open_inventory(data_t *data);
void init_inventory(data_t *data);

/*
** Cleanup functions
*/

void cleanup(data_t *data);
void free_sprite_texture(sfSprite *s, sfTexture *t);
void free_sfx_object(sfx_t *sfx);
void free_all_sfx(game_sfx_t *game_sfx);
void free_all_scenes(scene_t *scene);
void free_stat(stat_t *stat_obj);
void free_item(item_t *item);
void free_spell(spell_t *spell);
void free_bar(bar_t *bar);
void free_inventory(inventory_t *inv);
void free_txt_obj(txt_t *txt);
void free_clock(myclock_t *clock);
void free_button(button_t *button);
void free_game_object(game_object_t *obj);
void free_character_obj(character_t *ch);
void free_sprite_texture(sfSprite *s, sfTexture *t);
void free_sfx_object(sfx_t *sfx);

/*
** Draw functions
*/

void draw_fps(data_t *d);
void draw_particle_system(data_t *d, int scene_id);
void init_full_particle_system_smoke(data_t *d, particle_system_t *smoke_sys);
particle_t create_game_obj_smoke(data_t *d);
void draw_full_scenes(data_t *d, int scene_id);
void draw(data_t *d);
void draw_loading(sfRenderWindow *w);
void draw_cursor(data_t *d);
void draw_txt_scenes(data_t *d, int scene_id);
void draw_objs_scenes(data_t *d, int scene_id);
void draw_button_scenes(data_t *d, int scene_id);
void draw_character_obj(character_t *ch, sfRenderWindow *w);
void draw_list_character(list_t *list, sfRenderWindow *w);

/*
** Callback functions
*/

void button_resume(data_t *data);
void button_fps_15(data_t *data);
void button_fps_30(data_t *data);
void button_fps_60(data_t *data);
void button_fps_unlimited(data_t *data);
void button_show_fps(data_t *data);
void button_fps_menu(data_t *data);
void button_cursor_slider_music(data_t *data);
void button_cursor_slider_sound(data_t *data);
void button_audio_setting(data_t *data);
void button_control_setting(data_t *data);
void button_setting(data_t *data);
void button_right_arrow_c(data_t *d);
void button_right_arrow_m(data_t *d);
void button_right_arrow_i(data_t *d);
void button_left_arrow_c(data_t *d);
void button_left_arrow_m(data_t *d);
void button_left_arrow_i(data_t *d);
void button_exit(data_t *data);
void button_start_game(data_t *data);
void button_continue_game(data_t *data);
void button_print_help_main_menu(data_t *data);
void button_credits(data_t *data);
void button_return_main_menu(data_t *data);
void button_choose_bad_sauron(data_t *data);
void button_choose_good_sauron(data_t *data);
void button_return_game(data_t *data);
void callback_control_b_up(data_t *data);
void callback_control_b_down(data_t *data);
void callback_control_b_left(data_t *data);
void callback_control_b_right(data_t *data);
void callback_control_b_attack(data_t *data);
void callback_control_b_inventory(data_t *data);

/*
** Animation functions
*/

void game_intro(sfRenderWindow *w);
void game_intro2(sfRenderWindow *, intro_t, txt_t, txt_t);
void anim_obj_simple(game_object_t *obj, float second);
void anim_obj(game_object_t *obj, float second);
char *get_str_arrows(void);
intro_t init_txt_intro_2(intro_t ni, char *str);

/*
** Initialisation functions
*/

void init_sound4(game_sfx_t *sfx);
void init_block_map(data_t *d);
void init_all_bosses(data_t *data);
void init_historical(data_t *data);
void init_txt_hud5(data_t *data);
void init_txt_hud4(data_t *data);
void init_txt_hud3(data_t *data);
int get_level_enemy_according_to_scene(int scene_id);
void set_stat_according_to_level(stat_t *stat, int level);
char **get_raw_stat_enemy_id(int id_monster);
stat_t get_stat_enemy(int id_monster, int scene_id);
void init_die_menu(data_t *data);
char **get_collide(char *name);
void init_collide(data_t *data);
void change_state_checkbox(button_t *button);
void uncheck_boxes(data_t *data, int n1, int n2, int n3);
void init_fps_setting_menu(data_t *d);
void init_audio_setting_menu(data_t *d);
void init_setting_menu(data_t *d);
void init_all_sfx(game_sfx_t *sfx);
void init_basic_enemy_for_scene(data_t *d, int scene);
void init_continue_menu(data_t *data);
void init_all_credits(data_t *data);
void init_all_data(data_t *data);
void init_game(data_t *d);
void init_button_help_c_menu(data_t *data);
void init_button_help_m_menu(data_t *data);
void init_button_help_i_menu(data_t *data);
void init_obj_help_c_menu(data_t *data);
void init_obj_help_m_menu(data_t *data);
void init_obj_help_i_menu(data_t *data);
void init_hero_data(data_t *data);
void init_hud(data_t *data);
void init_main_menu(data_t *data);
void init_miscellaneous(data_t *data);
void init_new_game_menu(data_t *data);
void init_pause_menu(data_t *data);
void init_all_scenes_data(data_t *data);
void init_scenes2(data_t *data);
void init_scenes1(data_t *data);
void init_all_scenes(data_t *data);
void set_data_scene(data_t *data, int scene_id, info_scene_t info);
void init_control(data_t *data);
void init_all_control_menu(data_t *data);
void button_back(data_t *d);
void init_end(data_t *data);
void button_respawn(data_t *data);

/*
** Usefull init
*/

void init_sfx(sfx_t *sfx_obj, char const *path);
void init_bar_character(character_t *ch);
void init_clock(myclock_t *clock);
void init_txt_simple(txt_t *t, char const *path_font, char const *str);
void init_txt(button_t *obj, char const *path_font, char const *str);
void init_game_object(game_object_t *obj, char const *path);
void init_button(button_t *obj, char const *path, char const *str_txt,
char const *str_font);

/*
** Particle System
*/

particle_t create_game_obj_butterfly(data_t *d);
void init_full_particle_system_butterfly(data_t *d,
particle_system_t *butterfly_sys);
void update_rotation_particle(particle_t *particle, float delta_time);
void update_pos_particle(particle_t *particle, float delta_time);
particle_t create_game_obj_fire(data_t *d);
void init_full_particle_system_fire(data_t *d, particle_system_t *fire_sys);
void set_particle_to_system(data_t *d, particle_system_t *particle_sys,
particle_t (*get_particle_obj)(data_t *));
void init_particle_obj(particle_t *obj, char *path);
void default_update_particle(data_t *d, particle_system_t *sys);
void init_full_particle_system_snow(data_t *d, particle_system_t *snow_sys);
void init_full_particle_system_rain(data_t *d, particle_system_t *rain_sys);
particle_t create_game_obj_rain(data_t *d);
particle_t create_game_obj_snow(data_t *d);
void init_particle_system(particle_system_t *sys, int nb_particle,
float respawn_cycle, int direction);

/*
** Collision functions
*/

int is_near(game_object_t *obj1, game_object_t *obj2, int area_effect);
int is_collide_simple(game_object_t *obj1, game_object_t *obj2);
int is_point_collide(game_object_t *obj, int x, int y);
int is_collide_left(game_object_t *obj1, game_object_t *obj2);
int is_collide_right(game_object_t *obj1, game_object_t *obj2);
int is_collide_top(game_object_t *obj1, game_object_t *obj2);
int is_collide_bottom(game_object_t *obj1, game_object_t *obj2);
int collide_triangle(sfVector2f *p, sfVector2i p_ref);

/*
** Button pressed Menu functions
*/

int is_hovered(button_t *b, sfVector2i pm);
void hover_button(button_t *button, sfVector2i pm, int continue_game);
void button_pressed_menu(data_t *d, sfEvent *event);

/*
** Chase enemy event
*/

void turn_enemies_to_hero(data_t *data);
void chase_enemies_hero_current_scene(data_t *d, int area_effect);
void enemies_chase_hero(character_t *hero, list_t *list_enemies);

/************************************************************
**
** \brief Chaser object chase victim object
** \param magnet_area: if -1 -> infinity area
**
************************************************************/

void chase_victim(game_object_t *victim, game_object_t *chaser,
int magnet_area);

/*
** Transition_map
*/

void draw_circle_change_map(data_t *d, float radius, sfCircleShape *circle,
int scene_id);
void draw_change_map(data_t *d);
void look_change_map(data_t *d, int x, int y);

/*
** Hero level_up attributes
*/

void add_xp_hero(data_t *d, float xp_amount);

float next_regen_hp_level(int level);
float next_regen_mana_level(int level);
float next_attack_level(int level);
float next_defense_level(int level);
float next_max_life_level(int level);
float next_max_mana_level(int level);
float next_max_xp_level(int level);
void upgrade_hero_attributes(spell_t *spell, stat_t *stat, float *xp_width,
game_object_t *xp_bar);

/*
** Life / Mana System
*/

void recalc_raw_damage(character_t *ch, float *raw_damage);
void cost_mana_hero(data_t *d, float cost, int type);
void cost_life_hero(data_t *d, float cost, int type);
void cost_life_little_bar(character_t *ch, float cost, int type);
float calc_pourcentage(float cost, float width, float max);

/*
** Utils functions
*/

int get_size_file(char *name);
int myrand(int min, int max);
float myrand_float(float min, float max);

/*
** Control event
*/

void control_event(data_t *data, sfKeyCode *code);

/*
** ----------------------------------------------------
*/

void poll_event(data_t *data, sfEvent *event);
void open_pause_menu(data_t *data);
void event_move_hero(data_t *data);
void shift_game(data_t *d, float x_off, float y_off);
void event_attack_hero(data_t *d);
void check_die_enemy(data_t *data);
void check_hero_attack_enemy(data_t *d);
void check_enemy_attack_hero(data_t *d);
void all_event_enemies(data_t *data);
void all_event_hero(data_t *d);
void cost_gold_hero(data_t *d, float gold_amount);
int loose_gold_from_scene(int scene_id, int total_gold_hero, int *pourcent);
void check_die_hero(data_t *d);
void lvl_up_hero(data_t *d, float *xp_width);
void get_info_enemy_hud(data_t *d, sfEvent *event);
void add_item_to_historical(scene_t *hud, item_t *item_ref, int index_item);
void set_item_rect_historical_hud(scene_t *hud, item_t *item_ref);