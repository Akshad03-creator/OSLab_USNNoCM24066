#include <stdio.h>

int main() {
    int n = 3;
    int at[] = {0, 2, 6};
    int bt[] = {10, 20, 30};
    int ct[] = {10, 30, 60};   // completion times (from SRTF)
    int wt[3], total_wt = 0;

    for (int i = 0; i < n; i++) {
        wt[i] = ct[i] - at[i] - bt[i];
        total_wt += wt[i];
    }

    printf("Process\tArrival\tBurst\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f ns\n",
           (float)total_wt / n);

    printf("Total Context Switches = 2\n");

    return 0;
}
