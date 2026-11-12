// Question: Write a message into shared memory.
#include <stdio.h>
#include <sys/shm.h>

int main(void)
{
    char message[100];
    printf("Enter a message: ");
    if (fgets(message, sizeof(message), stdin) == NULL) return 1;
    int id = shmget(5678, 100, 0600 | IPC_CREAT);
    if (id == -1) { perror("shmget"); return 1; }
    char *memory = shmat(id, NULL, 0);
    if (memory == (void *)-1) { perror("shmat"); return 1; }
    int i = 0;
    do { memory[i] = message[i]; } while (message[i++] != '\0');
    if (shmdt(memory) == -1) { perror("shmdt"); return 1; }
    printf("Message written. Run the reader.\n");
    return 0;
}
