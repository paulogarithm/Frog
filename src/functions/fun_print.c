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
    my_printf("%s\n", cal != NULL ? cal : "\033[90mnull\033[m");
    free_ception(tmp);
    free(line);
    if (cal != NULL)
        free(cal);
    free_ception(array);
}
