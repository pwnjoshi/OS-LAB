// Question: Receive a message from a System V message queue.
#include <stdio.h>
#include <sys/msg.h>

struct message { long type; char text[100]; };

int main(void)
{
    struct message msg;
    int id = msgget(1234, 0600);
    if (id == -1) { perror("msgget (run sender first)"); return 1; }
    ssize_t count = msgrcv(id, &msg, sizeof(msg.text), 1, 0);
    if (count == -1) { perror("msgrcv"); return 1; }
    printf("Received: ");
    fwrite(msg.text, 1, (size_t)count, stdout);
    if (msgctl(id, IPC_RMID, NULL) == -1)
    { perror("msgctl"); return 1; }
    return 0;
}
