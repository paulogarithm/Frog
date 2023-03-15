/*
** Paul PARISOT, 2023
** Frog
** File description:
** variables_set
*/

#include <stdlib.h>

#include "../../include/frog.h"

int my_conv_str_nb(char const *str, int nb);
int my_compstr(char *a, char *b);
int my_countarray(char **array);

char *get_type(char *val);
variable_t **addin_var(variable_t **list, variable_t *button);
variable_t *get_variable(frog_t *frog, char *name);
char *get_string_value(variable_t *var);
void burn_variable(frog_t *frog, char *name);

void add_variable(frog_t *frog, char *key, char *type, char *value)
{
    variable_t *var = malloc(sizeof(variable_t));
    var->type = type;
    var->name = key;

    if (my_compstr("boolean", type))
        var->boolean = my_compstr(value, "true") ? 1 : 0;
    if (my_compstr("string", type))
        var->string = value;
    if (my_compstr("number", type))
        var->number = my_conv_str_nb(value, 0);
    frog->variables = addin_var(frog->variables, var);
}

void set_variable(frog_t *frog, char **line)
{
    char *key;
    char *value;
    char *type;
    variable_t *maybe_var;

    if (my_countarray(line) != 4 || !my_compstr(line[2], "="))
        return;
    key = line[1];
    value = line[3];
    type = get_type(value);
    maybe_var = get_variable(frog, value);

    if (maybe_var != NULL) {
        type = maybe_var->type;
        value = get_string_value(maybe_var);
    } if (my_compstr(type, "null"))
        return;
    burn_variable(frog, key);
    add_variable(frog, key, type, value);
}
