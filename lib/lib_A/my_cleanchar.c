/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_cleanchar
*/

void my_cleanchar(char *str, char c)
{
    int place = 0;

    for (int n = place; str[n] != '\0'; n ++) {
        if (str[n] == c)
            continue;
        str[place] = str[n];
        place += 1;
    }
    str[place] = '\0';
}
