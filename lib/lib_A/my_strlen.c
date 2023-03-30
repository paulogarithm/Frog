/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int n;

    for (n = 0; str[n] != '\0'; n ++);
    return n;
}
