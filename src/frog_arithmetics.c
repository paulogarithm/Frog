/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_arithmetic
*/


#include <iso646.h>
#include <stddef.h>
#include <malloc.h>
#include "my/string.h"
#include "my/stdlib.h"
#include "my/array.h"
#include "my/stdio.h"

#include "frog/functions.h"
#include "frog/operations.h"

static const tabfrog_operations_t LIST[] = {
    {"+", operation_plus},
    {"-", operation_minus},
    {NULL, NULL}
};

static short get_operation_pos(const char *ope)
{
    for (unsigned short n = 0; LIST[n].operation != NULL; ++n)
        if (my_strcmp(ope, LIST[n].operation))
            return n;
    return -1;
}

static void process_arithmetics(frog_t *frog, char ***array, size_t *n)
{
    short pos = get_operation_pos((*array)[*n]);

    if (pos < 0)
        (*array)[*n - 1] = NULL;
    else
        LIST[pos].function(frog, array, *n);
    my_arraypop(array, *n + 1);
    my_arraypop(array, *n);
    *n -= 1;
}

static void loop_arithmetics(frog_t *frog, char ***array)
{
    const char *ARITHMETICS[] = {"+", "-", "*", "/", NULL};

    for (size_t n = 0; (*array)[n] != NULL; ++n)
        if (my_arrayindex(ARITHMETICS, (*array)[n]) >= 0)
            process_arithmetics(frog, array, &n);
}

static void beautiful_num(frog_t *frog, char **ret)
{
    char *tmp = NULL;
    enum mode_e type = frog_get_type(frog, *ret);

    if (type == G_NIL) {
        free(*ret);
        *ret = my_newstr("nil");
    } if (type != G_NUMBER)
        return;
    if (my_atoi(*ret) == my_atof(*ret)) {
        tmp = my_itoa(my_atoi(*ret));
        free(*ret);
        *ret = tmp;
        return;
    }
    for (size_t n = my_strlen(*ret) - 1; n > 0; --n)
        if ((*ret)[n] == '0')
            (*ret)[n] = '\0';
}

char *frog_arithmetics(frog_t *frog, char *str)
{
    char **array = my_array_str(str);
    char *ret = NULL;

    if (not frog_replacevar(frog, &array))
        return NULL;
    loop_arithmetics(frog, &array);
    if (array[0] == NULL)
        return NULL;
    ret = my_newstr(array[0]);
    beautiful_num(frog, &ret);
    my_arrayfree(array);
    return ret;
}
