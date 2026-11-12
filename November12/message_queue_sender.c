// Question: Send a message using a System V message queue.
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

struct message { long type; char text[100]; };

int main(void)
{
    struct message msg = { .type = 1 };
    printf("Enter a message: ");
    if (fgets(msg.text, sizeof(msg.text), stdin) == NULL) return 1;
    int id = msgget(1234, 0600 | IPC_CREAT);
    if (id == -1) { perror("msgget"); return 1; }
    if (msgsnd(id, &msg, strlen(msg.text) + 1, 0) == -1)
    { perror("msgsnd"); return 1; }
    printf("Message sent. Run the receiver.\n");
    return 0;
}
