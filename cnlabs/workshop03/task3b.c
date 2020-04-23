//task3b.c workshop 03
​
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
    ​
#define BUFFER_SIZE 1000
        ​ int
        main(int argc, const char *argv[])
{
    ​
        // this need slots of work........
        int fd;
    char *buffer;
    //int br;
    ​
        fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC);
    if (fd == -1)
    {
        printf("failed to create and open the file");
        exit(1);
    }
    ​
        // below is some code for debugging
        printf("fd = %d\n", fd);
    ​
        buffer = (char *)malloc(BUFFER_SIZE);
    ​ if (buffer == NULL)
    {
        printf("ERROR : unable to create buffer. \n");
        exit(1);
    }
    ​ int bufferUsed = 0;
    int bytesRead;
    if (*buffer != EOF || BUFFER_SIZE <= 1000)
    {
        printf("test 1\n");
        bytesRead = read(STDIN_FILENO, buffer + bufferUsed, BUFFER_SIZE - bufferUsed);
        if (fd == -1)
        {
            printf("ERROR :failed to read the file \n");
            exit(1);
        }
        bufferUsed += bytesRead;
        printf("test 2\n");
    }
    write(fd, buffer, bufferUsed);
    ​
        close(fd);
    free(buffer);
    return 0;
}
​
