/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_operations
*/

#include <stddef.h>
#include <stdbool.h>
#include "my/string.h"
#include "my/stdlib.h"

#include "frog/functions.h"
#include "frog/operations.h"

void operation_plus(frog_t *frog, char ***array, size_t n)
{
    switch (frog_get_type(frog, (*array)[n - 1])) {
        case G_STRING:
        (*array)[n - 1] = my_strcat((*array)[n - 1], (*array)[n + 1]);
        break;
        case G_NUMBER:
        (*array)[n - 1] =
        my_ftoa(my_atof((*array)[n - 1]) + my_atof((*array)[n + 1]));
        break;
        case G_BOOLEAN:
        (*array)[n - 1] =
        my_btoa((my_atob((*array)[n - 1]) + my_atob((*array)[n + 1])) != 0);
        break;
        default:
        (*array)[n - 1] = my_newstr("nil");
        break;
    }
}

void operation_minus(frog_t *frog, char ***array, size_t n)
{
    switch (frog_get_type(frog, (*array)[n - 1])) {
        case G_STRING:
        (*array)[n - 1] = remove_string((*array)[n - 1], (*array)[n + 1]);
        break;
        case G_NUMBER:
        (*array)[n - 1] =
        my_ftoa(my_atof((*array)[n - 1]) - my_atof((*array)[n + 1]));
        break;
        case G_BOOLEAN:
        (*array)[n - 1] =
        my_btoa((my_atob((*array)[n - 1]) - my_atob((*array)[n + 1])) != 0);
        break;
        default:
        (*array)[n - 1] = my_newstr("nil");
        break;
    }
}
