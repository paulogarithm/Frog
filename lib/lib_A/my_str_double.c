/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_str_nb
*/

double my_str_double(char *str)
{
    double ret = 0;
    double frac = 1;
    int sign = 1;
    int decimal = 0;

    if (str[0] == '-')
        sign = -1;
    for (int i = sign < 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            decimal = 1;
            continue;
        } if (str[i] < '0' || str[i] > '9')
            return 0;
        if (decimal) {
            frac /= 10;
            ret += (str[i] - '0') * frac;
        } else
            ret = ret * 10 + (str[i] - '0');
    }
    return ret * sign;
}
