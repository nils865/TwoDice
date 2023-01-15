#include <stdio.h>
#include <stdlib.h>

int main() {
    long count = 10000000;

    long numbers[11];
    float percentage[11];

    for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++)
        numbers[i] = 0;

    for (size_t i = 0; i < count; i++)
    {
        int num = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        numbers[num - 2]++;
    }

    for (size_t i = 0; i < (sizeof(percentage) / sizeof(percentage[0])); i++) 
        percentage[i] = ((float)numbers[i] / (float)count) * 100;

    for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++)
        printf("%ld: %ld, %f %\n", (i + 2), numbers[i], percentage[i]);
    
    return 0;
}