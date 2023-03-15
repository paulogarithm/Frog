/*
** Paul PARISOT, 2023
** a_star
** File description:
** parcing
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *my_cutstr(char *str, int beggin, int end);
char **my_addin_array(char **array, char *str);

char *my_parcing(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    int st_result = stat(path, &st);
    char *buf;
    int read_result = 0;

    if (fd < 0 || st_result < 0 || st.st_size < 1)
        return NULL;
    buf = malloc(sizeof(char) * (st.st_size + 1));
    if (buf == NULL)
        return NULL;
    read_result = read(fd, buf, st.st_size);
    if (read_result == -1)
        return NULL;
    buf[read_result] = '\0';
    return buf;
}

char **my_array_parcing(char *path)
{
    char *src = my_parcing(path);
    char **array = malloc(sizeof(char *) * 2);
    int n = 0;
    int index = 0;
    char *cut;

    array[0] = NULL;
    if (src == NULL)
        return NULL;
    while (src[n]) {
        if (src[n] == '\n') {
            cut = my_cutstr(src, index, n);
            array = my_addin_array(array, cut);
            index = n + 1;
        }
        n += 1;
    }
    cut = my_cutstr(src, index, n);
    array = my_addin_array(array, cut);
    return array;
}
