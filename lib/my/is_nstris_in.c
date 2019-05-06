/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** return (1) if str, is in str2 else 0
*/

int my_strlen(char *str);

int is_nstris_in(char *s2, char *s1, int n)
{
    int len_s1 = my_strlen(s1);
    int len_s2 = my_strlen(s2);
    int count_s2 = 0;

    if (len_s1 > len_s2)
        return (0);
    for (int i = 0, j = 0; s2[i] != '\0' && i < n; i++, j++) {
        if (s1[j] == s2[i])
            count_s2 += 1;
        else {
            count_s2 = 0;
            j = -1;
        }
        if (count_s2 == len_s1)
            return (1);
    }
    return (0);
}
