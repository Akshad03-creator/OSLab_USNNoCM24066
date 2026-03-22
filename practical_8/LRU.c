#include <stdio.h>

int main() {
    int pages[] = {1,2,3,4,1,2,5,1,2,3,4,5};
    int n = 12;
    int frames[3], time[3];
    int i, j, k, pos, faults = 0, hits = 0;
    int counter = 0;

    // Initialize frames
    for(i = 0; i < 3; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check for hit
        for(j = 0; j < 3; j++) {
            if(frames[j] == pages[i]) {
                hits++;
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        // If not found → page fault
        if(!found) {
            pos = 0;

            // Find least recently used
            for(j = 1; j < 3; j++) {
                if(time[j] < time[pos]) {
                    pos = j;
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    printf("Total Page Hits = %d\n", hits);

    printf("Page Fault Percentage = %.2f%%\n", (float)faults/n*100);
    printf("Page Hit Percentage = %.2f%%\n", (float)hits/n*100);

    return 0;
}
