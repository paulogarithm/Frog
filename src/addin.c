/*
** Paul PARISOT, 2023
** frog_code
** File description:
** addin
*/

#include <stdlib.h>

#include "../include/frog.h"

variable_t **addin_var(variable_t **list, variable_t *button)
{
    variable_t **new_list;
    int size = 0;
    int n = 0;

    while (list[size] != NULL)
        ++size;
    new_list = malloc(sizeof(variable_t) * (size + 2));
    while (list[n] != NULL) {
        new_list[n] = list[n];
        n += 1;
    }
    new_list[n] = button;
    new_list[n + 1] = NULL;
    return new_list;
}
