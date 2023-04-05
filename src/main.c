/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

void read_it(frog_t *frog, int beg);
char *calculus(const char *line_const, frog_t *frog);
void free_the_frog(frog_t *frog);
void set_variable(frog_t *frog, char **line);

void local_function(frog_t *frog, char *name, char **array);
void is_it_function(frog_t *frog, char *line_template);
void native_condition(frog_t *frog, char **array_template, int *n);
void native_while(frog_t *frog, char **array_template, int *n);

int find_first_end(char **array, int begin)
{
    char *norm = malloc(sizeof(char));
    int n;

    for (n = begin; array[n] != NULL; n ++) {
        free(norm);
        norm = my_normalize(array[n]);
        if (my_compstr(norm, "end"))
            break;
    }
    free(norm);
    return n;
}

int rooter(frog_t *frog, char **line, int *n)
{
    if (my_compstr(line[0], "end"))
        return 1;
    if (my_arraylen(line) >= 3 && my_compstr(line[1], "="))
        set_variable(frog, line);
    if (my_arraylen(line) >= 3 && my_compstr(line[0], "if")
    && my_compstr(line[my_arraylen(line) - 1], "then"))
        native_condition(frog, line, n);
    if (my_arraylen(line) >= 3 && my_compstr(line[0], "while")
    && my_compstr(line[my_arraylen(line) - 1], "do"))
        native_while(frog, line, n);
    is_it_function(frog, frog->array[*n]);
    return 0;
}

void read_it(frog_t *frog, int beg)
{
    int len = my_arraylen(frog->array);
    char **line = malloc(sizeof(char *));

    line[0] = NULL;
    for (int n = beg; n < len; n ++) {
        free_ception(line);
        line = my_str_array(frog->array[n]);
        if (line == NULL || !my_arraylen(line))
            continue;
        if (rooter(frog, line, &n))
            break;
    }
    free_ception(line);
}

frog_t *setup_frog(char **av)
{
    frog_t *frog = malloc(sizeof(frog_t));

    frog->array = my_array_parsing(av[1]);
    frog->varibales = malloc(sizeof(variable_t));
    frog->null_ptr = malloc(sizeof(char));
    frog->current_function = NULL;
    frog->varibales[0] = NULL;
    return frog;
}

int main(int ac, char **av)
{
    frog_t *frog;
    char **array = NULL;
    char *str;

    if (ac < 2)
        return 69;
    array = malloc(sizeof(char *));
    array[0] = NULL;
    str = my_nb_str(ac - 1);
    frog = setup_frog(av);
    addin_array(&array, str);
    local_function(frog, "main", array);
    free_ception(array);
    free(str);
    free_the_frog(frog);
    return 0;
}
