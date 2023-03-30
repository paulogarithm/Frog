/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_cutstr
*/

#include <stdlib.h>

int my_strlen(char *str);
void *my_puterr(char *str);

char *my_cutstr(char *str, int beg, int end)
{
    char *new;

    if (beg > end)
        return NULL;
    new = malloc(sizeof(char) * (end - beg + 2));
    if (new == NULL)
        return my_puterr("Malloc Failure.\n");
    for (int n = beg; n < end && str[n] != '\0'; n ++)
        new[n - beg] = str[n];
    new[end - beg] = '\0';
    return new;
}
