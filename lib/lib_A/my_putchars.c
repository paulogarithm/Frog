/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_putstr
*/

#include <unistd.h>

int my_strlen(char *str);

int my_putstr(char *str)
{
    int count = my_strlen(str);

    write(1, str, count);
    return count;
}

void *my_puterr(char *str)
{
    int count = my_strlen(str);

    write(2, str, count);
    return NULL;
}

int my_putchar(char c)
{
    return write(1, &c, 1);
}
