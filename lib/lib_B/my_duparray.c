/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** my_duparray
*/

#include <stdlib.h>

char *my_newstr(char *str);
int my_arraylen(char **array);

char **my_duparray(char **array)
{
    int len = my_arraylen(array);
    char **dup = malloc(sizeof(char *) * (len + 1));

    for (int n = 0; array[n] != NULL; n ++)
        dup[n] = my_newstr(array[n]);
    dup[len] = NULL;
    return dup;
}
