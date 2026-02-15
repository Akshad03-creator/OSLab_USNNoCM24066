#include <stdio.h>
#include <unistd.h>

int main() {
    int i;

    for (i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            printf("Child %d | PID = %d | PPID = %d\n",
                   i, getpid(), getppid());
            break;   // IMPORTANT: child exits loop
        }
        else {
            // Parent process
            printf("Parent created Child %d | Child PID = %d\n",
                   i, pid);
        }
    }

    return 0;
}









