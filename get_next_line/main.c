#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd1;
    int fd2;

    fd1 = open("test.txt",O_RDONLY);
    fd2 = open("test1.txt",O_RDONLY);
    char *line;
    char *line1;

    while(1)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("%s",line);
            free(line);
        }
        line1 = get_next_line(fd2);
        if(line1)
        {
            printf("%s",line1);
            free(line1);
        }
        if(!line || !line1)
            break;
    }
}