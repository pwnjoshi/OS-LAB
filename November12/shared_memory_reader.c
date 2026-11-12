// Question: Read a message from shared memory.
#include <stdio.h>
#include <sys/shm.h>

int main(void)
{
    int id = shmget(5678, 100, 0600);
    if (id == -1) { perror("shmget (run writer first)"); return 1; }
    const char *memory = shmat(id, NULL, SHM_RDONLY);
    if (memory == (void *)-1) { perror("shmat"); return 1; }
    printf("Received: %.100s", memory);
    if (shmdt(memory) == -1) { perror("shmdt"); return 1; }
    if (shmctl(id, IPC_RMID, NULL) == -1)
    { perror("shmctl"); return 1; }
    return 0;
}
