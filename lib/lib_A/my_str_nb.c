/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_str_nb
*/

int my_str_nb(char *str)
{
    int ret = 0;
    int mul = str[0] == '-' ? -1 : 1;
    int num = 0;

    for (int n = mul < 0 ? 1 : 0; str[n] != '\0'; n ++) {
        if (str[n] < '0' || str[n] > '9')
            return 0;
        ret *= 10;
        num = str[n] - '0';
        ret += num;
    }
    return ret * mul;
}
