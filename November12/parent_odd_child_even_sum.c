// Question: Use fork(). Parent finds the sum of odd numbers and child
// finds the sum of even numbers from 1 to n.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    int n;
    printf("Enter n (1 to 10000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 10000)
        return 1;
    fflush(stdout);
    pid_t pid = fork();
    if (pid == -1) { perror("fork"); return 1; }
    int sum = 0;
    if (pid == 0)
    {
        for (int i = 2; i <= n; i += 2) sum += i;
        printf("Child: Sum of even numbers = %d\n", sum);
    }
    else
    {
        for (int i = 1; i <= n; i += 2) sum += i;
        wait(NULL);
        printf("Parent: Sum of odd numbers = %d\n", sum);
    }
    return 0;
}
