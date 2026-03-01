#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int phil = *(int*)num;

    printf("Philosopher %d is thinking\n", phil);
    sleep(1);

    // Pick left chopstick
    pthread_mutex_lock(&chopstick[phil]);
    printf("Philosopher %d picked left chopstick\n", phil);

    // Pick right chopstick
    pthread_mutex_lock(&chopstick[(phil + 1) % N]);
    printf("Philosopher %d picked right chopstick\n", phil);

    printf("Philosopher %d is eating\n", phil);
    sleep(2);

    // Release chopsticks
    pthread_mutex_unlock(&chopstick[phil]);
    pthread_mutex_unlock(&chopstick[(phil + 1) % N]);

    printf("Philosopher %d finished eating\n", phil);

    return NULL;
}

int main() {
    pthread_t thread[N];
    int phil_num[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    for (int i = 0; i < N; i++) {
        phil_num[i] = i;
        pthread_create(&thread[i], NULL, philosopher, &phil_num[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(thread[i], NULL);

    return 0;
}
