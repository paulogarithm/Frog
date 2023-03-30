/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_math
*/

int my_abs(int a)
{
    return a < 0 ? -a : a;
}

int my_pow(int a, unsigned int b)
{
    int ret = 1;

    for (int i = 0; i < (int) b; i ++)
        ret *= a;
    return ret;
}
