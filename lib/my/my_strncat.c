/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** Day07 - my_strncat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;
    int len_dest = 0;

    for (len_dest = 0; dest[len_dest] != '\0'; len_dest++);
    for (i = len_dest; i < len_dest + nb; i++) {
        dest[i] = src[j];
        j += 1;
    }
    return (dest);
}
