/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_ignorequote
*/

#include <stdlib.h>

int my_strlen(char *str);
void my_addstr(char **dest, char *add);
char *my_newstr(char *text);
void addin_array(char ***array, char *str);
void free_ception(char **array);
int my_arraylen(char **array);

static int is_quote_word(char *str)
{
    return (str[0] == '"') + (str[my_strlen(str) - 1] == '"');
}

char *my_cutarray(char **array, int a, int b)
{
    char *new = my_newstr("");

    for (int n = a; n <= b && array[n] != NULL; n ++) {
        my_addstr(&new, n != a ? " " : "");
        my_addstr(&new, array[n]);
    }
    return new;
}

static void the_last_word(int previous_index, char ***array, char ***new)
{
    char *str;

    if (previous_index >= 0) {
        str = my_cutarray(*array, previous_index, my_arraylen(*array));
        addin_array(new, str);
        free(str);
    }
}

void ignore_quotes(char ***array)
{
    char **new = malloc(sizeof(char *));
    int previous_index = -1;
    char *str;

    new[0] = NULL;
    for (int n = 0; (*array)[n] != NULL; n ++) {
        if (is_quote_word((*array)[n]) == 1 && previous_index >= 0) {
            str = my_cutarray(*array, previous_index, n);
            addin_array(&new, str);
            free(str);
            previous_index = -1;
            continue;
        } if (is_quote_word((*array)[n]) == 1 && previous_index < 0)
            previous_index = n;
        if (previous_index < 0 || is_quote_word((*array)[n]) == 2)
            addin_array(&new, (*array)[n]);
    }
    the_last_word(previous_index, array, &new);
    free_ception(*array);
    *array = new;
}
