/*
** Paul PARISOT, 2023
** object_parcing
** File description:
** my_array
*/

#include <unistd.h>
#include <stdlib.h>

void my_putstr(char *str);
int my_countstr(char *str);
char *my_cutstr(char *str, int beggin, int end);
char *my_dupstr(char *str);
char *my_compstr(char *str1, char *str2);

int my_countarray(char **array)
{
    int n = 0;

    while (array[n] != NULL)
        n += 1;
    return n;
}

void my_showarray(char **array)
{
    int n = 0;

    while (array[n] != NULL) {
        my_putstr(array[n ++]);
        my_putstr("\n");
    }
}

void free_this_array(char **array)
{
    int n = 0;
    while (array[n] != NULL)
        free(array[n ++]);
    free(array);
}

char **my_remove_array(char **array, char *key)
{
    int array_len = my_countarray(array);
    int key_len = my_countstr(key);
    char **new = malloc(sizeof(char *) * (array_len + 1));
    int n = 0;
    int i = 0;

    while (array[n] != NULL) {
        if (my_compstr(my_cutstr(array[n], 0, key_len), key)) {
            n += 1;
            continue;
        }
        new[i] = my_dupstr(array[n]);
        n += 1;
        i += 1;
    }
    new[i] = NULL;
    return new;
}

char **my_addin_array(char **array, char *str)
{
    char **new_array;
    int size = 0;
    int n = 0;

    if (!my_countstr(str))
        return array;
    while (array[size] != NULL)
        size ++;
    size += 1;
    new_array = malloc(sizeof(char *) * (size + 1));
    while (array[n] != NULL) {
        new_array[n] = my_dupstr(array[n]);
        n += 1;
    }
    new_array[n] = my_dupstr(str);
    new_array[n + 1] = NULL;
    free_this_array(array);
    return new_array;
}
