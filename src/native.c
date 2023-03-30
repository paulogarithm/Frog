/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** native
*/

#include <stdlib.h>

#include "frog.h"
#include "polib.h"

char *calculus(char *line_const, frog_t *frog);
void read_it(frog_t *frog, int beg);

int find_function(char **array, char *name)
{
    int len = my_arraylen(array);

    for (int n = 0; n < len; n ++) {
        char **split = my_str_array(array[n]);

        if (my_compstr(split[0], "function")
        && my_arraylen(split) >= 2
        && my_compstr(split[1], name)) {
            free_ception(split);
            return n;
        }
        free_ception(split);
    }

    return -1;
}

void native_print(frog_t *frog, char **array)
{
    char **tmp = malloc(sizeof(char *));
    char *cal;
    char *line;

    tmp[0] = NULL;
    for (int n = 0; array[n] != NULL; n ++)
        addin_array(&tmp, array[n]);
    line = my_strjoin(tmp, " ");
    cal = calculus(line, frog);
    my_printf("%s\n", cal != NULL ? cal : "null");

    free_ception(tmp);
    free(line);
    if (cal != NULL)
        free(cal);
    free_ception(array);
}

void local_function(frog_t *frog, char *name)
{
    int n = 0;

    if (name == NULL)
        return;
    n = find_function(frog->array, name);
    if (n < 0)
        return;
    read_it(frog, n);
}

void execute_function(frog_t *frog, char **array)
{
    char **args = my_duparray(array);
    char *name = my_newstr(args[0]);

    crush_array(&args, 0);
    if (my_compstr("print", name)) {
        free(name);
        return native_print(frog, args);
    }
    local_function(frog, name);

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
    if (line[my_strlen(split[0])] == '('
    && line[my_strlen(line) - 1] == ')')
        execute_function(frog, split);

    free(line);
    free_ception(split);
    free_ception(split_template);
}
