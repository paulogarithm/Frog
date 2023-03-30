/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_nb_str
*/

#include <stdlib.h>

int my_abs(int a);
char *my_newstr(char *text);
void my_addchar(char **str, char add);
void my_revstr(char *str);

char *my_nb_str(int nb)
{
    char *ret = my_newstr("");
    int tmp_nb;
    int s = nb < 0;

    nb = my_abs(nb);
    for (int i = 0; nb >= 10; i ++) {
        tmp_nb = (nb % 10);
        nb = (nb - tmp_nb) / 10;
        my_addchar(&ret, tmp_nb + '0');
    }
    my_addchar(&ret, nb + '0');
    if (s)
        my_addchar(&ret, '-');
    my_revstr(ret);
    return ret;
}
