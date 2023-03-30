/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_isit
*/

int my_strlen(char *str);

int my_isalphanum(char *str)
{
    for (int n = 0; str[n] != '\0'; n ++)
        if ((str[n] < 'A' || str[n] > 'Z')
        && (str[n] < '0' || str[n] > '9')
        && (str[n] < 'a' || str[n] > 'z'))
            return 0;
    return 1;
}

int my_isnum(char *str)
{
    int i = 0;

    if (str[i] == '-' && my_strlen(str) >= 2)
        i += 1;
    for (int n = i; str[n] != '\0'; n ++)
        if (str[n] < '0' || str[n] > '9')
            return 0;
    return 1;
}
