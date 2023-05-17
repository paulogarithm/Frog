/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_variable_creation
*/

#include <stdbool.h>
#include <malloc.h>
#include <iso646.h>
#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "frog/functions.h"

static bool frog_create_var_errcase(frog_t *frog, unsigned n)
{
    size_t len = my_arraylen((const char **)frog->words);

    if (len - n < 3)
        return true;
    if (not my_strcmp(frog->words[n + 2], "="))
        return true;
    return false;
}

static char *get_all_value(const char **array, size_t beggin)
{
    char *ret = my_newstr(NULL);
    const char *ARITHMETICS[] = {"+", "-", "*", "/", NULL};

    for (size_t n = beggin; array[n] != NULL; ++n) {
        if ((beggin + n) % 2 == 0) {
            ret = my_superstrcat(3, ret, (n == beggin) ? "" : " ", array[n]);
            continue;
        }
        if (my_arrayindex(ARITHMETICS, array[n]) < 0)
            break;
        ret = my_superstrcat(3, ret, " ", array[n]);
    }
    return ret;
}

static size_t count_words(const char *str)
{
    char **array = my_array_str(str);
    size_t count = my_arraylen((const char **)array);

    my_arrayfree(array);
    return count;
}

bool frog_create_var(frog_t *frog, size_t *n)
{
    var_t *var = NULL;
    size_t jump = 0;

    if (frog_create_var_errcase(frog, *n))
        return false;
    var = malloc(sizeof(var_t));
    if (var == NULL)
        return false;
    var->name = my_newstr(frog->words[*n + 1]);
    var->value = get_all_value((const char **)frog->words, *n + 3);
    jump = count_words(var->value) + 2;
    var->value = frog_arithmetics(frog, var->value);
    if (var->value == NULL)
        return false;
    var->type = frog_get_type(frog, var->value);
    if (not frog_append_var(frog, var))
        return false;
    *n += jump;
    return true;
}

bool frog_autovar(frog_t *frog, char *keyval_str)
{
    var_t *var = malloc(sizeof(var_t));
    char **keyval = NULL;

    if (var == NULL)
        return false;
    keyval = keyvalue_parser(keyval_str);
    if (keyval == NULL)
        return false;
    var->name = my_newstr(keyval[0]);
    var->value = my_newstr(keyval[1]);
    var->value = frog_arithmetics(frog, var->value);
    if (var->value == NULL)
        return false;
    frog_append_var(frog, var);
    return true;
}
