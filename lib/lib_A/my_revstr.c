/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_revstr
*/

int my_strlen(char *str);

void my_revstr(char *str)
{
    int len = my_strlen(str);
    int j = len - 1;
    char tmp;

    for (int i = 0; i < ((len + 1) / 2); i ++) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j -= 1;
    }
}
