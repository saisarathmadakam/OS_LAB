#include <stdio.h>
#include <stdlib.h>

void main() {
    int max[5][3], allocation[5][3], need[5][3], available[3], totalres[3], work[3], safe[5];
    char finish[5];
    int i, j, k, totalalloc, state, value = 0;
    
    printf("\n ENTER THE NUMBER OF INSTANCES (e.g., 3 resources): ");
    for(i = 0; i < 3; i++) {
        scanf("%d", &totalres[i]);
    }

    printf("\n ENTER THE MAXIMUM RESOURCES REQUIRED BY EACH PROCESS:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter maximum resource %d for process P%d: ", j + 1, i + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\n ENTER THE ALLOCATION OF RESOURCES FOR EACH PROCESS:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter allocated resource %d for process P%d: ", j + 1, i + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

    // Calculating the need matrix
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize finish array to 'f' (false)
    for(i = 0; i < 5; i++) {
        finish[i] = 'f';
    }

    // Calculate available resources
    for(i = 0; i < 3; i++) {
        totalalloc = 0;
        for(j = 0; j < 5; j++) {
            totalalloc += allocation[j][i];
        }
        available[i] = totalres[i] - totalalloc;
    }

    // Initial work array = available resources
    for(i = 0; i < 3; i++) {
        work[i] = available[i];
    }

    // Start the safety algorithm
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            if (finish[i] == 'f') {
                // Check if process can proceed
                if (need[i][j] <= work[j]) {
                    state = 1;  // Can proceed
                } else {
                    state = 0;  // Cannot proceed
                    break;
                }
            }
        }

        if (state == 1) {
            // Process can finish, release its resources
            for(j = 0; j < 3; j++) {
                work[j] += allocation[i][j];
            }
            finish[i] = 't';  // Mark process as finished
            safe[value] = i;  // Save the process ID in safe sequence
            value++;
        }

        // If no process was completed in this pass, system is in deadlock
        if (i == 4 && value < 5) {
            printf("\nSystem is in a deadlock state.\n");
            break;
        }
    }

    // Output the safe sequence
    printf("\nSafe sequence is: ");
    for(i = 0; i < value; i++) {
        printf("P%d ", safe[i] + 1);
    }
    printf("\n");
}
