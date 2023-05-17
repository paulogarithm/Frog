/*
** Paul Parisot PROJECT, 2023
** sh_final
** File description:
** frog_variable
*/

#include <malloc.h>
#include "my/string.h"

#include "frog/functions.h"

var_t *get_variable_by_name(frog_t *frog, const char *name)
{
    for (size_t n = 0; frog->variables[n] != NULL; ++n)
        if (my_strcmp(frog->variables[n]->name, name))
            return frog->variables[n];
    return NULL;
}

bool frog_newval_var(frog_t *frog, var_t *var)
{
    var_t *old_var = get_variable_by_name(frog, var->name);

    if (old_var == NULL)
        return false;
    old_var->value = my_newstr(var->value);
    old_var->type = var->type;
    free(var->name);
    free(var->value);
    free(var);
    return true;
}

bool frog_append_var(frog_t *frog, var_t *var)
{
    var_t **new = NULL;
    size_t len = 0;
    char *tmp = frog_get_varvalue(frog, var->name);

    if (tmp != NULL) {
        free(tmp);
        return frog_newval_var(frog, var);
    }
    free(tmp);
    for (; frog->variables[len] != NULL; ++len);
    new = malloc(sizeof(var_t) * (len + 2));
    if (new == NULL)
        return false;
    for (size_t n = 0; n < len; ++n)
        new[n] = frog->variables[n];
    new[len] = var;
    new[len + 1] = NULL;
    free(frog->variables);
    frog->variables = new;
    return true;
}
