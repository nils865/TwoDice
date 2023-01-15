#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// long count = 10000000;
long count = 100000000;
int threads = 5;
long numbers[11] = {0};

void *generator() {
    long current_count = count / threads;

    for (size_t i = 0; i < current_count; i++)
    {
        int num = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        numbers[num - 2]++;
    }
}

int main() {
    float percentage[11] = {0};

    srand(time(NULL));

    pthread_t *tid = malloc(threads * sizeof(pthread_t));

    // random number calculation
    clock_t start_time = clock();

    for (size_t i = 0; i < threads; i++)
        pthread_create(&tid[i], NULL, generator, NULL);

    for (size_t i = 0; i < threads; i++)
        pthread_join(tid[i], NULL);

    clock_t end_time = clock();
    double time = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;

    for (size_t i = 0; i < (sizeof(percentage) / sizeof(percentage[0])); i++) 
        percentage[i] = ((float)numbers[i] / (float)count) * 100;

    for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++)
        printf("%ld: %ld, %.2f%%\n", (i + 2), numbers[i], percentage[i]);

    if (time > 60000)
        printf("\nThis took %.2f m with a sample size of %ld\n", (time / 60000), count);
    else if (time > 1000)
        printf("\nThis took %.2f s with a sample size of %ld\n", (time / 1000), count);
    else
        printf("\nThis took %.0f ms with a sample size of %ld\n", time, count);
    
    return 0;
}