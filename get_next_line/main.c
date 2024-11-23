#include <fcntl.h>  
#include <stdio.h> 
#include <stdlib.h> 
#include "get_next_line.h" 

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);

    //while ((line = get_next_line(fd)))
    //{
        printf("%s", get_next_line(fd));  
        printf("%s", get_next_line(fd));

      /// free(line);        
    //}
    system("leaks a.out")
    close(fd);
    return (0);
}
