/*
** Paul PARISOT, 2023
** frog_code
** File description:
** read_file
*/

#include <stdlib.h>

#include "../include/frog.h"

char **my_conv_str_array(char *src);
int my_compstr(char *a, char *b);
int my_countarray(char **array);

void set_variable(frog_t *frog, char **line);
void show_variables(frog_t *frog);
void native_print(frog_t *frog, char *line);

int beggins_with(char *str, char *beg);

frog_t *setup_frog(void)
{
    frog_t *frog = malloc(sizeof(frog_t));
    frog->variables = malloc(sizeof(variable_t));

    frog->variables[0] = NULL;
    return frog;
}

void read_file(char **parcing)
{
    frog_t *frog = setup_frog();
    char **line;

    for (int n = 0; parcing[n] != NULL; n ++) {
        line = my_conv_str_array(parcing[n]);
        if (my_countarray(line) == 0)
            continue;
        if (my_compstr(line[0], "set"))
            set_variable(frog, line);
        if (beggins_with(line[0], "print"))
            native_print(frog, parcing[n]);
    }
}
