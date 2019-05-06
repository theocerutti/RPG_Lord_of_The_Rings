/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** Day06 - task02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int len_dest = 0;

    for (len_dest = 0; dest[len_dest] != '\0'; len_dest++);
    if (n > len_dest)
        return (0);
    for (i = 0; i != n; i++)
        dest[i] = src[i];
    dest[len_dest] = '\0';
    return (dest);
}
