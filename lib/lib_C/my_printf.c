/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>

char *my_nb_str(int nb);
char *my_newstr(char *text);
void my_addstr(char **dest, char *add);
void my_addchar(char **dest, char c);
int my_putstr(char *str);
char *my_disparray(char **array);

static char *do_switch(const char *str, int *n, va_list ap)
{
    *n += 1;
    switch (str[*n]) {
        case 's':
        return my_newstr(va_arg(ap, char *));
        case 'i':
        case 'd':
        return my_nb_str(va_arg(ap, int));
        case 'c':
        char *c = my_newstr("");
        my_addchar(&c, va_arg(ap, int));
        return c;
        case 'a':
        return my_disparray(va_arg(ap, char **));
        case '%':
        return my_newstr("%");
        default:
        return "";
    }
}

int my_printf(const char *str, ...)
{
    char *final = my_newstr("");
    int len = 0;

    va_list ap;
    va_start(ap, str);
    for (int n = 0; str[n] != '\0'; n ++) {
        if (str[n] == '%') {
            char *tmp = do_switch(str, &n, ap);
            my_addstr(&final, tmp);
            free(tmp);
        } else
            my_addchar(&final, str[n]);
    }
    len = my_putstr(final);

    va_end(ap);
    free(final);
    return len;
}
