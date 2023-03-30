/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_array
*/

#include <stdlib.h>

char *my_newstr(char *str);
int my_putstr(char *str);
void *my_puterr(char *str);

int my_arraylen(char **array)
{
    int n = 0;
    for (n = 0; array[n] != NULL; n ++);
    return n;
}

void free_ception(char **array)
{
    for (int i = 0; array[i] != NULL; i ++)
        free(array[i]);
    free(array);
}

void addin_array(char ***array, char *str)
{
    int len = my_arraylen(*array);
    char **new_array = malloc(sizeof(char *) * (len + 2));

    if (new_array == NULL)
        return (void) my_puterr("Malloc Failure.\n");
    for (int n = 0; n < len; n ++)
        new_array[n] = (*array)[n];
    new_array[len] = my_newstr(str);
    new_array[len + 1] = NULL;
    free(*array);
    *array = new_array;
}

void crush_array(char ***array, int index)
{
    int len = my_arraylen(*array);
    char **new_array = malloc(sizeof(char *) * len);
    int ratio = 0;

    if (new_array == NULL)
        return (void) my_puterr("Malloc Failure.\n");
    for (int n = 0; n < len; n ++)
        if (n == index)
            ratio = 1;
        else
            new_array[n - ratio] = my_newstr((*array)[n]);
    new_array[len - 1] = NULL;
    free_ception(*array);
    *array = new_array;
}
