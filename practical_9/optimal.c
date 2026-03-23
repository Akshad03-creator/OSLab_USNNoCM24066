#include <stdio.h>

int main() {
    int frames = 3;
    int ref[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = 12;

    int memory[3];
    int i, j, k, pos, max;
    int hits = 0, faults = 0;
    int found;

    // Initialize memory frames
    for(i = 0; i < frames; i++)
        memory[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in memory
        for(j = 0; j < frames; j++) {
            if(memory[j] == ref[i]) {
                hits++;
                found = 1;
                break;
            }
        }

        // If not found → Page Fault
        if(!found) {
            faults++;

            // Check for empty frame
            int empty = -1;
            for(j = 0; j < frames; j++) {
                if(memory[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if(empty != -1) {
                memory[empty] = ref[i];
            } else {
                // Find optimal page to replace
                max = -1;
                pos = -1;

                for(j = 0; j < frames; j++) {
                    int next = -1;

                    for(k = i + 1; k < n; k++) {
                        if(memory[j] == ref[k]) {
                            next = k;
                            break;
                        }
                    }

                    // If page not used again
                    if(next == -1) {
                        pos = j;
                        break;
                    }

                    if(next > max) {
                        max = next;
                        pos = j;
                    }
                }

                memory[pos] = ref[i];
            }
        }
    }

    printf("Total Page Hits = %d\n", hits);
    printf("Total Page Faults = %d\n", faults);

    float hit_ratio = (float)hits / n * 100;
    float fault_ratio = (float)faults / n * 100;

    printf("Hit Percentage = %.2f%%\n", hit_ratio);
    printf("Fault Percentage = %.2f%%\n", fault_ratio);

    return 0;
}
