#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    struct timeval start, end;
    double time_elapsed;
    int i, fd;
    char str_to_write[14];

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    gettimeofday(&start, NULL);

    for (i = 0; i < 1000000; i++) {
        strcpy(str_to_write, "Hello World!\n");
        if (write(fd, str_to_write, 13) != 13) {
            perror("Error writing to file");
            return 1;
        }
        printf("%d: Called write(3, %s, 13) which returned that %d bytes were written\n", i, str_to_write, 13);
    }

    gettimeofday(&end, NULL);

    time_elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Unbuffered IO time elapsed: %f seconds\n", time_elapsed);

    return 0;
}
