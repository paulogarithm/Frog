/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** condition
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

int find_first_end(char **array, int begin);
char *calculus(char *line_const, frog_t *frog);
void read_it(frog_t *frog, int beg);

void native_condition(frog_t *frog, char **array_template, int *n)
{
    char **array = my_newarray(array_template);
    char *cal;
    char *join;

    crush_array(&array, my_arraylen(array) - 1);
    crush_array(&array, 0);
    join = my_strjoin(array, " ");
    cal = calculus(join, frog);
    if (my_compstr(cal, "true") || my_str_nb(cal))
        read_it(frog, *n + 1);

    *n = find_first_end(frog->array, *n);
    free_ception(array);
    free(cal);
    free(join);
}
