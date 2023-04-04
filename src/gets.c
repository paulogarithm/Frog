/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** isit
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

variable_t *get_variable(frog_t *frog, char *name)
{
    for (int n = 0; frog->varibales[n] != NULL; n ++) {
        if (my_compstr(name, frog->varibales[n]->name))
            return frog->varibales[n];
    }
    return NULL;
}

char *get_textvalue(variable_t *var)
{
    if (var == NULL)
        return NULL;
    switch (var->type) {
        case number:
        return my_double_str(var->number);

        case string:
        return my_newstr(var->string);

        case boolean:
        return var->boolean ? my_newstr("true") : my_newstr("false");

        case null:
        default:
        return NULL;
    }
}

int get_type(char *str)
{
    double nb = my_str_double(str);

    if (str[0] == '"' && str[my_strlen(str) == '"'])
        return string;
    if (nb || my_compstr(str, "0"))
        return number;
    if (my_compstr(str, "true") || my_compstr(str, "false"))
        return boolean;
    return null;
}

double get_numbervalue(char *str, frog_t *frog)
{
    double nb = my_str_double(str);
    variable_t *var = get_variable(frog, str);

    if (nb)
        return nb;
    if (var == NULL)
        return 0;
    if (var->type == boolean)
        return (double) var->boolean;
    if (var->type == number)
        return var->number;
    return 0;
}
