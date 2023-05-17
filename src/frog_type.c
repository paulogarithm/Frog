/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_type
*/

#include <iso646.h>
#include <stddef.h>
#include <malloc.h>
#include "my/stdlib.h"
#include "my/string.h"

#include "frog/frog.h"

char *frog_get_varvalue(frog_t *frog, const char *varname)
{
    for (size_t n = 0; frog->variables[n] != NULL; ++n)
        if (my_strcmp(frog->variables[n]->name, varname))
            return frog->variables[n]->value;
    return NULL;
}

bool frog_replacevar(frog_t *frog, char ***array)
{
    char *varval = NULL;

    for (size_t n = 0; (*array)[n] != NULL; ++n) {
        varval = frog_get_varvalue(frog, (*array)[n]);
        if (varval == NULL)
            continue;
        free((*array)[n]);
        (*array)[n] = my_newstr(varval);
    }
    return true;
}

unsigned short frog_get_type(frog_t *frog, const char *str)
{
    char *varvalue = NULL;
    unsigned short ret = 0;

    if (str == NULL or my_strcmp(str, "nil"))
        return G_NIL;
    if (my_isnum(str) or my_isdouble(str))
        return G_NUMBER;
    if (my_strlen(str) >= 3 and
    str[0] == '"' and str[my_strlen(str) - 1] == '"')
        return G_STRING;
    if (my_strcmp(str, "true") or my_strcmp(str, "false"))
        return G_BOOLEAN;
    if (str[0] == '{')
        return G_TABLE;
    varvalue = frog_get_varvalue(frog, str);
    if (varvalue == NULL)
        return G_NIL;
    ret = frog_get_type(frog, varvalue);
    return ret;
}
