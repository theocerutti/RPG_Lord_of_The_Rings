/*
** EPITECH PROJECT, 2019
** LIB
** File description:
** my_stris_alpanum
*/

int my_str_isalphanum(char const *str)
{
    char s;

    for (int i = 0; str[i] != '\0'; i++) {
        s = str[i];
        if ((s < '0' || s > '9') && ((s < 'A' || s > 'Z') &&
        (s < 'a' || s > 'z')) && s != '_') {
            return (0);
        }
    }
    return (1);
}
