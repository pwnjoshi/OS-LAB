// Question: Send a message using a FIFO (named pipe). Run the reader too.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main(void)
{
    const char *path = "os_lab_fifo";
    char message[100];
    if (mkfifo(path, 0600) == -1 && errno != EEXIST)
    { perror("mkfifo"); return 1; }
    printf("Enter a message: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return 1;
    int fd = open(path, O_WRONLY); // Waits until the reader opens the FIFO.
    if (fd == -1) { perror("open"); return 1; }
    size_t length = 0;
    while (message[length] != '\0') length++;
    if (write(fd, message, length) != (ssize_t)length)
    { perror("write"); close(fd); return 1; }
    close(fd);
    return 0;
}
