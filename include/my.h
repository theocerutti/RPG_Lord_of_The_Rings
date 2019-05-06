/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header my.h
*/

#define READ_SIZE (50)

int is_chr_in_str(char c, char *str);
char *big_strcat(int nb_args, ...);
char *get_next_line(int);
void read_file(char *buffer, int fd);
int my_atoi(char *str);
char *my_itoa(int nb);
int my_str_isalphanum(char const *str);
char **my_strcpy_tab(char **dest, char **src);
int get_nb_cell(char const *str);
char *add_word_tab(char const *str);
void *my_memset(void *dest, char value, size_t allocated_size);
void my_fillmem(void *data, size_t allocated_size, char value);
void *my_calloc(size_t size, size_t nb_elem, char value);
void *my_realloc(void *data, size_t size);
int is_nstris_in(char *s2, char *s1, int n);
int is_stris_in(char *s1, char *s2);
char *my_strncpy_after(char *dest, char const *src, int n);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int get_signe(char const *str);
int get_begin_nb(char const *str);
int get_end_nb(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char **my_str_to_word_array(char const *str);
void swap_values(int *array, int size);
void get_hexa(int s);
int is_num_alpha(char s);
void word_add(char const *str, char **tab, int num_word, int modify);
void lenght_word(char const *str, char **tab, int num_word);
int count_word(char const *str);
void my_put_float(float nb, int index);
