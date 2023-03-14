/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_addchar
*/

#include <stdlib.h>

char *my_addstr(char *str1, char *str2);

char *my_char_to_string(char c)
{
    char *str = malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = '\0';
    return str;
}

char *my_addchar(char *str, char c)
{
    char *new_str = my_char_to_string(c);
    char *res = my_addstr(str, new_str);
    free(new_str);
    return res;
}
