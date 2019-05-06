/*
** EPITECH PROJECT, 2019
** is_chr_in_str
** File description:
** is_chr_in_str
*/

int is_chr_in_str(char c, char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0' && str[i] != c; i++);
    if (str[i] == c)
        return (1);
    else
        return (0);
}