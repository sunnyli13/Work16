#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd;
    char buffer[100];
    mkfifo("plumbing", 0666);

    while (1) {
        fd = open("plumbing", O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        
        close(fd);

        char *stuff = buffer;

        int len = strlen(buffer);
        for (int i = 0, j = len - 1; i < j; i++, j--) {
            char ch = buffer[i];
            buffer[i] = buffer[j];
            buffer[j] = ch;
        }

        fd = open("plumbing", O_WRONLY);
        write(fd, buffer, sizeof(buffer));

        close(fd);
    }

    return 0;
}