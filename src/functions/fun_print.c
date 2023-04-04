/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** nat_print
*/

#include <stdlib.h>

#include "frog.h"
#include "polib.h"

char *calculus(char *line_const, frog_t *frog);
int get_type(char *str);

void better_number(char **str)
{
    double nb;
    char **array = NULL;

    if (*str == NULL)
        return;
    array = my_str_array(*str);
    free(*str);
    for (int n = 0; array[n] != NULL; n ++) {
        if (!my_isdouble(array[n]))
            continue;
        nb = my_str_double(array[n]);
        if ((nb - (int) nb) != 0)
            continue;
        free(array[n]);
        array[n] = my_nb_str((int) nb);
    }
    *str = my_strjoin(array, " ");
    free_ception(array);
}

void rem_quote(char **str)
{
    char *res = NULL;
    char **array = NULL;

    if (*str == NULL)
        return;
    array = my_str_array(*str);
    free(*str);
    for (int n = 0; array[n] != NULL; n ++) {
        if (get_type(array[n]) != string)
            continue;
        array[n][0] = ' ';
        array[n][my_strlen(array[n]) - 1] = ' ';
        res = my_normalize(array[n]);
        free(array[n]);
        array[n] = res;
    }
    *str = my_strjoin(array, " ");
    free_ception(array);
}

void native_print(frog_t *frog, char **array)
{
    char **tmp = malloc(sizeof(char *));
    char *cal;
    char *line;

    tmp[0] = NULL;
    for (int n = 0; array[n] != NULL; n++)
        addin_array(&tmp, array[n]);
    line = my_strjoin(tmp, " ");
    cal = calculus(line, frog);
    better_number(&cal);
    rem_quote(&cal);
    my_printf("%s\n", cal != NULL ? cal : "\033[90mnull\033[m");
    free_ception(tmp);
    free(line);
    if (cal != NULL)
        free(cal);
    free_ception(array);
}
