/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_visiualarray
*/

#include <stdlib.h>

void my_addstr(char **a, char *b);
char *my_newstr(char *str);
char *my_strjoin(char **array, char *join);
int my_arraylen(char **str);
int my_putstr(char *str);

char *my_disparray(char **array)
{
    char *ret = my_newstr("[ ");
    char *str = my_strjoin(array, ", ");

    my_addstr(&ret, str);
    my_addstr(&ret, " ]");
    free(str);
    return ret;
}

void my_putarray(char **array)
{
    int len = my_arraylen(array);

    for (int n = 0; n < len; n ++) {
        my_putstr(array[n]);
        my_putstr("\n");
    }
}
