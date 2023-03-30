/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_parsing
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

void *my_puterr(char *message);
char **my_strsplit(char *str, char *correct);

char *my_parsing(char *path)
{
    int fd;
    int res;
    struct stat st;
    char *buf;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return my_puterr("Invalid Path.\n");
    res = stat(path, &st);
    if (res < 0)
        return my_puterr("Invalid Path.\n");
    buf = malloc(sizeof(char) * (st.st_size + 1));
    if (buf == NULL)
        return my_puterr("Malloc Failure.\n");
    res = read(fd, buf, st.st_size);
    if (res < 0)
        return my_puterr("Read Failed.\n");
    buf[st.st_size] = '\0';
    return buf;
}

char **my_array_parsing(char *path)
{
    char *str = my_parsing(path);
    char **array;

    if (str == NULL)
        return NULL;
    array = my_strsplit(str, "\n");
    free(str);
    return array;
}
