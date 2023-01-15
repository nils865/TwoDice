#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    long count = 10000000;

    long numbers[11];
    float percentage[11];

    for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++)
        numbers[i] = 0;

    // random number calculation
    clock_t start_time = clock();

    for (size_t i = 0; i < count; i++)
    {
        int num = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        numbers[num - 2]++;
    }

    clock_t end_time = clock();
    double time = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;

    for (size_t i = 0; i < (sizeof(percentage) / sizeof(percentage[0])); i++) 
        percentage[i] = ((float)numbers[i] / (float)count) * 100;

    for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++)
        printf("%ld: %ld, %.2f%%\n", (i + 2), numbers[i], percentage[i]);

    printf("\nThis took %.0f ms with a sample size of %ld\n", time, count);
    
    return 0;
}