/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strcreate
*/

#include <stdlib.h>

void my_strcpy(char *a, const char *b);
int my_strlen(char *str);
void *my_puterr(char *str);

char *my_newstr(char *text)
{
    int len = my_strlen(text);
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        return my_puterr("Malloc Failure.\n");
    str[len] = '\0';
    my_strcpy(str, text);
    return str;
}
