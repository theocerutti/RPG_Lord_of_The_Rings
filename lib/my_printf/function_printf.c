/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

void my_putchar(char c);
int my_strlen(char const *base);

void my_putn_ch(int nb, char ch)
{
    for (int i = 0; i < nb; i++) {
        my_putchar(ch);
    }
}

int count_digits_base(int nb, char *base)
{
    int nb_chiffre = 0;
    int multi = 1;
    int len_b = my_strlen(base);

    for (long nb_temp = nb; nb_temp > 0; nb_temp /= len_b, multi *= len_b)
        nb_chiffre += 1;
    return (nb_chiffre);
}
