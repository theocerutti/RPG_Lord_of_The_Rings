/*
** EPITECH PROJECT, 2018
** my_strstr
** File description:
** my_strstr
*/

char *my_strstr(char *str, char const *find)
{
    int j = 0;
    int k = 0;
    int len_find = 0;
    int len_str = 0;

    for (len_find = 0; find[len_find] != '\0'; len_find++);
    for (len_str = 0; str[len_str] != '\0'; len_str++) {
        if (find[j] == str[len_str] && j != len_find) {
            j += 1;
            k = len_str;
        } else if (j != 0 && find[j - 1] != str[len_str] && j != len_find) {
            j = 0;
            k = 0;
        }
    }
    if (find[0] == '\0')
        return (str);
    else if (j == len_find)
        return (str + k - j + 1);
    return (0);
}
