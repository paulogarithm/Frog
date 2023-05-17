/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** my_arraycat
*/

#include <stddef.h>

void my_arrayadd(char ***array, const char *str);

void my_arraycat(char ***a, const char **b)
{
    for (int n = 0; b[n] != NULL; n++)
        my_arrayadd(a, b[n]);
}
