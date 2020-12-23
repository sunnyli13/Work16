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
    int p = mkfifo("plumbing", 0666);

    printf("I am Reverse9000!");

    while (1) {
        printf("\nInput to reverse: ");

        fd = open("plumbing", O_WRONLY);
        fgets(buffer, sizeof(buffer), stdin);
        write(fd, buffer, sizeof(buffer));

        close(fd);

        fd = open("plumbing", O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        printf("%s\n", buffer);
        
        close(fd);
    }

    return 0;
}