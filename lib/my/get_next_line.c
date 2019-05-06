/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** Take a line from a file descriptor
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../../include/my.h"

void read_file(char *buffer, int fd)
{
    int ret = READ_SIZE;
    int i = 0;

    while (ret > 0 && ret == READ_SIZE) {
        ret = read(fd, buffer + i, READ_SIZE);
        i += ret;
    }
}

char *get_next_line(int fd)
{
    static int index = 0;
    static char buffer[50000];
    char *line = malloc(sizeof(char) * 50000);

    if (line == NULL || READ_SIZE > 50000 || fd == -1)
        return (NULL);
    for (int i = 0; i < 50000; i++)
        line[i] = '\0';
    if (index == 0)
        read_file(buffer, fd);
    if (buffer[index] != '\0') {
        for (int i = 0; buffer[index] != '\n'; i++, index++) {
            line[i] = buffer[index];
            if (buffer[index] == '\0')
                return (NULL);
        }
    } else
        return (NULL);
    index += 1;
    return (line);
}
