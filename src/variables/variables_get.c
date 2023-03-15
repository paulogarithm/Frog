/*
** Paul PARISOT, 2023
** Frog
** File description:
** variables_get
*/

#include <stdio.h>

#include "../../include/frog.h"

int my_compstr(char *a, char *b);
char *my_conv_nb_str(int nb);

variable_t **push_variables(variable_t **variables, int index)
{
    int n = 0;

    if (index < 0)
        return variables;
    for (n = index + 1; variables[n] != NULL; n ++)
        variables[n - 1] = variables[n];
    variables[n - 1] = NULL;
    return variables;
}

void show_variables(frog_t *frog)
{
    printf("List of variables:\n");
    for (int n = 0; frog->variables[n] != NULL; n ++)
        printf("[%s]\t%s\n",
        frog->variables[n]->type, frog->variables[n]->name);
}

int get_variable_index(frog_t *frog, char *name)
{
    for (int n = 0; frog->variables[n] != NULL; n ++)
        if (my_compstr(name, frog->variables[n]->name))
        return n;
    return -1;
}

variable_t *get_variable(frog_t *frog, char *name)
{
    for (int n = 0; frog->variables[n] != NULL; n ++)
        if (my_compstr(name, frog->variables[n]->name))
        return frog->variables[n];
    return NULL;
}

char *get_string_value(variable_t *var)
{
    if (my_compstr(var->type, "boolean"))
        return var->boolean ? "true" : "false";
    if (my_compstr(var->type, "string"))
        return var->string;
    if (my_compstr(var->type, "number"))
        return my_conv_nb_str(var->number);
    return NULL;
}

void burn_variable(frog_t *frog, char *name)
{
    int index = get_variable_index(frog, name);

    if (index < 0)
        return;
    frog->variables = push_variables(frog->variables, index);
}
