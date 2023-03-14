/*
** EPITECH PROJECT, 2023
** frog_code
** File description:
** read_file
*/

#include <stdlib.h>
#include <stdio.h>

#include "../include/frog.h"

int my_conv_str_nb(char const *str, int nb);
char **my_conv_str_array(char *src);
int my_compstr(char *a, char *b);
int my_countarray(char **array);

char *get_type(char *val);
string_t **addin_string(string_t **list, string_t *button);
boolean_t **addin_boolean(boolean_t **list, boolean_t *button);
number_t **addin_number(number_t **list, number_t *button);

void attribute_type(frog_t *frog, char *key, char *type, char *value)
{
    if (my_compstr("boolean", type)) {
        boolean_t *val = malloc(sizeof(boolean_t));
        val->boolean = my_compstr(value, "true") ? 1 : 0;
        val->name = key;
        frog->booleans = addin_boolean(frog->booleans, val);
        return;
    } if (my_compstr("string", type)) {
        string_t *val = malloc(sizeof(string_t));
        val->string = value;
        val->name = key;
        frog->strings = addin_string(frog->strings, val);
        return;
    } if (my_compstr("number", type)) {
        number_t *val = malloc(sizeof(number_t));
        val->number_n = my_conv_str_nb(value, 0);
        val->name = key;
        frog->numbers = addin_number(frog->numbers, val);
        return;
    }
}

void set_variable(frog_t *frog, char **line)
{
    char *key;
    char *value;
    char *type;

    if (my_countarray(line) != 4 || !my_compstr(line[2], "="))
        return;
    
    key = line[1];
    value = line[3];
    type = get_type(value);
    if (my_compstr(type, "Null"))
        return;
    attribute_type(frog, key, type, value);
}

frog_t *setup_frog()
{
    frog_t *frog = malloc(sizeof(frog_t));
    frog->booleans = malloc(sizeof(boolean_t));
    frog->numbers = malloc(sizeof(number_t));
    frog->strings = malloc(sizeof(string_t));

    frog->booleans[0] = NULL;
    frog->numbers[0] = NULL;
    frog->strings[0] = NULL;
    return frog;
}

void show_variables(frog_t *frog)
{
    printf("Type  Name\tValue\n\n");
    for (int n = 0; frog->booleans[n] != NULL; n ++)
        printf("[Bol] %s\t%s\n", frog->booleans[n]->name,
        frog->booleans[n]->boolean ? "true" : "false");
    for (int n = 0; frog->numbers[n] != NULL; n ++)
        printf("[Num] %s\t%d\n", frog->numbers[n]->name,
        frog->numbers[n]->number_n);
    for (int n = 0; frog->strings[n] != NULL; n ++)
        printf("[Str] %s\t%s\n", frog->strings[n]->name,
        frog->strings[n]->string);
}

void read_file(char **parcing)
{
    frog_t *frog = setup_frog();
    char **line;

    for (int n = 0; parcing[n] != NULL; n ++) {
        line = my_conv_str_array(parcing[n]);
        if (my_countarray(line) == 0)
            continue;
        if (my_compstr("set", line[0]))
            set_variable(frog, line);
    }
    show_variables(frog);
}
