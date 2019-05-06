/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Header my_printf
*/

#include <stdlib.h>
#include <stdarg.h>

void option_with_point4(char c, va_list args, char ch, int nb_pf);
void option_with_point3(char c, va_list args, char ch, int nb_pf);
void option_with_point2(char c, va_list args, char ch, int nb_pf);
void handle_option(char *ch, int *i, char *str);
int option_with_point(int i, char *str, va_list args);
void option_with_point5(char c, va_list args, char ch, int nb_pf);
void option4(char str_c, va_list args);
void option3(char str_c, va_list args);
void option2(char str_c, va_list args);
void my_printf_option(char str_c, char *str, va_list args, int i);
int my_printf(char *str, ...);
void my_put_unb_base(unsigned int whole, char *base);
void my_putfloat(float nb, int index);
void my_putnstr(char const *str, int n);
void add_zero(char c);
void my_putstr_oct(char *str);
