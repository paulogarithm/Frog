/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_str_array
*/

#include <stdlib.h>

int my_strlen(char *str);
void *my_puterr(char *str);
int my_findchar(char *str, char c);
char *my_cutstr(char *str, int beg, int end);

void my_addstr(char **dest, char *add);
char *my_newstr(char *text);
void addin_array(char ***array, char *str);

void ignore_quotes(char ***array);

static void do_cut(char ***array, char **cut, int n, int *old)
{
    if (*cut == NULL)
        return;
    if (!my_strlen(*cut)) {
        free(*cut);
        return;
    }
    addin_array(array, *cut);
    free(*cut);
    *old = n + 1;
}

char **my_strsplit(char *str, char *correct)
{
    char **array = malloc(sizeof(char *));
    char *cut;
    int old = 0;

    if (array == NULL)
        return my_puterr("Malloc failure.\n");
    array[0] = NULL;
    for (int n = 0; str[n] != '\0'; n ++) {
        if (my_findchar(correct, str[n]) >= 0 && old != n) {
            cut = my_cutstr(str, old, n);
            do_cut(&array, &cut, n, &old);
        } if (my_findchar(correct, str[n]) >= 0 && old == n)
            old = n + 1;
    }
    cut = my_cutstr(str, old, my_strlen(str));
    do_cut(&array, &cut, 0, &old);
    ignore_quotes(&array);
    return array;
}

char **my_str_array(char *str)
{
    return my_strsplit(str, " \t\n");
}

char *my_strjoin(char **array, char *join)
{
    char *ret = my_newstr("");

    for (int n = 0; array[n] != NULL; n ++) {
        if (n && join)
            my_addstr(&ret, join);
        my_addstr(&ret, array[n]);
    }
    return ret;
}
