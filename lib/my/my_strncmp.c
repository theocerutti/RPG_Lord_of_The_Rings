/*
** EPITECH PROJECT, 2018
** my_strncmp
** File description:
** task06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; i != n && s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}