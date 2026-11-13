// Question: Implement LRU page replacement and count page faults.
#include <stdio.h>

int main(void)
{
    int pages[100], memory[20], n, frames, faults = 0;
    int last_used[20] = {0};
    printf("Enter number of pages (1 to 100): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;
    printf("Enter page numbers (0 or greater): ");
    for (int i = 0; i < n; i++)
        if (scanf("%d", &pages[i]) != 1 || pages[i] < 0) return 1;
    printf("Enter number of frames (1 to 20): ");
    if (scanf("%d", &frames) != 1 || frames < 1 || frames > 20) return 1;
    for (int j = 0; j < frames; j++) memory[j] = -1;
    for (int i = 0; i < n; i++)
    {
        int found = -1;
        for (int j = 0; j < frames; j++)
            if (memory[j] == pages[i]) found = j;
        if (found != -1) last_used[found] = i;
        if (found == -1)
        {
            int slot = 0;
            for (int j = 0; j < frames; j++)
            {
                if (memory[j] == -1) { slot = j; break; }
                if (last_used[j] < last_used[slot]) slot = j;
            }
            last_used[slot] = i;
            memory[slot] = pages[i];
            faults++;
        }
        printf("Page %d: ", pages[i]);
        for (int j = 0; j < frames; j++)
        {
            if (memory[j] == -1) printf("- ");
            else printf("%d ", memory[j]);
        }
        printf("%s\n", found == -1 ? "Fault" : "Hit");
    }
    printf("Total page faults = %d\n", faults);
    printf("Total page hits = %d\n", n - faults);
    return 0;
}
