/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** variables
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

void *my_puterr(char *message);
variable_t *get_variable(frog_t *frog, char *name);

char *calculus(char *line_const, frog_t *frog);
int get_type(char *str);

void auto_setup_var(variable_t *var, char *str)
{
    var->type = get_type(str);
    switch (var->type) {
        case number:
        var->number = my_str_nb(str);
        break;
        case boolean:
        var->boolean = my_compstr(str, "true");
        break;
        case string:
        var->string = my_cutstr(str, 1, my_strlen(str) - 1);
        break;
        default:
        break;
    }
}

variable_t *create_var(frog_t *frog, char *name, char *value)
{
    variable_t *exists = get_variable(frog, name);
    variable_t *var = exists != NULL ? exists : NULL;

    if (exists == NULL) {
        var = malloc(sizeof(variable_t));
        if (var == NULL)
            return my_puterr("Malloc Failure");
        var->name = my_newstr(name);
        var->string = NULL;
    }
    auto_setup_var(var, value);

    return exists != NULL ? NULL : var;
}

int my_varslen(variable_t **vars)
{
    int n;
    for (n = 0; vars[n] != NULL; n ++);
    return n;
}

void addin_var(variable_t ***array, variable_t *var)
{
    int len = my_varslen(*array);
    variable_t **new_array = malloc(sizeof(variable_t *) * (len + 2));

    if (new_array == NULL)
        return (void) my_puterr("Malloc Failure.\n");
    for (int n = 0; n < len; n ++)
        new_array[n] = (*array)[n];
    new_array[len] = var;
    new_array[len + 1] = NULL;
    free(*array);
    *array = new_array;
}

void set_variable(frog_t *frog, char **line)
{
    char **tmp = my_newarray(line);
    char *tmp_line;
    char *value;
    variable_t *var;

    crush_array(&tmp, 0);
    crush_array(&tmp, 0);
    tmp_line = my_strjoin(tmp, " ");
    value = calculus(tmp_line, frog);
    if (value == NULL)
        return;
    var = create_var(frog, line[0], value);
    if (var != NULL)
        addin_var(&frog->varibales, var);
    free(tmp_line);
    free(value);
    free_ception(tmp);
}
