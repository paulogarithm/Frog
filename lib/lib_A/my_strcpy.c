/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_strcpy
*/

void my_strcpy(char *dest, char *src)
{
    int n;

    for (n = 0; src[n] != '\0'; n ++)
        dest[n] = src[n];
    dest[n] = '\0';
}
