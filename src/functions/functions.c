/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** native
*/

#include <stdlib.h>

#include "frog.h"
#include "polib.h"

int native_function(frog_t *frog, char *name, char **args);
void local_function(frog_t *frog, char *name, char **array);

int find_function(char **array, char *name)
{
    int len = my_arraylen(array);
    char **split = NULL;

    for (int n = 0; n < len; n++) {
        split = my_str_array(array[n]);
        if (split[0] == NULL) {
            free_ception(split);
            continue;
        }
        if (my_compstr(split[0], "function") && my_arraylen(split) >= 2
        && my_compstr(split[1], name)) {
            free_ception(split);
            return n;
        }
        free_ception(split);
    }
    return -1;
}

void execute_function(frog_t *frog, char **array)
{
    char **args = my_newarray(array);
    char *name = my_newstr(args[0]);
    char *old_function;

    crush_array(&args, 0);
    if (native_function(frog, name, args))
        return free(name);
    old_function = frog->current_function;
    local_function(frog, name, args);
    frog->current_function = old_function;

    free(name);
    free_ception(args);
}

void is_it_function(frog_t *frog, char *line_template)
{
    char *line = my_newstr(line_template);
    char **split;
    char **split_template;

    if (my_countchar(line, '(') != 1 || my_countchar(line, ')') != 1)
        return free(line);
    split_template = my_str_array(line);
    my_replacechar(line, '(', ' ');
    my_replacechar(line, ')', ' ');
    my_replacechar(line, ',', ' ');
    split = my_str_array(line);
    free(line);
    line = my_strjoin(split_template, " ");
    if (line[my_strlen(split[0])] == '(' && line[my_strlen(line) - 1] == ')')
        execute_function(frog, split);

    free(line);
    free_ception(split);
    free_ception(split_template);
}
