/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** task03
*/

char *my_revstr(char *str)
{
    int len = 0;
    int i = 0;
    int j = 0;
    char stock = 0;
    int len2 = 0;

    for (len = 0; str[len] != '\0'; len++)
        len2 += 1;
    for (i = len; i > len2 / 2; i--) {
        stock = str[j];
        str[j] = str[len - 1];
        str[len - 1] = stock;
        j += 1;
        len -= 1;
    }
    str[len2] = '\0';
    return (str);
}
