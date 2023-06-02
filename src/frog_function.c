/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_function
*/

#include <stdbool.h>
#include <iso646.h>
#include <stddef.h>
#include <malloc.h>

#include "my/string.h"
#include "my/array.h"
#include "my/stdio.h"

#include "frog/functions.h"

static const tabfrog_builtins_t TAB_GROF[] = {
    {"exec", frog_builtins_exec},
    {"print", frog_builtins_print},
    {NULL, NULL}
};

static void clean_it(char **str)
{
    char *ret = NULL;
    long pos = my_strcfnd(*str, '(');

    if (pos < 0)
        return;
    ret = my_strcut(*str, pos + 1, my_strlen(*str) - 2);
    free(*str);
    *str = ret;
}

static char *get_value(frog_t *frog, size_t *n)
{
    char *ret = my_newstr(NULL);

    for (; frog->words[*n] != NULL; ++(*n)) {
        my_addstr(&ret, frog->words[*n]);
        my_addstr(&ret, " ");
        if (frog->words[*n][my_strlen(frog->words[*n]) - 1] == ')') {
            clean_it(&ret);
            return ret;
        }
    }
    free(ret);
    return NULL;
}

static bool basic_errorcase(frog_t *frog, size_t n)
{
    if (frog->words[n] == NULL)
        return true;
    if (my_strcfnd(frog->words[n], '(') < 0)
        return true;
    return false;
}

static char **check_form(frog_t *frog, size_t *n)
{
    char **array = NULL;
    char **ret = NULL;
    char *value = NULL;

    if (basic_errorcase(frog, *n))
        return NULL;
    array = my_strsplit(frog->words[*n], "(");
    if (array == NULL or array[0] == NULL or
    not my_startswith(frog->words[*n], array[0]))
        return NULL;
    value = get_value(frog, n);
    if (value == NULL)
        return NULL;
    ret = my_newarray(NULL);
    my_arrayadd(&ret, array[0]);
    my_arrayadd(&ret, value);
    free(value);
    my_arrayfree(array);
    return ret;
}

bool frog_isfunction(frog_t *frog, size_t *n)
{
    char **function_elements = check_form(frog, n);
    short pos = 0;

    if (function_elements == NULL)
        return false;
    pos = frog_tabpos_builtins(function_elements[0], TAB_GROF);
    if (pos < 0)
        return false;
    return TAB_GROF[pos].function(frog, function_elements);
}
