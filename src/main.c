#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// long count = 10000000;
long count = 1000000000;
int threads = 6;

typedef struct {
    long numbers[11];
} OUTPUT;

void *generator() {
    long current_count = count / threads;
    long counter = 0;

    OUTPUT *out = malloc(sizeof(OUTPUT));

    for (size_t i = 0; i < sizeof(out->numbers) / sizeof(out->numbers[0]); i++)
        out->numbers[i] = 0;    

    for (size_t i = 0; i < current_count; i++)
    {
        int num = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        out->numbers[num - 2]++;
        counter++;
    }

    printf("Current: 0: %d 1: %d\n", out->numbers[0], out->numbers[1]);

    pthread_exit(out);
}

int main() {
    long numbers[11] = {0};
    float percentage[11] = {0};

    srand(time(NULL));

    pthread_t *tid = malloc(threads * sizeof(pthread_t));

    // random number calculation
    clock_t start_time = clock();

    for (size_t i = 0; i < threads; i++)
        pthread_create(&tid[i], NULL, generator, NULL);

    for (size_t i = 0; i < threads; i++) {
        OUTPUT *out;

        pthread_join(tid[i], &out);
        
        for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
            numbers[i] += out->numbers[i];        

        free(out);
    }

    clock_t end_time = clock();
    double time = (((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);

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