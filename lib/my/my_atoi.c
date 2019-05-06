/*
** EPITECH PROJECT, 2019
** template
** File description:
** my_atoi
*/

int my_strlen(char *str);

int my_atoi(char *str)
{
    int nb_digits = my_strlen(str);
    int result = 0;
    int multi = 1;
    int index = 0;

    if (str[0] == '-') {
        index += 1;
        nb_digits -= 1;
    }
    for (int i = 0; i != nb_digits - 1; multi *= 10, i++);
    for (; str[index] != '\0'; index++) {
        result += (str[index] - '0') * multi;
        multi /= 10;
    }
    if (str[0] == '-')
        result *= -1;
    return (result);
}
