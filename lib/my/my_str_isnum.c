/*
** EPITECH PROJECT, 2018
** my_str_isnum
** File description:
** Day06 - task0??
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int count_same = 0;
    int len = 0;

    for (i = 0; str[i] != '\0'; i++) {
        len += 1;
        if (str[i] >= '0' && str[i] <= '9')
            count_same += 1;
    }
    if (count_same == len || len == 0)
        return (1);
    else
        return (0);
}
