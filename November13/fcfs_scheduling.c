// Question: Implement FCFS CPU scheduling.
// Enter arrival time and burst time for each process. Ties use input order.
#include <stdio.h>

int main(void)
{
    int n, arrival[20], burst[20], done[20] = {0};
    int time = 0;
    double total_wait = 0, total_turn = 0;
    printf("Enter number of processes (1 to 20): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) return 1;
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival and burst time for P%d: ", i + 1);
        if (scanf("%d%d", &arrival[i], &burst[i]) != 2 ||
            arrival[i] < 0 || arrival[i] > 100000 ||
            burst[i] < 1 || burst[i] > 100000) return 1;
    }
    printf("Process  Arrival  Burst  Completion  Waiting  Turnaround\n");
    for (int completed = 0; completed < n; completed++)
    {
        int next = -1;
        for (int i = 0; i < n; i++)
            if (!done[i] && arrival[i] <= time)
                if (next == -1 || arrival[i] < arrival[next]) next = i;
        // If CPU is idle, jump to the earliest unfinished arrival.
        if (next == -1)
        {
            for (int i = 0; i < n; i++)
                if (!done[i] && (next == -1 || arrival[i] < arrival[next]))
                    next = i;
            time = arrival[next];
            completed--;
            continue;
        }
        int waiting = time - arrival[next];
        time += burst[next];
        int turnaround = time - arrival[next];
        done[next] = 1;
        total_wait += waiting;
        total_turn += turnaround;
        printf("P%d       %d        %d      %d           %d        %d\n",
               next + 1, arrival[next], burst[next], time, waiting, turnaround);
    }
    printf("Average waiting time = %.2f\n", total_wait / n);
    printf("Average turnaround time = %.2f\n", total_turn / n);
    return 0;
}
