/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_compstr
*/

int my_strlen(char *str);

int my_compstr(char *a, char *b)
{
    if (my_strlen(a) != my_strlen(b))
        return 0;
    for (int n = 0; n < my_strlen(a); n ++)
        if (a[n] != b[n])
            return 0;
    return 1;
}
