/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <stdlib.h>

#include "polib.h"
#include "frog.h"

int get_type(char *str);
variable_t *get_variable(frog_t *frog, char *name);
char *get_textvalue(variable_t *var);

char **cmon_do_math_a(char **array, frog_t *frog);
char **cmon_do_math_b(char **array, frog_t *frog);
char **cmon_do_math_c(char **array, frog_t *frog);

static int is_operator(char *line)
{
    if (my_compstr(line, "==") || my_compstr(line, "!="))
        return 1;
    if (my_compstr(line, ">=") || my_compstr(line, "<="))
        return 1;
    if (my_findchar("+-%/*<>&", line[0]) >= 0 && my_strlen(line) == 1)
        return 1;
    return 0;
}

static int check_operators(char **array)
{
    int n;

    for (n = 0; array[n] != NULL; n ++)
        if (n % 2 == 1 && !is_operator(array[n]))
            return 0;
    return (my_arraylen(array) % 2);
}

char **replace_variables(char **array, frog_t *frog, char **line)
{
    variable_t *var;
    char *var_val;

    for (int n = 0; array[n] != NULL; n ++) {
        if (n % 2 == 1 || get_type(array[n]) != null)
            continue;
        var = get_variable(frog, array[n]);
        var_val = get_textvalue(var);
        if (var_val == NULL) {
            free_ception(array);
            free(*line);
            return NULL;
        }
        free(array[n]);
        array[n] = var_val;
    }
    return array;
}

static void remove_ands(char ***array)
{
    for (int n = 0; (*array)[n] != NULL; n ++)
        if (my_strlen((*array)[n]) == 1 && (*array)[n][0] == '&')
            crush_array(array, n --);
}

char *calculus(char *line_const, frog_t *frog)
{
    char *line = my_newstr(line_const);
    char **array = my_str_array(line);

    if (!check_operators(array)) {
        free_ception(array);
        free(line);
        return NULL;
    }
    array = replace_variables(array, frog, &line);
    if (array == NULL)
        return NULL;

    array = cmon_do_math_a(array, frog);
    array = cmon_do_math_b(array, frog);
    array = cmon_do_math_c(array, frog);
    remove_ands(&array);
    free(line);
    line = my_strjoin(array, " ");
    free_ception(array);
    return line;
}
