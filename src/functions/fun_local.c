/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** fun_local
*/

#include <stdlib.h>

#include "frog.h"
#include "polib.h"

void read_it(frog_t *frog, int beg);
int find_function(char **array, char *name);
void set_variable(frog_t *frog, char **line);

void create_var_arguments(frog_t *frog, char *line, char **args)
{
    char **array = my_str_array(line);
    char **var_line = NULL;

    crush_array(&array, 0);
    crush_array(&array, 0);
    for (int n = 0; array[n] != NULL; n ++) {
        var_line = malloc(sizeof(char *));
        var_line[0] = NULL;
        addin_array(&var_line, array[n]);
        addin_array(&var_line, " = ");
        addin_array(&var_line, args[n]);
        set_variable(frog, var_line);
        free_ception(var_line);
    }
    free_ception(array);
}

void local_function(frog_t *frog, char *name, char **args)
{
    int n = 0;

    if (name == NULL)
        return;
    n = find_function(frog->array, name);
    if (n < 0)
        return;
    frog->current_function = name;
    create_var_arguments(frog, frog->array[n], args);
    read_it(frog, n);
}
