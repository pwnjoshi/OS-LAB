// Question: Read a message from a FIFO. Start the writer first.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    char message[100];
    int fd = open("os_lab_fifo", O_RDONLY);
    if (fd == -1) { perror("open (start writer first)"); return 1; }
    ssize_t count;
    printf("Received: ");
    while ((count = read(fd, message, sizeof(message))) > 0)
        fwrite(message, 1, (size_t)count, stdout);
    if (count == -1) { perror("read"); close(fd); return 1; }
    close(fd);
    unlink("os_lab_fifo");
    return 0;
}
