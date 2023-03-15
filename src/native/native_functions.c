/*
** Paul PARISOT, 2023
** Frog
** File description:
** basic_functions
*/

#include <stdio.h>

#include "../../include/frog.h"

int my_countstr(char *str);
char *my_replace_char(char *str, char replace, char by);
char *my_cutstr(char *str, int a, int b);
char **my_conv_str_array(char *src);
char *unstringify(char *str);
int my_compstr(char *a, char *b);

variable_t *get_variable(frog_t *frog, char *name);
char *get_variable_string(variable_t *var);
char *get_type(char *val);

void native_print_display(frog_t *frog, char **parametters)
{
    variable_t *var;

    for (int n = 0; parametters[n] != NULL; n ++) {
        if (!my_compstr(get_type(parametters[n]), "null")) {
            printf("%s%s", n ? " " : "", parametters[n]);
            continue;
        }
        var = get_variable(frog, parametters[n]);
        if (var == NULL)
            printf("%snull", n ? " " : "");
        else
            printf("%s%s", n ? " " : "",
            unstringify(get_variable_string(var)));
    }
    printf("\n");
}

void native_print(frog_t *frog, char *line)
{
    char *base = "print";
    int len_base = my_countstr(base);
    int len_line = my_countstr(line);
    char *parametters;
    char **parametters_split;

    if (line[len_base] != '(' && line[len_line - 1] != ')')
        return;
    parametters = my_cutstr(line, len_base + 1, len_line - 1);
    parametters = my_replace_char(parametters, ',', ' ');
    parametters_split = my_conv_str_array(parametters);
    native_print_display(frog, parametters_split);
}
