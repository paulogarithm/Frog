/*
** Paul PARISOT, 2022
** my_lib
** File description:
** my_addstr
*/

#include <stdlib.h>

int my_countstr(char *str);

char *my_addstr(char *first, char *second)
{
    int both_size = my_countstr(first) + my_countstr(second);
    char *str = malloc(sizeof(char) * (both_size + 1));
    int f = 0;
    int s = 0;

    while (first[f]) {
        str[f] = first[f];
        f += 1;
    }
    while (second[s]) {
        str[f + s] = second[s];
        s += 1;
    }
    str[f + s] = '\0';
    return str;
}
