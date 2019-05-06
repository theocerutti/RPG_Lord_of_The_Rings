/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** task05
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}
