/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_findchar
*/

int my_strlen(char *str);

int my_findchar(char *str, char c)
{
    for (int n = 0; str[n] != '\0'; n ++)
        if (str[n] == c)
            return n;
    return -1;
}

int my_findstr(char *str, char *find)
{
    int find_index = 0;
    int find_len = my_strlen(find);
    int str_index;

    for (str_index = 0; str[str_index] != '\0'; str_index ++) {
        if (str[str_index] == find[find_index])
            find_index += 1;
        else
            find_index = 0;
        if (find_index == find_len)
            return 1;
        str_index += 1;
    }
    return 0;
}
