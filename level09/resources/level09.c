#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
 
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }
 
    unsigned char buffer;
    ssize_t bytesRead;
    size_t index = 0;
 
    while ((bytesRead = read(fd, &buffer, 1)) > 0 && index < 25) {
        putchar((buffer - index));
        index++;
    }

    if (bytesRead == -1) {
        printf("Error: failed to read from file '%s'\n", argv[1]);
        close(fd);
        return 1;
    }

    putchar('\n');
    close(fd);
    return 0;
}

