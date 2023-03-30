/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** free
*/

#include <stdlib.h>

#include "frog.h"
#include "polib.h"

void free_var(variable_t *var)
{
    free(var->name);
    if (var->string != NULL)
        free(var->string);
    free(var);
}

void free_the_frog(frog_t *frog)
{
    free_ception(frog->array);
    for (int n = 0; frog->varibales[n] != NULL; n ++)
        free_var(frog->varibales[n]);
    free(frog->varibales);
    free(frog->null_ptr);
    free(frog);
}
