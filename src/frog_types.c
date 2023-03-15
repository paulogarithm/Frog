/*
** Paul PARISOT, 2023
** frog_code
** File description:
** get_type
*/

int my_isnb(char *str);
int my_countstr(char *str);
int my_compstr(char *a, char *b);

int count_chars(char *str, char c)
{
    int count = 0;
    for (int n = 0; str[n] != '\0'; n ++)
        if (str[n] == c)
            count += 1;
    return count;
}

char *get_type(char *val)
{
    int cond = 0;

    cond = my_countstr(val) == 0;
    if (cond) return "null";

    cond = count_chars(val, '"') == 2;
    cond = cond && val[0] == '"' && val[my_countstr(val) - 1] == '"';
    if (cond) return "string";

    cond = my_isnb(val);
    if (cond) return "number";

    cond = my_compstr(val, "true") || my_compstr(val, "false");
    if (cond) return "boolean";

    return "null";
}
