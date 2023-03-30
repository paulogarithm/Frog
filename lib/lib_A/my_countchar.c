/*
** EPITECH PROJECT, 2023
** New_Frog
** File description:
** my_countchars
*/

int my_countchar(char *str, char c)
{
    int counter = 0;

    for (int n = 0; str[n] != '\0'; n ++)
        if (str[n] == c)
            counter += 1;
    return counter;
}
