/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header struct.h
*/

enum current {MENU, NEW_GAME, CREDITS, PAUSE, HUD, CONTROL, SETTING,
FPS_SETTING, AUDIO_SETTING, DIE,
HELP_C, HELP_I, HELP_M, LVL_1_F, LVL_1_C, LVL_2_F, LVL_2_C, LVL_3_F, LVL_3_C,
INVENTORY, MERCHANT, END, NULL_SCENE};

enum id_enum {
    BACKGROUND_ID,
    HERO_ID,
    ENEMY_ID,
    BOSS_ID,
    ITEM_ID,
    HUD_ID,
    MISCELLANEOUS_ID,
    PNJ_ID
};

enum control_key {
    UP_KEY,
    DOWN_KEY,
    RIGHT_KEY,
    LEFT_KEY,
    ATTACK_KEY,
    INVENTORY_KEY,
};

enum direction_enum {
    LEFT,
    RIGHT,
    BOTTOM,
    TOP
};
enum direction_particle {
    TO_TOP,
    TO_BOTTOM
};

enum heal_damage_enum {
    HEAL,
    DAMAGE
};

enum bool_enum {
    FALSE,
    TRUE
};

enum sfx_enum {
    MUSIC,
    SOUND
};

typedef struct data_s data_t;

typedef struct sfx_s {
    enum sfx_enum type;
    int volume;
    sfSoundBuffer *buffer;
    sfSound *sound;
    sfMusic *music;
} sfx_t;

typedef struct game_sfx_s {
    sfx_t *sfx;
    int nb_sfx;
} game_sfx_t;

typedef struct txt_t {
    sfText *txt;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int size;
} txt_t;

typedef struct myclock_s {
    sfClock *clock;
    sfTime time;
    float s;
} myclock_t;

typedef struct game_object_s {
    float width;
    float height;
    sfVector2f scale;
    sfVector2i offset;
    sfVector2f v;
    sfVector2f pos;
    sfTexture *t;
    sfSprite *s;
    sfIntRect rect;
    myclock_t clock;
    int id;
} game_object_t;

typedef struct button_s {
    sfRectangleShape *obj;
    sfVector2f pos;
    sfVector2f size;
    sfTexture *t;
    txt_t txt;
    void (*pressed)(data_t *);
    sfVector2i offset;
    sfIntRect rect;
} button_t;

typedef struct help_s {
    game_object_t *obj;
    int index;
    button_t *button;
} help_t;

typedef struct stat_s {
    int type;
    char *name;
    char *describe;
    int level;
    float regen_life;
    float regen_mana;
    float attack;
    float defense;
    float life;
    float max_life;
    float mana;
    float max_mana;
    float xp;
    float max_xp;
    int value;
    int gold;
    int speed;
} stat_t;

typedef struct particle_t {
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f origin;
    sfVector2f size;
    sfColor color;
    float rotation;
    sfVector2f gravity;
    sfVector2f grav_limitx;
    sfVector2f grav_limity;
    sfVector2f respawn_areax;
    sfVector2f respawn_areay;
    sfVector2f shake;
    float speed_rotation;
    int loop_rotating;
    float limit;
} particle_t;

typedef struct particle_system_s {
    particle_t *particle;
    void (*update)(data_t *, struct particle_system_s *sys);
    int nb_particle;
    float respawn_cycle;
    int running;
    int direction;
    myclock_t clock;
} particle_system_t;

typedef struct item_s {
    game_object_t item;
    stat_t stat;
} item_t;

typedef struct inventory_s {
    item_t *items;
    int nb_items;
    int bag[32][3];
    game_object_t *stuff;
} inventory_t;

typedef struct spell_s {
    game_object_t spell;
    stat_t stat;
} spell_t;

typedef struct bar_s {
    game_object_t life_bar;
    txt_t lvl;
    txt_t life;
    float life_width;
    sfSprite *s_bg;
    sfTexture *t_bg;
} bar_t;

typedef struct character_s {
    inventory_t inventory;
    spell_t spell[4];
    stat_t stat;
    game_object_t obj;
    bar_t bar;
    int is_attacking;
    int is_clicked_hud;
    myclock_t clock;
} character_t;

typedef struct window_s {
    sfVector2i size;
    sfRenderWindow *w;
} window_t;

typedef struct node_s {
    character_t ch;
    struct node_s *next;
} node_t;
typedef node_t *list_t;

typedef struct info_scene_s {
    int nb_button;
    int nb_obj;
    int nb_txt;
    int nb_character;
    int have_particle_system;
    int have_collide_map;
} info_scene_t;

typedef struct scene_s {
    particle_system_t *particle_sys;
    txt_t *txt;
    game_object_t *objs;
    game_object_t on_map;
    int have_collide_map;
    button_t *buttons;
    list_t list_ch;
    char **col;
    int have_particle_system;
    int nb_txt;
    int nb_but;
    int nb_obj;
    int nb_ch;
} scene_t;

typedef struct control_s {
    sfKeyCode key[6];
    char c;
    int check;
    int button;
    sfKeyCode k;
} control_t;

typedef struct fps_s {
    int can_draw_fps;
    txt_t txt;
    myclock_t clock;
} fps_t;

typedef struct overview_s {
    game_object_t *spell_anim;
    int nb_spell_anim;
    sfRectangleShape **overview_r;
    sfCircleShape *overview_c;
    sfVector2f pos;
    sfVector2f size;
    float radius;
    void (*draw_it)(data_t *);
} overview_t;

typedef struct intro_s {
    int tour;
    int trans;
    sfSprite **intro;
    sfColor color;
    sfVector2f s;
    myclock_t cl;
    myclock_t next;
    myclock_t prev;
    txt_t *txt;
} intro_t;

typedef struct merchant_s {
    character_t t;
    game_object_t use;
    int market;
    enum current cur_m;
} merchant_t;

typedef struct boss_s {
    character_t boss_ch[3];
    int cur_boss[3];
    int boss;
} boss_t;

typedef struct data_s {
    game_object_t cursor;
    character_t hero;
    scene_t *scenes;
    window_t window;
    enum current cur;
    enum current pre_cur;
    item_t *item_ref;
    control_t ctrl;
    game_sfx_t sfx;
    fps_t fps;
    int next_map;
    overview_t overview[4];
    int overview_activate[4];
    int overview_activate_anim[4];
    myclock_t delta_time;
    myclock_t action_tick;
    txt_t change_map;
    merchant_t merch;
    boss_t boss;
    int trans;
    int *posinx;
    int *posiny;
    int can_continue_game;
} data_t;