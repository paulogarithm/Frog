/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_addstr
*/

#include <stdlib.h>

int my_strlen(char *str);
void my_strcpy(char *dest, char *src);
void *my_puterr(char *str);

void my_addstr(char **dest, char *add)
{
    int len_a = my_strlen(*dest);
    int len_b = my_strlen(add);
    int len_both = len_a + len_b;
    char *tmp = malloc(sizeof(char) * (len_both + 1));

    if (tmp == NULL)
        return (void) my_puterr("Malloc Failure.\n");
    my_strcpy(tmp, *dest);
    for (int i = 0; i < len_b; i ++)
        tmp[len_a + i] = add[i];
    tmp[len_both] = '\0';
    free(*dest);
    *dest = tmp;
}

void my_addchar(char **str, char add)
{
    int len = my_strlen(*str);
    char *tmp = malloc(sizeof(char) * (len + 2));

    if (tmp == NULL)
        return (void) my_puterr("Malloc Failure.\n");
    my_strcpy(tmp, *str);
    tmp[len] = add;
    tmp[len + 1] = '\0';
    free(*str);
    *str = tmp;
}
