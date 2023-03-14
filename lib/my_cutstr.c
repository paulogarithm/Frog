/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_cutstr
*/

#include <stdlib.h>

char *my_addchar(char *str, char c);

char *my_cutstr(char *str, int beggin, int end)
{
    int n = beggin;
    char *ret = "";

    while (str[n] && n < end) {
        ret = my_addchar(ret, str[n++]);
    }
    ret = my_addchar(ret, '\0');
    return ret;
}
