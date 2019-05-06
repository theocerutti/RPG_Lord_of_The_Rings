/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** task05
*/

int get_signe(char const *str)
{
    int signe = 0;
    int nb_minus = 0;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            nb_minus += 1;
        i += 1;
    }
    if (nb_minus % 2 == 0 && nb_minus != 0)
        signe = 1;
    else if (nb_minus % 2 != 0 && nb_minus != 0)
        signe = -1;
    else
        signe = 1;
    return (signe);
}

int get_begin_nb(char const *str)
{
    int i = 0;
    char s;

    while (str[i] != '\0') {
        s = str[i];
        if (s != '+' && s != '-' && (s < '0' || s > '9'))
            return (-1);
        else if (s >= '0' && s <= '9')
            return (i);
        i += 1;
    }
    return (0);
}

int get_end_nb(char const *str, int begin_nb)
{
    int i = begin_nb;

    while (str[i] >= '0' && str[i] <= '9')
        i += 1;
    return (i - 1);
}

int my_getnbr(char const *str)
{
    int signe = get_signe(str);
    int begin_nb = get_begin_nb(str);
    int end_nb = get_end_nb(str, begin_nb);
    int diff = end_nb - begin_nb;
    int multi = 1;
    int result = 0;

    for (; diff != -1; diff--)
        multi *= 10;
    for (int z = begin_nb; z != end_nb + 1; z++) {
        result += (str[z] - 48) * multi;
        multi /= 10;
    }
    result /= 10 * signe;
    return (result);
}