#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    long long count;
    int threads;
    int threadID;
} INFO;

typedef struct {
    long long numbers[11];
} OUTPUT;

void *generator(void *information) {
    INFO *info = (INFO *) information;

    long long current_count = (*info).count / info->threads;
    long long counter = 0;

    srand(time(NULL) + info->threadID);
    srand(rand());

    OUTPUT *out = malloc(sizeof(OUTPUT));

    for (size_t i = 0; i < sizeof(out->numbers) / sizeof(out->numbers[0]); i++)
        out->numbers[i] = 0;    

    for (size_t i = 0; i < current_count; i++)
    {
        int num = ((rand() % 6) + 1) + ((rand() % 6) + 1);
        out->numbers[num - 2]++;
        counter++;
    }

    pthread_exit(out);
}

int main(int argc, char** argv) {
    long long numbers[11] = {0};
    float percentage[11] = {0};

    INFO info;
    
    printf("DEBUG: argc: %d, argv: ", argc);
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s", argv[i]);
    }
    printf("\n");
    
    if (argc > 1) {
        if (!strcmp(argv[1], "-b")) {
            info.count = 10000000;
        } else if (!strcmp(argv[1], "-bc")) {
            if (!strcmp(argv[2], "0")) {
                printf("Sample size: ");
                scanf("%lli", &info.count);
            } else if (!strcmp(argv[2], "1"))
                info.count = 10000000;
            else if (!strcmp(argv[2], "2"))
                info.count = 1000000000;
            else if (!strcmp(argv[2], "3"))
                info.count = 10000000000;
            else
                return 1;
        } else
            return 1;
    } else {
        printf("Sample size: ");
        scanf("%lli", &info.count);
    }

    printf("Thread count: ");
    scanf("%d", &info.threads);

    pthread_t *tid = malloc(info.threads * sizeof(pthread_t));

    // random number calculation
    clock_t start_time = clock();

    for (size_t i = 0; i < info.threads; i++) {
        INFO *current_info;
        current_info = malloc(sizeof(INFO));
        (*current_info).count = info.count;
        (*current_info).threads = info.threads;
        (*current_info).threadID = i;
        pthread_create(&tid[i], NULL, generator, (void *) current_info);
    }

    for (size_t i = 0; i < info.threads; i++) {
        OUTPUT *out;

        pthread_join(tid[i], &out);
        
        for (size_t i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
            numbers[i] += out->numbers[i];        

        free(out);
    }

    clock_t end_time = clock();
    double time = (((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000);

    for (size_t i = 0; i < (sizeof(percentage) / sizeof(percentage[0])); i++) 
        percentage[i] = ((float)numbers[i] / (float)info.count) * 100;

    long long sum = 0;
    
    if (argc > 1) {
        long long score = info.count / time;
        sum = info.count;

        if (!strcmp(argv[1], "-bc")) {
            printf("You got a score of %lli in benchmark %s\n", score, argv[2]);
        } else if (!strcmp(argv[1], "-b")) {
            printf("You got a score of %lli in benchmark 1\n", score);
        }
    } else {
        for (size_t i = 0; i < (sizeof(numbers) / sizeof(numbers[0])); i++) {
            printf("%ld: %lli, %.2f%%\n", (i + 2), numbers[i], percentage[i]);
            sum += numbers[i];
        }
    }

    if (time > 60000)
        printf("\nThis took %.2f m with a sample size of %lli\n", (time / 60000), sum);
    else if (time > 1000)
        printf("\nThis took %.2f s with a sample size of %lli\n", (time / 1000), sum);
    else
        printf("\nThis took %.0f ms with a sample size of %lli\n", time, sum);

    return 0;
}