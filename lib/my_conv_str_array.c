/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <stdlib.h>

int my_countstr(char *str);
char *my_cutstr(char *str, int beggin, int end);
char *my_addstr(char *a, char *b);

char **my_addin_array(char **array, char *str);

char **replace_quotes(char **array)
{
    char **new = malloc(sizeof(char *) * 2);
    int n = 0;
    char *tmp = "";
    int isquote = 0;
    new[0] = NULL;
    while (array[n] != NULL) {
        if (array[n][0] == '"')
            isquote = 1;
        if (isquote)
            tmp = my_addstr(tmp, my_addstr(array[n], " "));
        else {
            new = my_addin_array(new, my_cutstr(tmp, 1, my_countstr(tmp) - 2));
            tmp = "";
            new = my_addin_array(new, array[n]);
        } if (array[n][my_countstr(array[n]) - 1] == '"')
            isquote = 0;
        n += 1;
    } if (my_countstr(tmp) != 0)
        new = my_addin_array(new, my_cutstr(tmp, 0, my_countstr(tmp) - 1));
    return new;
}

char **my_conv_str_array(char *src)
{
    char **array = malloc(sizeof(char *) * 2);
    int n = 0;
    int index = 0;
    char *cut = "";

    array[0] = NULL;
    while (1) {
        if (src[n] == ' ' || !src[n] || src[n] == '\t') {
            cut = my_cutstr(src, index, n);
            array = my_addin_array(array, cut);
            index = n + 1;
        } if (!src[n])
            break;
        n += 1;
    }
    return replace_quotes(array);
}
